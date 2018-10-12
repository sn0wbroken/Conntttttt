#include "Bullet.h"

// �R���X�g���N�^
Bullet::Bullet(int set_x, int set_y, int set_direction_x, int set_direction_y) {
	radius = define_value.BULLET_RADIUS;

	x = set_x;
	y = set_y;
	direction_x = set_direction_x;
	direction_y = set_direction_y;
	a.Left = 0;
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
float Bullet::Get_X() {
	return x;
}

// y���W���擾
float Bullet::Get_Y() {
	return y;
}

// ���a��Ԃ�
int Bullet::Get_Radius() {
	return radius;
}

// �e�̈ړ�
void Bullet::Move(float set_x, float set_y) {
	x += set_x;
	y += set_y;
}

// ��ʉE�[����o�悤�Ƃ��ĂȂ���
bool Bullet::Is_Over_Max_X() {
	return define_value.MAX_SCREEN_X < x;
}
// ��ʉ��[����o�悤�Ƃ��Ă��Ȃ���
bool Bullet::Is_Over_Max_Y() {
	return define_value.MAX_WINDOW_Y < y;
}
// ��ʍ��[����o�悤�Ƃ��Ă��Ȃ���
bool Bullet::Is_Over_Min_X() {
	return define_value.MIN_SCREEN_X > x;
}
// ��ʏ�[����o�悤�Ƃ��Ă��Ȃ���
bool Bullet::Is_Over_Min_Y() {
	return define_value.MIN_WINDOW_Y > y;
}

// �e�ۂ���ʊO�ɏo�Ă��邩�𔻒f
bool Bullet::Bullet_Off_Screen(Bullet& player_bullet) {
	return player_bullet.Is_Over_Max_X() || player_bullet.Is_Over_Min_X() ||
		   player_bullet.Is_Over_Max_Y() || player_bullet.Is_Over_Min_Y();
}
