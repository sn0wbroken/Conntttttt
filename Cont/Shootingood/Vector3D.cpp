#include "DxLib.h"
#include "Vector3D.h"

// �R���X�g���N�^
Vector3D::Vector3D() {

}

// �f�X�g���N�^
Vector3D::~Vector3D() {

}

DxLib::VECTOR Vector3D::GetVECTOR()
{
	return VGet( this->x,this->y,this->z );
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
