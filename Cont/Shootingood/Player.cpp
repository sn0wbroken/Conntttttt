#include "Player.h"

// コンストラクタ
Player::Player() {
	// プレイヤーの幅
	width = define_value.PLAYER_WIDTH;
	// プレイヤーの高さ
	height = define_value.PLAYER_HEIGHT;

	// 初期化
	Initialize();

	// モデルを取得
	Create_Actor("Resources/Player/Player.x");
	// プレイヤーの座標を指定 
	MV1SetPosition(model_handle, VGet(vector3d.x, vector3d.y, 0.0f));
	// プレイヤーの表示角度を調整
	MV1SetRotationXYZ(model_handle, VGet(0,0,0));
}

// デストラクタ
Player::~Player() {}

// 初期化
void Player::Initialize() {
	// UIの表示域分ずらす(ゲーム画面の中心)
	vector3d.Arrange(/*-define_value.UI_SPACE / 2*/0, 0, 0);
	is_power_up = false;

	is_dead = false;
}

// パワーアップ状態であるかをセットする
void Player::Set_Power_Up(bool set_is_power_up) {
	is_power_up = set_is_power_up;
}

// パワーアップ状態であるかを返す
bool Player::Get_Power_Up() {
	return is_power_up;
}
