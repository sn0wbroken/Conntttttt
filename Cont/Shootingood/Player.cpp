#include "Player.h"

// �R���X�g���N�^
Player::Player() {
	vector3 = new Vector3D;

	// �v���C���[�̕�
	width = define_value.PLAYER_WIDTH;
	// �v���C���[�̍���
	height = define_value.PLAYER_HEIGHT;	

	// �����ʒu�͉�ʂ̒���
	vector3->Arrange((define_value.WINDOW_X - define_value.UI_SPACE) / 2,
					 define_value.WINDOW_Y - (height + (height / 2)), 0);

	rectangle =  new Rect<float>(vector3->x, vector3->y);
	
	// �v���C���[�̉摜�����[�h
	player_graph = LoadGraph("Picture/Player/Player.png");
}

// �f�X�g���N�^
Player::~Player() {}

// ������
void Player::Initialize() {
	vector3->x = (define_value.WINDOW_X - define_value.UI_SPACE) / 2;
	vector3->y = define_value.WINDOW_Y - (height + (height / 2));
	// ������Ԃ����ɖ߂�
	is_power_up = false;

	player_bullet.clear();
}

// �v���C���[�A�v���C���[���������e��`��
void Player::Render() {
	// ������`��
	DrawExtendGraph(vector3->x, vector3->y, Get_Right_Edge(), Get_Bottom_Edge(), player_graph, TRUE);

	// �������e�����`��
	for (auto& player_bullet_ : player_bullet) {
		player_bullet_.Render();
	}
}

// �v���C���[�̉E�[�̍��W��Ԃ�
int Player::Get_Right_Edge() {
	return vector3->x + width;
}

// �v���C���[�̍��[�̍��W��Ԃ�
int Player::Get_Left_Edge() {
	return vector3->x;
}

// �v���C���[�̏�[�̍��W��Ԃ�
int Player::Get_Top_Edge() {
	return vector3->y;
}

// �v���C���[�̉��[�̍��W��Ԃ�
int Player::Get_Bottom_Edge() {
	return vector3->y + height;;
}

// �e���o��ʒu��Ԃ�
int Player::Get_Shoot_Point() {
	return  vector3->x + (width / 2);
}

// �p���[�A�b�v��Ԃł��邩���Z�b�g����
void Player::Set_Power_Up(bool set_is_power_up) {
	is_power_up = set_is_power_up;
}

// �p���[�A�b�v��Ԃł��邩��Ԃ�
bool Player::Get_Power_Up() {
	return is_power_up;
}
