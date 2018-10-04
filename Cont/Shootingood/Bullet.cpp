#include "Bullet.h"

// コンストラクタ
Bullet::Bullet(int set_x, int set_y, int set_direction_x, int set_direction_y) {
	radius = define_value.BULLET_RADIUS;

	x = set_x;
	y = set_y;
	direction_x = set_direction_x;
	direction_y = set_direction_y;
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
int Bullet::Get_X() {
	return x;
}

// y座標を取得
int Bullet::Get_Y() {
	return y;
}

// 半径を返す
int Bullet::Get_Radius() {
	return radius;
}

// 弾の移動
void Bullet::Move(int set_x, int set_y) {
	x += set_x;
	y += set_y;
}

// 画面下部から出ようとしていないか
bool Bullet::Is_Over_Max_Y() {
	return define_value.MAX_WINDOW_Y < y;
}

// 画面上部から出ようとしていないか
bool Bullet::Is_Over_Min_Y() {
	return define_value.MIN_WINDOW_Y > y;
}

