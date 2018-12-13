#include "Bullet.h"

// コンストラクタ
Bullet::Bullet() {

}

// デストラクタ
Bullet::~Bullet() {
}

// 描画
void Bullet::Render() {
	if (actor_state == eActor_State::Action) {
		DrawSphere3D(vector3d.GetVECTOR(), 5, 5, GetColor(255, 0, 255), GetColor(0, 0, 0), TRUE);
		Move(vector3d.x + speed, vector3d.y + speed, vector3d.z);
	}
}

// x座標を返す
float Bullet::Get_X() {
	return vector3d.x;
}
// x座標を設定する
void Bullet::Set_X(float set_x) {
	vector3d.x = set_x;
}

// y座標を返す
float Bullet::Get_Y() {
	return vector3d.y;
}
// y座標を設定する
void Bullet::Set_Y(float set_y) {
	vector3d.y = set_y;
}

// z座標を返す
float Bullet::Get_Z() {
	return vector3d.z;
}
// z座標を設定する
void Bullet::Set_Z(float set_z) {
	vector3d.z = set_z;
}

// 半径を返す
int Bullet::Get_Radius() {
	return radius;
}

// 弾の移動
void Bullet::Move(float set_x, float set_y, float set_z) {
	vector3d.Move(speed * cos(radian), 0.0f, speed * sin(radian));
}

// 飛んでいく角度を設定する
void Bullet::Set_Radian(float set_radian) {
	radian = set_radian;
}

// 飛んでいく速度を設定する
void Bullet::Set_Speed(float set_speed) {
	speed = set_speed;
}

// 画面右端から出ようとしてないか
bool Bullet::Is_Over_Max_X() {
	return define_value.MAX_SCREEN_X < vector3d.x;
}
// 画面下端から出ようとしていないか
bool Bullet::Is_Over_Max_Y() {
	return define_value.MAX_WINDOW_Y < vector3d.y;
}
// 画面左端から出ようとしていないか
bool Bullet::Is_Over_Min_X() {
	return define_value.MIN_SCREEN_X > vector3d.x;
}
// 画面上端から出ようとしていないか
bool Bullet::Is_Over_Min_Y() {
	return define_value.MIN_WINDOW_Y > vector3d.y;
}

// 弾丸が画面外に出ているかを判断
bool Bullet::Off_Screen() {
	if (actor_state == eActor_State::Action) {
		return Is_Over_Max_X() || Is_Over_Min_X() ||
			   Is_Over_Max_Y() || Is_Over_Min_Y();
	}
	return false;
}
