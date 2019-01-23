#include"Main_Scene.h"
#include"Enemy_Manager.h"
#include"Scene_Manager.h"

// �R���X�g���N�^
Main_Scene::Main_Scene() {
	// �Q�[�����\������I�u�W�F�N�g�𐶐�����
	std::unique_ptr<Object_Creater>& object_creater = Object_Creater::Get_Instance();

	// �v���C���[�̃}�l�[�W���N���X
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	player = player_manager->player;
	player_action = player_manager->player_action;
	player_status = player_manager->player_status;

	unique_ptr<Actor>& actor = Actor::Get_Instance();
	// �o��l���̏����������ׂčs��
	actor->Initialize();

	collision = std::make_shared<Collision>();

	Initialize();
	
	UI_class = std::make_shared<UI>();
	
	x1 = 0;
	x2 = -define_value.MIN_SCREEN_X;

	// ���C���ɓ��������̓C���^�[�o���Ƃ���
	is_interval = true;
}

// ������
void Main_Scene::Initialize() {
	// �v���C���[�̏�����
	player->Initialize();
	player_action->Initialize();

	// �A�N�^�[���\������I�u�W�F�N�g�𐶐�����
	std::unique_ptr<Object_Creater>& object_creater = Object_Creater::Get_Instance();
	object_creater->Create_Enemy();
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
	unique_ptr<Actor>& actor = Actor::Get_Instance();
	actor->Update();

	// �G�l�~�[�̃A�b�v�f�[�g����
	enemy_manager->Update();

	// �G�l�~�[�̟r�łŃN���A
	if (enemy_manager->Is_Enemy_All_Dead()) {
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
	// UI�̕`��
	UI_class->Render();
	// �I�u�W�F�N�g�̕`��
	unique_ptr<Actor>& actor = Actor::Get_Instance();
	actor->Render();
	
	// �C���^�[�o�����͔w�i�̃X�N���[������
	if (is_interval) {
		// �A�i�E���X��\��
		DrawString(300, 200, "Ready?", GetColor(0, 0, 0));
		DrawString(285, 400, "Push Enter", GetColor(0, 0, 0));
		return;
	}
}

// �v���C���[�����S�����Ƃ��̏���
void Main_Scene::Player_Dead() {
	is_interval = true;
	player->Initialize();
}
