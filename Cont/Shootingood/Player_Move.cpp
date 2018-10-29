#include "Player_Move.h"

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

//TEST
VECTOR Player_Move::Rotation(VECTOR vector) {
	MATRIX rot_x = MGetRotX(M_PI / 4.0f);

	auto rad = static_cast<float>(M_PI / 360.0f);

	VECTOR vec = VTransform(vector, rot_x);

	return vec;
}
