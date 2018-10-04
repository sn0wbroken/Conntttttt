#include"Main_Scene.h"
#include"Game_Manager.h"

// �R���X�g���N�^
Main_Scene::Main_Scene() {
	UI_class = std::make_shared<UI>();

	player = player_manager->player;
	player_action = player_manager->player_action;

	collision = std::make_shared<Collision>();

	Initialize();

	y1 = 0;
	y2 = -define_value.MAX_WINDOW_Y;

	// ���C���ɓ��������̓C���^�[�o���Ƃ���
	is_interval = true;
}

// ���t���[������
void Main_Scene::Update() {
	// �G���^�[�������܂ŃQ�[�����i�܂Ȃ�
	if (is_interval) {
		if (key_checker->key[KEY_INPUT_RETURN] == 1) {
			is_interval = false;
		}
		return;
	}

	player_action->Player_Controll();
	player_manager->Update();
	std::unique_ptr<Game_Manager> &game_manager = Game_Manager::Get_Instance();

	// �G�l�~�[�̃A�b�v�f�[�g����
	enemy_manager->Update();

	// �G�l�~�[�̟r�łŃN���A
	if (Is_Enemy_All_Ded()) {
		// �ŏI�X�e�[�W�łȂ���Ύ��̃X�e�[�W��
		if (!(static_cast<int>(game_manager->Get_Stage()) == define_value.FINAL_STAGE)) {
			game_manager->Next_Stage();
			is_interval = true;
			Initialize();
			player->Set_Power_Up(true);
			return;
		}
		// �ŏI�X�e�[�W�N���A�Ń��U���g
		game_manager->Reset_Stage();
		game_manager->Change_Scene(Game_Manager::Clear);
		return;
	}
	
	// �G�̒e�ɓ���������c�@�����炷
	if (Is_Enemy_Attack_Hit()) {
		// �c�@�����炷
		player_manager->player_status->Dead();
		
		// �c�@�����ŃQ�[���I�[�o�[
		if (!(player_manager->player_status->Get_Life() <= 0)) {
			Player_Dead();
		}
		else {
			player_manager->player_status->Reset_Life();
			game_manager->Reset_Stage();
			game_manager->Change_Scene(Game_Manager::Game_Over);
		}
		return;
	}

	// �G�l�~�[�ɓ���������c�@�����炷
	if (Is_Hit_Actor_Fellow()) {
		// �c�@�����炷
		player_manager->player_status->Dead();

		// �c�@�����ŃQ�[���I�[�o�[
		if (!(player_manager->player_status->Get_Life() <= 0)) {
			Player_Dead();
		}
		else {
			player_manager->player_status->Reset_Life();
			game_manager->Reset_Stage();
			game_manager->Change_Scene(Game_Manager::Game_Over);
		}
	}
	
	// �v���C���[�̌��e���G�l�~�[�ɓ���������_���[�W��^����
	Is_Player_Attack_Hit();
}

// ���C���V�[���ɕK�v�Ȃ��̂�`��
void Main_Scene::Render() {
	// �w�i�̕`��
	DrawExtendGraph(0, y1,
					define_value.WINDOW_X - define_value.UI_SPACE, y1 + define_value.WINDOW_Y,
					background_graph, TRUE);
	DrawExtendGraph(0, y2,
		define_value.WINDOW_X - define_value.UI_SPACE, y2 + define_value.WINDOW_Y,
		background_graph, TRUE);

	// �A�N�^�[�̕`��
	player->Render();
	enemy_manager->Render();

	// UI�̕`��
	UI_class->Render();

	// �C���^�[�o�����͔w�i�̃X�N���[������
	if (is_interval) {
		// �A�i�E���X��\��
		DrawString(300, 200, "Ready?", GetColor(0, 0, 0));
		DrawString(285, 400, "Push Enter", GetColor(0, 0, 0));
		return;
	}
	// �w�i�̃X�N���[��
	Scroll();
}

// ������
void Main_Scene::Initialize() {
	// �v���C���[�̏�����
	player->Initialize();
	player_action->Initialize();
	
	// �G�l�~�[�̏�����
	enemy_manager->Initialize();
}

// �w�i�̉摜�𓮂���
void Main_Scene::Scroll() {
	++y1;
	++y2;

	// ��ʂ��犮�S�ɏo�؂����^�C�~���O�ł���1���̔w�i�̏��
	if (y1 >= define_value.MAX_WINDOW_Y) {
		y1 = -define_value.MAX_WINDOW_Y;
	}
	if (y2 >= define_value.MAX_WINDOW_Y) {
		y2 = -define_value.MAX_WINDOW_Y;
	}
}

// �G�l�~�[���S�ł������ǂ��� �S�ł�����true
bool Main_Scene::Is_Enemy_All_Ded() {
	return enemy_manager->enemies.size() == 0;
}

// �v���C���[�ƃG�l�~�[���Փ˂������ǂ��� �Փ˂�����true
bool Main_Scene::Is_Hit_Actor_Fellow() {
	for (auto& enemy : enemy_manager->enemies) {
		if (collision->Box_To_Box(player->Get_Right_Edge(), player->Get_Left_Edge(), player->Get_Top_Edge(),
			enemy.Get_Right_Edge(), enemy.Get_Left_Edge(), enemy.Get_Bottom_Edge())) {
			return true;
		}
	}
	return false;
}

// �v���C���[���G�l�~�[�̍U�����󂯂����ǂ��� �U�����󂯂���true
bool Main_Scene::Is_Enemy_Attack_Hit() {
	for (int i = 0; i < enemy_manager->enemies.size(); ++i) {
		for (auto& enemy_bullet : enemy_manager->enemy_bullet) {
			if (collision->Player_To_Enemy_Bullet(player->Get_Right_Edge(), player->Get_Left_Edge(), player->Get_Top_Edge(), player->Get_Bottom_Edge(),
				enemy_bullet.Get_X(), enemy_bullet.Get_Y(), enemy_bullet.Get_Radius()))
				return true;
		}
	}
	return false;
}

// �v���C���[�̍U�����G�l�~�[�ɖ���������
void Main_Scene::Is_Player_Attack_Hit() {
	for (unsigned int i = 0; i < player->player_bullet.size(); ++i) {
		auto& player_bullet = player->player_bullet[i];

		for (unsigned int j = 0; j < enemy_manager->enemies.size(); ++j) {
			auto& enemy = enemy_manager->enemies[j];

			if (collision->Enemy_To_Player_Bullet(enemy.Get_Right_Edge(), enemy.Get_Left_Edge(), enemy.Get_Top_Edge(), enemy.Get_Bottom_Edge(),
				player_bullet.Get_X(), player_bullet.Get_Y(), player_bullet.Get_Radius())) {
				// �_���[�W��^����
				enemy.enemy_status->Damage();
				// ����������e��������
				player->player_bullet.erase(player->player_bullet.begin() + i);

				// ����ł��������
				if (enemy.enemy_status->Is_Dead()) {
					enemy_manager->enemies.erase(enemy_manager->enemies.begin() + j);
				}
			}
		}
	}
}

// �v���C���[�����S�����Ƃ��̏���
void Main_Scene::Player_Dead() {
	is_interval = true;
	enemy_manager->Reset_Enemy();
	player->Initialize();
}
