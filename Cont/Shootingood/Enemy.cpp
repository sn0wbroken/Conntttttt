#include"Enemy.h"
#include"Scene_Manager.h"

// �R���X�g���N�^
Enemy::Enemy() {}

// �R�s�[�R���X�g���N�^
Enemy::Enemy(float set_x, float set_y) {
	// �v���C����X�e�[�W���擾
	std::unique_ptr<Scene_Manager>& scene_manager = Scene_Manager::Get_Instance();

	// �z�u
	vector3d.Arrange(set_x, set_y, 0);

	// �G�l�~�[�̕�
	width = define_value.ENEMY_WIDTH;
	// �G�l�~�[�̍���
	height = define_value.ENEMY_HEIGHT;

	// �X�e�[�^�X���Z�b�g
	enemy_status = std::make_shared<Enemy_Status>(scene_manager->Get_Stage());

	// TODO:�摜�̗p�ӂ��܂��Ȃ̂�
	Create_Actor("Resources/Player/Bullet.x");
	MV1SetPosition(model_handle, VGet(vector3d.x, vector3d.y, vector3d.z));
	// �G�l�~�[�̑傫�����w��
	MV1SetScale(model_handle, VGet(40.0f, 40.0f, 35.0f));
	// �G�l�~�[�̕\���p�x�𒲐�
	//MV1SetRotationXYZ(model_handle, VGet(270 * (DX_PI_F / 180), 0.0f, 180 * (DX_PI_F / 180)));
}

// �f�X�g���N�^
Enemy::~Enemy() {}