#include "Player.h"

// コンストラクタ
Player::Player() {
	vector3 = new Vector3D;

	// プレイヤーの幅
	width = define_value.PLAYER_WIDTH;
	// プレイヤーの高さ
	height = define_value.PLAYER_HEIGHT;	

	// 初期位置は画面の中央
	vector3->Arrange((define_value.WINDOW_X - define_value.UI_SPACE) / 2,
					 define_value.WINDOW_Y - (height + (height / 2)), 0);

	rectangle =  new Rect<float>(vector3->x, vector3->y);
	
	// プレイヤーの画像をロード
	player_graph = LoadGraph("Picture/Player/Player.png");
}

// デストラクタ
Player::~Player() {}

// 初期化
void Player::Initialize() {
	vector3->x = (define_value.WINDOW_X - define_value.UI_SPACE) / 2;
	vector3->y = define_value.WINDOW_Y - (height + (height / 2));
	// 強化状態を元に戻す
	is_power_up = false;

	player_bullet.clear();
}

// プレイヤー、プレイヤーが撃った弾を描画
void Player::Render() {
	// 自分を描画
	DrawExtendGraph(vector3->x, vector3->y, Get_Right_Edge(), Get_Bottom_Edge(), player_graph, TRUE);

	// 撃った弾だけ描画
	for (auto& player_bullet_ : player_bullet) {
		player_bullet_.Render();
	}
}

// プレイヤーの右端の座標を返す
int Player::Get_Right_Edge() {
	return vector3->x + width;
}

// プレイヤーの左端の座標を返す
int Player::Get_Left_Edge() {
	return vector3->x;
}

// プレイヤーの上端の座標を返す
int Player::Get_Top_Edge() {
	return vector3->y;
}

// プレイヤーの下端の座標を返す
int Player::Get_Bottom_Edge() {
	return vector3->y + height;;
}

// 弾が出る位置を返す
int Player::Get_Shoot_Point() {
	return  vector3->x + (width / 2);
}

// パワーアップ状態であるかをセットする
void Player::Set_Power_Up(bool set_is_power_up) {
	is_power_up = set_is_power_up;
}

// パワーアップ状態であるかを返す
bool Player::Get_Power_Up() {
	return is_power_up;
}
