#include "Bullet.h"

// コンストラクタ
Bullet::Bullet(int set_x, int set_y, int set_direction_x, int set_direction_y) {
	radius = define_value.BULLET_RADIUS;

	x = set_x;
	y = set_y;
	direction_x = set_direction_x;
	direction_y = set_direction_y;
	a.Left = 0;
}

// デストラクタ
Bullet::~Bullet() {

}

// 毎フレーム呼ばれる
void Bullet::Update() {
	Move(direction_x, direction_y);
}

// 描画
void Bullet::Render() {
	DrawCircle(x, y, radius,
			   GetColor(255, 0, 255), TRUE);
}

// x座用を返す
float Bullet::Get_X() {
	return x;
}

// y座標を取得
float Bullet::Get_Y() {
	return y;
}

// 半径を返す
int Bullet::Get_Radius() {
	return radius;
}

// 弾の移動
void Bullet::Move(float set_x, float set_y) {
	x += set_x;
	y += set_y;
}

// 画面右端から出ようとしてないか
bool Bullet::Is_Over_Max_X() {
	return define_value.MAX_SCREEN_X < x;
}
// 画面下端から出ようとしていないか
bool Bullet::Is_Over_Max_Y() {
	return define_value.MAX_WINDOW_Y < y;
}
// 画面左端から出ようとしていないか
bool Bullet::Is_Over_Min_X() {
	return define_value.MIN_SCREEN_X > x;
}
// 画面上端から出ようとしていないか
bool Bullet::Is_Over_Min_Y() {
	return define_value.MIN_WINDOW_Y > y;
}

// 弾丸が画面外に出ているかを判断
bool Bullet::Bullet_Off_Screen(Bullet& player_bullet) {
	return player_bullet.Is_Over_Max_X() || player_bullet.Is_Over_Min_X() ||
		   player_bullet.Is_Over_Max_Y() || player_bullet.Is_Over_Min_Y();
}
