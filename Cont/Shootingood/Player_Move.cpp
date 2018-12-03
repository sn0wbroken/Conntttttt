#include"Player_Move.h"
#include"Player_Manager.h"

// コストラクタ
Player_Move::Player_Move() {

}

// デストラクタ
Player_Move::~Player_Move() {

}

// プレイヤーを移動させる
void Player_Move::Move() {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	auto player = player_manager->player;
	auto player_status = player_manager->player_status;

	// 同時押しでは動かないように
	if (CheckHitKey(KEY_INPUT_RIGHT) && CheckHitKey(KEY_INPUT_LEFT)) {
		return;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		float player_x = player->Get_X();
		player->Set_X(player_x += player_status->Get_Speed());
	}
	else if (CheckHitKey(KEY_INPUT_LEFT)) {
		float player_x = player->Get_X();
		player->Set_X(player_x -= player_status->Get_Speed());
	}
}

// キーの入力で向きを変える
void Player_Move::Rotation() {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	auto player = player_manager->player;
	auto player_status = player_manager->player_status;

	// 同時押しでは動かないように
	if (CheckHitKey(KEY_INPUT_RIGHT) && CheckHitKey(KEY_INPUT_LEFT)) {
		return;
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT)) {
		VECTOR player_rotation = MV1GetRotationXYZ(player->Get_Model_Handle());
		MV1SetRotationXYZ(player->Get_Model_Handle(),
						  VGet(player_rotation.x, player_rotation.y, player_rotation.z - define_value.ROTATION_VALUE));
	}
	else if (CheckHitKey(KEY_INPUT_LEFT)) {
		VECTOR player_rotation = MV1GetRotationXYZ(player->Get_Model_Handle());
		MV1SetRotationXYZ(player->Get_Model_Handle(), 
						  VGet(player_rotation.x, player_rotation.y, player_rotation.z + define_value.ROTATION_VALUE));
	}
}
