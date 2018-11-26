#include"Main_Scene.h"
<<<<<<< HEAD
#include"Game_Manager.h"
#include "MazeGenerator.h"
=======
#include"Scene_Manager.h"
>>>>>>> origin/ishikuraBranch

// �R���X�g���N�^
Main_Scene::Main_Scene() {
	// �v���C���[�̃}�l�[�W���N���X
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	player = player_manager->player;
	player_action = player_manager->player_action;
	player_status = player_manager->player_status;

	collision = std::make_shared<Collision>();

	Initialize();

	UI_class = std::make_shared<UI>();
	
	y1 = 0;
	y2 = -define_value.MAX_WINDOW_Y;

	// ���C���ɓ��������̓C���^�[�o���Ƃ���
	is_interval = true;
}

// ������
void Main_Scene::Initialize() {
	// �v���C���[�̏�����
	player->Initialize();
	player_action->Initialize();
}

// ���t���[������
void Main_Scene::Update() {
	std::unique_ptr<Key_Checker>& key_checker = Key_Checker::Get_Instance();
	std::unique_ptr<Scene_Manager> &scene_manager = Scene_Manager::Get_Instance();

	// �G���^�[�������܂ŃQ�[�����i�܂Ȃ�
	if (is_interval) {
		if (key_checker->key[KEY_INPUT_RETURN] == 1) {
			is_interval = false;
		}
		return;
	}

	player_action->Update();
	std::unique_ptr<TEST_GOD> &god = TEST_GOD::Get_Instance();
	god->actor->Update();

	// �G�l�~�[�̃A�b�v�f�[�g����
	enemy_manager->Update();

	// �G�l�~�[�̟r�łŃN���A
	if (enemy_manager->Is_Enemy_All_Ded()) {
		// �ŏI�X�e�[�W�łȂ���Ύ��̃X�e�[�W��
		if (!(static_cast<int>(scene_manager->Get_Stage()) == define_value.FINAL_STAGE)) {
			scene_manager->Next_Stage();
			is_interval = true;
			Initialize();
			player->Set_Power_Up(true);
			return;
		}
		// �ŏI�X�e�[�W�N���A�Ń��U���g
		scene_manager->Reset_Stage();
		scene_manager->Change_Scene(Scene_Manager::Clear);
		return;
	}

	// �v���C���[�����񂾂�Q�[���I�[�o�[
	if (player_status->Get_Is_Dead()) {
		player_status->Reset_Life();
		scene_manager->Reset_Stage();
		scene_manager->Change_Scene(Scene_Manager::Game_Over);
	}
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

	// UI�̕`��
	UI_class->Render();
	// �I�u�W�F�N�g�̕`��
	auto &god = TEST_GOD::Get_Instance();
	god->actor->Render();
	
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

// �w�i�̉摜�𓮂���
void Main_Scene::Scroll() {
	++y1;
	++y2;

	// ��ʂ��犮�S�ɏo�؂����^�C�~���O�ł���1���̔w�i�̏�ɓ�����
	if (y1 >= define_value.MAX_WINDOW_Y) {
		y1 = -define_value.MAX_WINDOW_Y;
	}
	if (y2 >= define_value.MAX_WINDOW_Y) {
		y2 = -define_value.MAX_WINDOW_Y;
	}
}

// �v���C���[�����S�����Ƃ��̏���
void Main_Scene::Player_Dead() {
	is_interval = true;
	player->Initialize();
}
