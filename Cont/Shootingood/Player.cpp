#include "Player.h"

// �R���X�g���N�^
Player::Player() {
	// �v���C���[�̕�
	width = define_value.PLAYER_WIDTH;
	// �v���C���[�̍���
	height = define_value.PLAYER_HEIGHT;

	// ������
	Initialize();

	rectangle = Rect<float>(vector3.x, vector3.y);

	//TODO:���e������
	// �v���C���[�̃��f���n���h�����i�[
	model_handle = MV1LoadModel("Resources/Player/Player.x");
	// �v���C���[�̍��W���w��
	MV1SetPosition(model_handle, VGet(vector3.x, vector3.y, 0.0f));
	// �v���C���[�̑傫�����w��
	MV1SetScale(model_handle, VGet(40.0f, 40.0f, 35.0f));
	// �v���C���[�̕\���p�x�𒲐�
	MV1SetRotationXYZ(model_handle, VGet(270 * (DX_PI_F / 180), 0.0f, 180 * (DX_PI_F / 180)));
}

// �f�X�g���N�^
Player::~Player() {}

// ������
void Player::Initialize() {
	vector3.Arrange((define_value.WINDOW_X - define_value.UI_SPACE) / 2, define_value.WINDOW_Y / 2, 0);
	// ������Ԃ����ɖ߂�
	is_power_up = false;

	player_bullet.clear();
}

// �v���C���[�ƁA�v���C���[���������e��`��
void Player::Render() {
	MV1DrawModel(model_handle);
	auto hoge = MV1GetRotationXYZ(model_handle);

	// �������e�����`��
	for (auto& player_bullet_ : player_bullet) {
		player_bullet_.Render();
	}
}

// �v���C���[�̉E�[�̍��W��Ԃ�
float Player::Get_Right_Edge() {
	return vector3.x + width;
}

// �v���C���[�̍��[�̍��W��Ԃ�
float Player::Get_Left_Edge() {
	return vector3.x;
}

// �v���C���[�̏�[�̍��W��Ԃ�
float Player::Get_Top_Edge() {
	return vector3.y;
}

// �v���C���[�̉��[�̍��W��Ԃ�
float Player::Get_Bottom_Edge() {
	return vector3.y + height;;
}

// �e���o��ʒu��Ԃ�
float Player::Get_Shoot_Point() {
	return  vector3.x + (width / 2);
}

// �p���[�A�b�v��Ԃł��邩���Z�b�g����
void Player::Set_Power_Up(bool set_is_power_up) {
	is_power_up = set_is_power_up;
}

// �p���[�A�b�v��Ԃł��邩��Ԃ�
bool Player::Get_Power_Up() {
	return is_power_up;
}
