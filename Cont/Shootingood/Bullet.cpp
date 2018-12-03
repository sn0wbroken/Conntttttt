#include "Bullet.h"

// �R���X�g���N�^
Bullet::Bullet() {

}

Bullet::Bullet(Vector3D set_vector3, float set_radian, float set_speed) {
	vector3d.Arrange(set_vector3.x, set_vector3.y, set_vector3.z);

	speed = set_speed;
	radian = set_radian;
}

// �f�X�g���N�^
Bullet::~Bullet() {
}

// ���t���[���Ă΂��
void Bullet::Update() {
	if (actor_state == eActor_State::Action) {

		Move(Direction.x, Direction.y, Direction.z);

		// ��ʊO�ɏo�Ă����������
		if (Bullet_Off_Screen()) {
			//TODO:���͔��f�����A��������������
		}
	}
}

// �`��
void Bullet::Render() {
	if (actor_state == eActor_State::Action) {
			DrawSphere3D(vector3d.GetVECTOR(), 5, 5, GetColor(255, 0, 255), GetColor(0, 0, 0), TRUE);
	}
}

// x���W��Ԃ�
float Bullet::Get_X() {
	return vector3d.x;
}
// x���W��ݒ肷��
void Bullet::Set_X(float set_x) {
	vector3d.x = set_x;
}

// y���W��Ԃ�
float Bullet::Get_Y() {
	return vector3d.y;
}
// y���W��ݒ肷��
void Bullet::Set_Y(float set_y) {
	vector3d.y = set_y;
}

// z���W��Ԃ�
float Bullet::Get_Z() {
	return vector3d.z;
}
// z���W��ݒ肷��
void Bullet::Set_Z(float set_z) {
	vector3d.z = set_z;
}

// ���a��Ԃ�
int Bullet::Get_Radius() {
	return radius;
}

// �e�̈ړ�
void Bullet::Move(float set_x, float set_y, float set_z) {
	vector3d.Move(set_x += speed, set_y += speed, set_z += speed);
}

// ��ʉE�[����o�悤�Ƃ��ĂȂ���
bool Bullet::Is_Over_Max_X() {
	return define_value.MAX_SCREEN_X < vector3d.x;
}
// ��ʉ��[����o�悤�Ƃ��Ă��Ȃ���
bool Bullet::Is_Over_Max_Y() {
	return define_value.MAX_WINDOW_Y < vector3d.y;
}
// ��ʍ��[����o�悤�Ƃ��Ă��Ȃ���
bool Bullet::Is_Over_Min_X() {
	return define_value.MIN_SCREEN_X > vector3d.x;
}
// ��ʏ�[����o�悤�Ƃ��Ă��Ȃ���
bool Bullet::Is_Over_Min_Y() {
	return define_value.MIN_WINDOW_Y > vector3d.y;
}

// �e�ۂ���ʊO�ɏo�Ă��邩�𔻒f
bool Bullet::Bullet_Off_Screen() {
	return Is_Over_Max_X() || Is_Over_Min_X() ||
		   Is_Over_Max_Y() || Is_Over_Min_Y();
}
