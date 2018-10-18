#include "DxLib.h"
#include "Vector3D.h"

// �R���X�g���N�^
Vector3D::Vector3D() {

}

Vector3D::Vector3D(const Vector3D &vec){
	x = vec.x;
	y = vec.y;
	z = vec.z;
}

Vector3D::Vector3D(const DxLib::VECTOR & vec){
	x = vec.x;
	y = vec.y;
	z = vec.z;
}

// �f�X�g���N�^
Vector3D::~Vector3D() {

}

DxLib::VECTOR Vector3D::GetVECTOR()
{
	return VGet( x,y,z );
}

// �ړ�
void Vector3D::Move(float set_x, float set_y, float set_z) {
	x += set_x;
	y += set_y;
	z += set_z;
}
// �z�u
void Vector3D::Arrange(float set_x, float set_y, float set_z) {
	x = set_x;
	y = set_y;
	z = set_z;
}
