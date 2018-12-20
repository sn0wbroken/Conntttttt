#include "DxLib.h"
#include "Vector3D.h"

#include <cmath>

// �R���X�g���N�^
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

// �f�X�g���N�^
Vector3D::~Vector3D() {
}

DxLib::VECTOR Vector3D::GetVECTOR() {
	return VGet(x, y, z);
}

// �����̗v�f�������Vector3D�^�ɂ��ĕԂ�
Vector3D Vector3D::Get_Vector(float x, float y, float z) {
	Vector3D result;
	result.x = x;
	result.y = y;
	result.z = z;
	return result;
}

// �ړ�
void Vector3D::Move(float set_x, float set_y, float set_z) {
	x += set_x;
	y += set_y;
	z += set_z;
}
// �z�u
void Vector3D::Set_Vector(float set_x, float set_y, float set_z) {
	x = set_x;
	y = set_y;
	z = set_z;
}
