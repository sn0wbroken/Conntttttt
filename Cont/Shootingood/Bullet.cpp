#include "Bullet.h"

// コンストラクタ
Bullet::Bullet() {

}

Bullet::Bullet(Vector3D set_vector3, float set_radian, float set_speed) {
	vector3d.Arrange(set_vector3.x, set_vector3.y, set_vector3.z);

	speed = set_speed;
	radian = set_radian;
}

// デストラクタ
Bullet::~Bullet() {
}

// 毎フレーム呼ばれる
void Bullet::Update() {
	if (actor_state == eActor_State::Action) {

		Move(Direction.x, Direction.y, Direction.z);

		// 画面外に出ていたら消える
		if (Bullet_Off_Screen()) {
			//TODO:↑は判断だけ、消す処理を書く
		}
	}
}

// 描画
void Bullet::Render() {
	if (actor_state == eActor_State::Action) {
			DrawSphere3D(vector3d.GetVECTOR(), 5, 5, GetColor(255, 0, 255), GetColor(0, 0, 0), TRUE);
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
	vector3d.Move(set_x += speed, set_y += speed, set_z += speed);
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
bool Bullet::Bullet_Off_Screen() {
	return Is_Over_Max_X() || Is_Over_Min_X() ||
		   Is_Over_Max_Y() || Is_Over_Min_Y();
}
