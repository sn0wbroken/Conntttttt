#include"Enemy.h"
#include"Scene_Manager.h"

// �R���X�g���N�^
Enemy::Enemy() {}

// �R�s�[�R���X�g���N�^
Enemy::Enemy(float set_x, float set_y) {
	// �v���C����X�e�[�W���擾
	std::unique_ptr<Scene_Manager>& scene_manager = Scene_Manager::Get_Instance();

	// �z�u
	vector3.Arrange(set_x, set_y, 0);

	initialize_position_x = set_x;
	initialize_position_y = set_y;

	// �G�l�~�[�̕�
	width = define_value.ENEMY_WIDTH;
	// �G�l�~�[�̍���
	height = define_value.ENEMY_HEIGHT;

	// �X�e�[�^�X���Z�b�g
	enemy_status = std::make_shared<Enemy_Status>(scene_manager->Get_Stage());

	// TODO:�摜�̗p�ӂ��܂��Ȃ̂�
	Create_Actor("Resources/Enemy/Enemy.x");
	// �G�l�~�[�̑傫�����w��
	MV1SetScale(model_handle, VGet(40.0f, 40.0f, 35.0f));
	// �G�l�~�[�̕\���p�x�𒲐�
	//MV1SetRotationXYZ(model_handle, VGet(270 * (DX_PI_F / 180), 0.0f, 180 * (DX_PI_F / 180)));
}

// �f�X�g���N�^
Enemy::~Enemy() {}

// �G�l�~�[�̉E�[�̍��W��Ԃ�
float Enemy::Get_Right_Edge() {
	return vector3.x + width;
}

// �G�l�~�[�̍��[�̍��W��Ԃ�
float Enemy::Get_Left_Edge() {
	return vector3.x;
}

// �G�l�~�[�̏�[�̍��W��Ԃ�
float Enemy::Get_Top_Edge() {
	return vector3.y;
}

// �G�l�~�[�̉��[�̍��W��Ԃ�
float Enemy::Get_Bottom_Edge() {
	return vector3.y + height;
}

// �e�̔��˂���ʒu��Ԃ�
float Enemy::Get_Shot_Point() {
	return vector3.x + (width / 2);
}

// ����x���W��Ԃ�
float Enemy::Get_Initialize_Position_X() {
	return initialize_position_x;
}

// ����y���W��Ԃ�
float Enemy::Get_Initialize_Position_Y() {
	return initialize_position_y;
}