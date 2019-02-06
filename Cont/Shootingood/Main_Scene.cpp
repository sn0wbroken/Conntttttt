#include"Main_Scene.h"
#include"Enemy_Manager.h"
#include"Scene_Manager.h"

// �R���X�g���N�^
Main_Scene::Main_Scene() {
	// �Q�[�����\������I�u�W�F�N�g�𐶐�����
	Object_Creater::Get_Instance();

	// �v���C���[�̃}�l�[�W���N���X
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	player = player_manager->player;
	player_action = player_manager->player_action;
	player_status = player_manager->player_status;
	player_weapon = player_manager->player_weapon;

	unique_ptr<Actor>& actor = Actor::Get_Instance();
	// �o��l���̏����������ׂčs��
	actor->Initialize();

	Initialize();
	
	UI_class = std::make_shared<UI>();
	
	x1 = 0;
	x2 = -define_value.MIN_SCREEN_X;

	// ���C���ɓ��������̓C���^�[�o���Ƃ���
	is_interval = true;

	ground_handle =  MV1LoadModel("Resources/BackGround/ground.x");
	MV1SetPosition(ground_handle,VGet(0.0f,0.0f,-700.0f));
	MV1SetScale(ground_handle, VGet(1000, 1, 1000));
	// �w�i���f���ǂݍ���
	background_model = MV1LoadModel("Resources/BackGround/background.dome.x");
	MV1SetScale(background_model, VGet(10,10,10));
	//X���J�����Ɠ����p�x�X����
	MV1SetRotationXYZ(background_model, VGet(45, 0, 0));

	// �w�i���f���̍��W��ݒ肷��
	Set_BackGround_Position();
}

Main_Scene::~Main_Scene()
{
	unique_ptr<Actor>& actor = Actor::Get_Instance();
	auto character = actor->children["Character"];
	auto player = actor->children["Player"];
	auto weapon = actor->children["Weapon"];
	auto player_weapon = weapon->children["Player_Weapon"];
	auto collision = actor->children["Collision"];
	actor->children.clear();
	actor->Add_Child("Charactor", character);
	actor->Add_Child("Player", player);
	actor->Add_Child("Weapon", weapon);
	weapon->Add_Child("Player_Weapon", player_weapon);
	actor->Add_Child("Collision", collision);
}

// ������
void Main_Scene::Initialize() {
	// �v���C���[�̏�����
	player->Initialize();
	player_action->Initialize();
	
	// �A�N�^�[���\������I�u�W�F�N�g�𐶐�����
	std::unique_ptr<Object_Creater>& object_creater = Object_Creater::Get_Instance();
	object_creater->Create_Enemy();
	object_creater->Play_Sound();

	player_weapon->Set_Ammo(enemy_manager->active_enemies.size());
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
	MV1SetWriteZBuffer(background_model, false);
	MV1SetWriteZBuffer(ground_handle, false);
	//�w�i�̃��C�e�B���O����邽�ߗ͋�
	SetUseLighting(false);
	MV1DrawModel(background_model);
	MV1DrawModel(ground_handle);

	SetUseLighting(true);
	// �I�u�W�F�N�g�̕`��
	unique_ptr<Actor>& actor = Actor::Get_Instance();
	actor->Render();
	std::unique_ptr<Enemy_Manager>& enemy_manager = Enemy_Manager::Get_Instance();
	enemy_manager->PlayEffect();
	// UI�̕`��
	UI_class->Render();

	// �C���^�[�o�����̓A�i�E���X��\��
	if (is_interval) {
		UI_class->Interval_Announce();
		return;
	}
}

// �v���C���[�����S�����Ƃ��̏���
void Main_Scene::Player_Dead() {
	is_interval = true;
	player->Initialize();
}

// �w�i���f���̍��W��ݒ肷��
void Main_Scene::Set_BackGround_Position() {
	VECTOR vector;
	vector.x = define_value.CAMERA_POSITION_X;
	vector.y = -50;
	vector.z = define_value.CAMERA_POSITION_Z;

	MV1SetPosition(background_model, vector);
}
