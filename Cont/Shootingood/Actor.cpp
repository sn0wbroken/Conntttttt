#include "Actor.h"

// ���݂�x���W��Ԃ�
float Actor::Get_X() {
	return vector3->x;
}
// x���W���Z�b�g����
void Actor::Set_X(float set_x) {
	vector3->x = set_x;
}

// ���݂�y���W��Ԃ�
float Actor::Get_Y() {
	return vector3->y;
}
// y���W��ݒ肷��
void Actor::Set_Y(float set_y) {
	vector3->y = set_y;
}
// ����Ԃ�
int Actor::Get_Width() {
	return width;
}
// ������Ԃ�
int Actor::Get_Height() {
	return height;
}
