#include "Bullet.h"

// コンストラクタ
Bullet::Bullet(float set_x, float set_y, float set_z, float set_direction_x, float set_direction_y, float set_direction_z) {
	radius = define_value.BULLET_RADIUS;
 
	vector3.Arrange(set_x, set_y, set_z);
	Direction.Arrange(set_direction_x, set_direction_y, set_direction_z);
}

// デストラクタ
Bullet::~Bullet() {
}

// 毎フレーム呼ばれる
void Bullet::Update() {
	Move(Direction.x, Direction.y, Direction.z);
}

// 描画
void Bullet::Render() {
	DrawSphere3D(VGet(vector3.x, vector3.y, vector3.z), 5, 5, GetColor(255, 0, 255), GetColor(0,0,0), TRUE);
}

// x座標を返す
float Bullet::Get_X() {
	return vector3.x;
}
// x座標を設定する
void Bullet::Set_X(float set_x) {
	vector3.x = set_x;
}

// y座標を返す
float Bullet::Get_Y() {
	return vector3.y;
}
// y座標を設定する
void Bullet::Set_Y(float set_y) {
	vector3.y = set_y;
}

// z座標を返す
float Bullet::Get_Z() {
	return vector3.z;
}
// z座標を設定する
void Bullet::Set_Z(float set_z) {
	vector3.z = set_z;
}

// 半径を返す
int Bullet::Get_Radius() {
	return radius;
}

// 弾の移動
void Bullet::Move(float set_x, float set_y, float set_z) {
	vector3.Move(set_x, set_y, set_z);
}

// 画面右端から出ようとしてないか
bool Bullet::Is_Over_Max_X() {
	return define_value.MAX_SCREEN_X < vector3.x;
}
// 画面下端から出ようとしていないか
bool Bullet::Is_Over_Max_Y() {
	return define_value.MAX_WINDOW_Y < vector3.y;
}
// 画面左端から出ようとしていないか
bool Bullet::Is_Over_Min_X() {
	return define_value.MIN_SCREEN_X > vector3.x;
}
// 画面上端から出ようとしていないか
bool Bullet::Is_Over_Min_Y() {
	return define_value.MIN_WINDOW_Y > vector3.y;
}

// 弾丸が画面外に出ているかを判断
bool Bullet::Bullet_Off_Screen(Bullet& player_bullet) {
	return player_bullet.Is_Over_Max_X() || player_bullet.Is_Over_Min_X() ||
		   player_bullet.Is_Over_Max_Y() || player_bullet.Is_Over_Min_Y();
}