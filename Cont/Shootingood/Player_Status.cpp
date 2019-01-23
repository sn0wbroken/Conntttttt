#include"Player_Status.h"

// �R���X�g���N�^
Player_Status::Player_Status() {
	attack = define_value.PLAYER_ATTACK;
	life = define_value.PLAYER_INITIALIZE_LIFE;
}

// �f�X�g���N�^
Player_Status::~Player_Status() {
}

// �G�ɓ���������Ă΂��B���C�t��1���炷
void Player_Status::Damage() {
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

// ����ł��邩��Ԃ�
bool Player_Status::Get_Is_Dead() {
	return life < 0;
}
