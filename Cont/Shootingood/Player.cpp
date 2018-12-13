#include "Player.h"

// �R���X�g���N�^
Player::Player() {
	// �v���C���[�̕�
	width = define_value.PLAYER_WIDTH;
	// �v���C���[�̍���
	height = define_value.PLAYER_HEIGHT;

	// ������
	Initialize();

	// ���f�����擾
	Create_Actor("Resources/Player/Player.x");
	// �v���C���[�̍��W���w�� 
	MV1SetPosition(model_handle, VGet(vector3d.x, vector3d.y, 0.0f));
	// �v���C���[�̕\���p�x�𒲐�
	MV1SetRotationXYZ(model_handle, VGet(0,0,0));
}

// �f�X�g���N�^
Player::~Player() {}

// ������
void Player::Initialize() {
	// UI�̕\���敪���炷(�Q�[����ʂ̒��S)
	vector3d.Arrange(/*-define_value.UI_SPACE / 2*/0, 0, 0);
	is_power_up = false;

	is_dead = false;
}

// �p���[�A�b�v��Ԃł��邩���Z�b�g����
void Player::Set_Power_Up(bool set_is_power_up) {
	is_power_up = set_is_power_up;
}

// �p���[�A�b�v��Ԃł��邩��Ԃ�
bool Player::Get_Power_Up() {
	return is_power_up;
}
