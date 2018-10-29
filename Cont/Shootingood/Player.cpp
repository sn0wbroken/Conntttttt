#include "Player.h"

// �R���X�g���N�^
Player::Player() {
	// �v���C���[�̕�
	width = define_value.PLAYER_WIDTH;
	// �v���C���[�̍���
	height = define_value.PLAYER_HEIGHT;

	// �����ʒu�͉�ʂ̒���
	vector3.Arrange((define_value.WINDOW_X - define_value.UI_SPACE) / 2,
	define_value.WINDOW_Y - (height + (height / 2)), 0);

	rectangle = Rect<float>(vector3.x, vector3.y);

	//TEST------------------------------------
	// �������W��ݒ�
	matrix[0] = VGet(250.0f, 250.0f, 0.0f);
	matrix[1] = VGet(225.0f, 200.0f, 0.0f);
	matrix[2] = VGet(275.0f, 200.0f, 0.0f);
	auto wdith  = matrix[2].x - matrix[1].x;
	auto height = matrix[1].y - matrix[0].y;
	// �d�S(�O�p�`�̒��S)
	center = VGet(matrix[1].x + (width / 2), matrix[0].y + (height / 2), 0.0f);
	//----------------------------------------

	// �v���C���[�̉摜�����[�h
	player_graph = LoadGraph("Picture/Player/Player.png");
}

// �f�X�g���N�^
Player::~Player() {}

// ������
void Player::Initialize() {
	vector3.x = (define_value.WINDOW_X - define_value.UI_SPACE) / 2;
	vector3.y = define_value.WINDOW_Y - (height + (height / 2));
	// ������Ԃ����ɖ߂�
	is_power_up = false;

	player_bullet.clear();
}

// �v���C���[�A�v���C���[���������e��`��
void Player::Render() {
	// ������`��
	DrawExtendGraph(vector3.x, vector3.y, Get_Right_Edge(), Get_Bottom_Edge(), player_graph, TRUE);

	//TEST--------------------------------------------------
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		auto hoge = -64.0f;
		MATRIX rot_x = MGetRotZ(M_PI / hoge);
		auto t_ = MMult(MGetTranslate(VScale(center, -1.0f)), MMult(rot_x, MGetTranslate(center)));

		matrix[0] = VTransform(matrix[0], t_);
		matrix[1] = VTransform(matrix[1], t_);
		matrix[2] = VTransform(matrix[2], t_);
	}

	DrawTriangle3D(matrix[0],
		matrix[1],
		matrix[2], GetColor(0, 255, 0), TRUE);
	//------------------------------------------------------

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