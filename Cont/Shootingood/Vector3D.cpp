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

// X座標を返す
float Vector3D::Get_X() {
	return x;
}
// Y座標を返す
float Vector3D::Get_Y() {
	return y;
}
// Z座標を返す
float Vector3D::Get_Z() {
	return z;
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


// X座標に引数の値を加算したVectorを返す
Vector3D Vector3D::Add_VectorX(float add_value) {
	Vector3D result;
	result.x = x + add_value;
	result.y = y;
	result.z = z;
	return result;
}
// Y座標に引数の値を加算したVectorを返す
Vector3D Vector3D::Add_VectorY(float add_value) {
	Vector3D result;
	result.x = x;
	result.y = y + add_value;
	result.z = z;
	return result;
}
// Z座標に引数の値を加算したVectorを返す
Vector3D Vector3D::Add_VectorZ(float add_value) {
	Vector3D result;
	result.x = x;
	result.y = y;
	result.z = z + add_value;
	return result;
}
// X座標に引数の値を減算したVectorを返す
Vector3D Vector3D::Subtract_VectorX(float add_value) {
	Vector3D result;
	result.x = x - add_value;
	result.y = y;
	result.z = z;
	return result;
}
// Y座標に引数の値を減算したVectorを返す
Vector3D Vector3D::Subtract_VectorY(float add_value) {
	Vector3D result;
	result.x = x;
	result.y = y - add_value;
	result.z = z;
	return result;
}
// Z座標に引数の値を減算したVectorを返す
Vector3D Vector3D::Subtract_VectorZ(float add_value) {
	Vector3D result;
	result.x = x;
	result.y = y;
	result.z = z - add_value;
	return result;
}


// X座標に引数の値を加算した数値を返す
float Vector3D::Add_X(float add_value) {
	return x + add_value;
}
// Y座標に引数の値を加算した数値を返す
float Vector3D::Add_Y(float add_value) {
	return y + add_value;
}
// Z座標に引数の値を加算した数値を返す
float Vector3D::Add_Z(float add_value) {
	return z + add_value;
}
// X座標に引数の値を減算した数値を返す
float Vector3D::Subtract_X(float add_value) {
	return x - add_value;
}
// Y座標に引数の値を減算した数値を返す
float Vector3D::Subtract_Y(float add_value) {
	return y - add_value;
}
// Z座標に引数の値を減算した数値を返す
float Vector3D::Subtract_Z(float add_value) {
	return z - add_value;
}
