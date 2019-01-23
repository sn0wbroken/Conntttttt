#include"Character.h"

// コンストラクタ
Character::Character() {

}

// 現在のx座標を返す
float Character::Get_X() {
	return vector3d.x;
}
// x座標をセットする
void Character::Set_X(float set_x) {
	vector3d.x = set_x;
}

// 現在のy座標を返す
float Character::Get_Y() {
	return vector3d.y;
}
// y座標を設定する
void Character::Set_Y(float set_y) {
	vector3d.y = set_y;
}

// 現在のz座標を返す
float Character::Get_Z() {
	return vector3d.z;
}
// z座標を設定する
void Character::Set_Z(float set_z) {
	vector3d.z = set_z;
}

// 出現位置を設定する
void Character::Set_Arrange_Poisition(float set_x, float set_y, float set_z) {
	vector3d.Set_Vector(set_x, set_y, set_z);
}

// vectorを設定する
void Character::Set_Position(Vector3D set_vector3) {
	vector3d = set_vector3;
}

// 座標を返す
Vector3D Character::Get_Position() {
	return vector3d;
}

// 大きさを返す
Object_Size Character::Get_Size() {
	return size;
}

// アクターの右端の座標を返す
float Character::Get_Right_Edge() {
	return center_position.x - (size.width / 2);
}
// アクターの左端の座標を返す
float Character::Get_Left_Edge() {
	return center_position.x + (size.width / 2);
}
// アクターの上端の座標を返す
float Character::Get_Top_Edge() {
	return center_position.y - (size.height / 2);
}
// アクターの下端の座標を返す
float Character::Get_Bottom_Edge() {
	return center_position.y + (size.height / 2);
}

// アクターのモデルハンドルを返す
int &Character::Get_Model_Handle() {
	return model_handle;
}

// アクターオブジェクトを生成する
void Character::Create_Actor(TCHAR* model_path) {
	// プレイヤーのモデルハンドルを格納
	model_handle = MV1LoadModel(model_path);
}

// 描画を行う
void Character::Render() {
	MV1DrawModel(model_handle);
	MV1SetPosition(model_handle, vector3d);
}
