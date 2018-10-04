#include "Bullet.h"

// �R���X�g���N�^
Bullet::Bullet(int set_x, int set_y, int set_direction_x, int set_direction_y) {
	radius = define_value.BULLET_RADIUS;

	x = set_x;
	y = set_y;
	direction_x = set_direction_x;
	direction_y = set_direction_y;
}

// �f�X�g���N�^
Bullet::~Bullet() {

}

// ���t���[���Ă΂��
void Bullet::Update() {
	Move(direction_x, direction_y);
}

// �`��
void Bullet::Render() {
	DrawCircle(x, y, radius,
			   GetColor(255, 0, 255), TRUE);
}

// x���p��Ԃ�
int Bullet::Get_X() {
	return x;
}

// y���W���擾
int Bullet::Get_Y() {
	return y;
}

// ���a��Ԃ�
int Bullet::Get_Radius() {
	return radius;
}

// �e�̈ړ�
void Bullet::Move(int set_x, int set_y) {
	x += set_x;
	y += set_y;
}

// ��ʉ�������o�悤�Ƃ��Ă��Ȃ���
bool Bullet::Is_Over_Max_Y() {
	return define_value.MAX_WINDOW_Y < y;
}

// ��ʏ㕔����o�悤�Ƃ��Ă��Ȃ���
bool Bullet::Is_Over_Min_Y() {
	return define_value.MIN_WINDOW_Y > y;
}

