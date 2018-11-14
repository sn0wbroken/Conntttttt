#include"Player_Move.h"

// �R�X�g���N�^
Player_Move::Player_Move() {

}

// �R���X�g���N�^
Player_Move::Player_Move(std::shared_ptr<Player> set_player, std::shared_ptr<Player_Status> set_player_status) {
	player = set_player;
	player_status = set_player_status;
}

// �f�X�g���N�^
Player_Move::~Player_Move() {

}

// �v���C���[���ړ�������
void Player_Move::Move() {
	// ���������ł͓����Ȃ��悤��
	if (CheckHitKey(KEY_INPUT_RIGHT) && CheckHitKey(KEY_INPUT_LEFT)) {
		return;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		int player_x = player->Get_X();
		player->Set_X(player_x += player_status->Get_Speed());
	}
	else if (CheckHitKey(KEY_INPUT_LEFT)) {
		int player_x = player->Get_X();
		player->Set_X(player_x -= player_status->Get_Speed());
	}
}

// �L�[�̓��͂Ō�����ς���
void Player_Move::Rotation() {
	// ���������ł͓����Ȃ��悤��
	if (CheckHitKey(KEY_INPUT_RIGHT) && CheckHitKey(KEY_INPUT_LEFT)) {
		return;
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT)) {
		VECTOR player_rotation = MV1GetRotationXYZ(player->Get_Model_Handle());
		MV1SetRotationXYZ(player->Get_Model_Handle(), 
						  VGet(player_rotation.x, player_rotation.y, player_rotation.z - (define_value.PLAYER_ROTATE_SPEED * DX_PI_F / 180)));
	}
	else if (CheckHitKey(KEY_INPUT_LEFT)) {
		VECTOR player_rotation = MV1GetRotationXYZ(player->Get_Model_Handle());
		MV1SetRotationXYZ(player->Get_Model_Handle(), 
						  VGet(player_rotation.x, player_rotation.y, player_rotation.z + (define_value.PLAYER_ROTATE_SPEED * DX_PI_F / 180)));
	}
}
