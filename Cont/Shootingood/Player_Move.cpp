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
}

// キーの入力で向きを変える
void Player_Move::Rotation() {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	auto player = player_manager->player;
	auto player_status = player_manager->player_status;
	auto rotate_value = define_value.ROTATION_VALUE;

	// 同時押しで動かないように
	if (CheckHitKey(KEY_INPUT_RIGHT) && CheckHitKey(KEY_INPUT_LEFT)) {
		return;
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT)) {
		auto radian = rotate_value * DX_PI_F / 180;

		VECTOR player_rotation = MV1GetRotationXYZ(player->Get_Model_Handle());
		MV1SetRotationXYZ(player->Get_Model_Handle(),
						  VGet(player_rotation.x, player_rotation.y + radian, player_rotation.z));
	}
	else if (CheckHitKey(KEY_INPUT_LEFT)) {
		auto radian = rotate_value * DX_PI_F / 180;

		VECTOR player_rotation = MV1GetRotationXYZ(player->Get_Model_Handle());
		MV1SetRotationXYZ(player->Get_Model_Handle(), 
						  VGet(player_rotation.x, player_rotation.y - radian, player_rotation.z));
	}
}
