#include"Player_Move.h"

// コストラクタ
Player_Move::Player_Move() {

}

// コンストラクタ
Player_Move::Player_Move(std::shared_ptr<Player> set_player, std::shared_ptr<Player_Status> set_player_status) {
	player = set_player;
	player_status = set_player_status;
}

// デストラクタ
Player_Move::~Player_Move() {

}

// プレイヤーを移動させる
void Player_Move::Move() {
	// 同時押しでは動かないように
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

// キーの入力で向きを変える
void Player_Move::Rotation() {
	// 同時押しでは動かないように
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
