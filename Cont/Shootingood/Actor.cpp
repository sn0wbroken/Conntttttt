#include "Actor.h"

// ���݂�x���W��Ԃ�
int Actor::Get_X() {
	return vector3->x;
}
// x���W���Z�b�g����
void Actor::Set_X(int set_x) {
	vector3->x = set_x;
}

// ���݂�y���W��Ԃ�
int Actor::Get_Y() {
	return vector3->y;
}
// y���W��ݒ肷��
void Actor::Set_Y(int set_y) {
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
