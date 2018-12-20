#include "DxLib.h"
#include "Vector3D.h"

#include <cmath>

// コンストラクタ
Vector3D::Vector3D() {
}

Vector3D::Vector3D(float _x, float _y, float _z) {
	x = _x;
	y = _y;
	z = _z;
}

Vector3D::Vector3D(const Vector3D &vec) {
	x = vec.x;
	y = vec.y;
	z = vec.z;
}

Vector3D::Vector3D(const DxLib::VECTOR & vec) {
	x = vec.x;
	y = vec.y;
	z = vec.z;
}

// デストラクタ
Vector3D::~Vector3D() {
}

DxLib::VECTOR Vector3D::GetVECTOR() {
	return VGet(x, y, z);
}

// 引数の要素を自作のVector3D型にして返す
Vector3D Vector3D::Get_Vector(float x, float y, float z) {
	Vector3D result;
	result.x = x;
	result.y = y;
	result.z = z;
	return result;
}

// 移動
void Vector3D::Move(float set_x, float set_y, float set_z) {
	x += set_x;
	y += set_y;
	z += set_z;
}
// 配置
void Vector3D::Set_Vector(float set_x, float set_y, float set_z) {
	x = set_x;
	y = set_y;
	z = set_z;
}
