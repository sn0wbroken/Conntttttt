#include "Actor.h"

// ���݂�x���W��Ԃ�
int Actor::Get_X() {
	return x;
}
// x���W���Z�b�g����
void Actor::Set_X(int set_x) {
	x = set_x;
}

// ���݂�y���W��Ԃ�
int Actor::Get_Y() {
	return y;
}
// y���W��ݒ肷��
void Actor::Set_Y(int set_y) {
	y = set_y;
}
// ����Ԃ�
int Actor::Get_Width() {
	return width;
}
// ������Ԃ�
int Actor::Get_Height() {
	return height;
}
