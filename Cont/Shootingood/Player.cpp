#include "Player.h"

// コンストラクタ
Player::Player() {
	// プレイヤーの幅
	width = define_value.PLAYER_WIDTH;
	// プレイヤーの高さ
	height = define_value.PLAYER_HEIGHT;

	// 初期化
	Initialize();

	rectangle = Rect<float>(vector3.x, vector3.y);

	Create_Actor("Resources/Player/Player.x");
	// プレイヤーの座標を指定
	MV1SetPosition(model_handle, VGet(vector3.x, vector3.y, 0.0f));
	// プレイヤーの大きさを指定
	MV1SetScale(model_handle, VGet(40.0f, 40.0f, 35.0f));
	// プレイヤーの表示角度を調整
	MV1SetRotationXYZ(model_handle, VGet(270 * (DX_PI_F / 180), 0.0f, 180 * (DX_PI_F / 180)));
}

// デストラクタ
Player::~Player() {}

// 初期化
void Player::Initialize() {
	vector3.Arrange((define_value.WINDOW_X - define_value.UI_SPACE) / 2, define_value.WINDOW_Y / 2, 0);
	is_power_up = false;

	is_dead = false;
}

//// プレイヤーの右端の座標を返す
//float Player::Get_Right_Edge() {
//	return vector3.x + width;
//}
//
//// プレイヤーの左端の座標を返す
//float Player::Get_Left_Edge() {
//	return vector3.x;
//}
//
//// プレイヤーの上端の座標を返す
//float Player::Get_Top_Edge() {
//	return vector3.y;
//}
//
//// プレイヤーの下端の座標を返す
//float Player::Get_Bottom_Edge() {
//	return vector3.y + height;
//}

// 弾が出る位置を返す
float Player::Get_Shoot_Point() {
	return  vector3.x + (width / 2);
}

// パワーアップ状態であるかをセットする
void Player::Set_Power_Up(bool set_is_power_up) {
	is_power_up = set_is_power_up;
}

// パワーアップ状態であるかを返す
bool Player::Get_Power_Up() {
	return is_power_up;
}
