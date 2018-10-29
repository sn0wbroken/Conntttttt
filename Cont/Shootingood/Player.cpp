#include "Player.h"

// コンストラクタ
Player::Player() {
	// プレイヤーの幅
	width = define_value.PLAYER_WIDTH;
	// プレイヤーの高さ
	height = define_value.PLAYER_HEIGHT;

	// 初期位置は画面の中央
	vector3.Arrange((define_value.WINDOW_X - define_value.UI_SPACE) / 2,
	define_value.WINDOW_Y - (height + (height / 2)), 0);

	rectangle = Rect<float>(vector3.x, vector3.y);

	//TEST------------------------------------
	// 初期座標を設定
	matrix[0] = VGet(250.0f, 250.0f, 0.0f);
	matrix[1] = VGet(225.0f, 200.0f, 0.0f);
	matrix[2] = VGet(275.0f, 200.0f, 0.0f);
	auto wdith  = matrix[2].x - matrix[1].x;
	auto height = matrix[1].y - matrix[0].y;
	// 重心(三角形の中心)
	center = VGet(matrix[1].x + (width / 2), matrix[0].y + (height / 2), 0.0f);
	//----------------------------------------

	// プレイヤーの画像をロード
	player_graph = LoadGraph("Picture/Player/Player.png");
}

// デストラクタ
Player::~Player() {}

// 初期化
void Player::Initialize() {
	vector3.x = (define_value.WINDOW_X - define_value.UI_SPACE) / 2;
	vector3.y = define_value.WINDOW_Y - (height + (height / 2));
	// 強化状態を元に戻す
	is_power_up = false;

	player_bullet.clear();
}

// プレイヤー、プレイヤーが撃った弾を描画
void Player::Render() {
	// 自分を描画
	DrawExtendGraph(vector3.x, vector3.y, Get_Right_Edge(), Get_Bottom_Edge(), player_graph, TRUE);

	//TEST--------------------------------------------------
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		auto hoge = -64.0f;
		MATRIX rot_x = MGetRotZ(M_PI / hoge);
		auto t_ = MMult(MGetTranslate(VScale(center, -1.0f)), MMult(rot_x, MGetTranslate(center)));

		matrix[0] = VTransform(matrix[0], t_);
		matrix[1] = VTransform(matrix[1], t_);
		matrix[2] = VTransform(matrix[2], t_);
	}

	DrawTriangle3D(matrix[0],
		matrix[1],
		matrix[2], GetColor(0, 255, 0), TRUE);
	//------------------------------------------------------

	// 撃った弾だけ描画
	for (auto& player_bullet_ : player_bullet) {
		player_bullet_.Render();
	}
}

// プレイヤーの右端の座標を返す
float Player::Get_Right_Edge() {
	return vector3.x + width;
}

// プレイヤーの左端の座標を返す
float Player::Get_Left_Edge() {
	return vector3.x;
}

// プレイヤーの上端の座標を返す
float Player::Get_Top_Edge() {
	return vector3.y;
}

// プレイヤーの下端の座標を返す
float Player::Get_Bottom_Edge() {
	return vector3.y + height;;
}

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