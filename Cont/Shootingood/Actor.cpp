#include "Actor.h"

// ���݂�x���W��Ԃ�
float Actor::Get_X() {
	return vector3.x;
}
// x���W���Z�b�g����
void Actor::Set_X(float set_x) {
	vector3.x = set_x;
}

// ���݂�y���W��Ԃ�
float Actor::Get_Y() {
	return vector3.y;
}
// y���W��ݒ肷��
void Actor::Set_Y(float set_y) {
	vector3.y = set_y;
}
float Actor::Get_Z()
{
	return vector3.z;
}

void Actor::Set_Z(float set_z)
{
	vector3.z = set_z;
}
// ����Ԃ�
int Actor::Get_Width() {
	return width;
}
// ������Ԃ�
int Actor::Get_Height() {
	return height;
}

void Actor::Set_Vector3D(float set_x, float set_y, float set_z)
{
	vector3.Arrange(set_x, set_y, set_z);
}

void Actor::Set_Vector3D(Vector3D Vec3)
{
	vector3 = Vec3;
}