#include"Player_Status.h"

#include"Game_Manager.h"

// �R���X�g���N�^
Player_Status::Player_Status() {
	player = std::make_shared<Player>();

	speed = define_value.PLAYER_SPEED;
	attack = define_value.PLAYER_ATTACK;
	life = define_value.PLAYER_INITIALIZE_LIFE;
}

// �f�X�g���N�^
Player_Status::~Player_Status() {

}

// ���񂾂�Ă΂��B�c�@��1���炷
void Player_Status::Dead() {
	--life;
}

// �c�@�����Z�b�g����
void Player_Status::Reset_Life() {
	life = define_value.PLAYER_INITIALIZE_LIFE;
}

// �c�@��Ԃ�
int Player_Status::Get_Life() {
	return life;
}

// speed��Ԃ�
int Player_Status::Get_Speed() {
	return speed;
}
