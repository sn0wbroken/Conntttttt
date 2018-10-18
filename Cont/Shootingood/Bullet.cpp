#include "Bullet.h"

// �R���X�g���N�^
Bullet::Bullet(float set_x, float set_y,float set_z, float set_direction_x, float set_direction_y,float set_direction_z) {
	radius = define_value.BULLET_RADIUS;

	vector3->Arrange(set_x, set_y,set_z);
	Direction->Arrange(set_direction_x,set_direction_y,set_direction_z);
}

// �f�X�g���N�^
Bullet::~Bullet() {

}

// ���t���[���Ă΂��
void Bullet::Update() {
	Move(Direction->x, Direction->y,Direction->z);
}

// �`��
void Bullet::Render() {
	DrawCircle((int)vector3->x, (int)vector3->y, radius,
			   GetColor(255, 0, 255), TRUE);
	//3D�`��p
	//DrawSphere3D(vector3->GetVECTOR(), 16,radius, GetColor(255, 0, 255), GetColor(0, 0, 0), TRUE);
}

// x���p��Ԃ�
float Bullet::Get_X() {
	return vector3->x;
}

void Bullet::Set_X(float set_x){
	vector3->x = set_x;
}

// y���W���擾
float Bullet::Get_Y() {
	return vector3->y;
}

void Bullet::Set_Y(float set_y){
	vector3->y = set_y;
}

float Bullet::Get_Z()
{
	return vector3->z;
}

void Bullet::Set_Z(float set_z)
{
	vector3->z = set_z;
}

// ���a��Ԃ�
int Bullet::Get_Radius() {
	return radius;
}

// �e�̈ړ�
void Bullet::Move(float set_x, float set_y,float set_z) {
	vector3->Move(set_x,set_y,set_z);
	
}

// ��ʉE�[����o�悤�Ƃ��ĂȂ���
bool Bullet::Is_Over_Max_X() {
	return define_value.MAX_SCREEN_X < vector3->x;
}
// ��ʉ��[����o�悤�Ƃ��Ă��Ȃ���
bool Bullet::Is_Over_Max_Y() {
	return define_value.MAX_WINDOW_Y < vector3->y;
}
// ��ʍ��[����o�悤�Ƃ��Ă��Ȃ���
bool Bullet::Is_Over_Min_X() {
	return define_value.MIN_SCREEN_X > vector3->x;
}
// ��ʏ�[����o�悤�Ƃ��Ă��Ȃ���
bool Bullet::Is_Over_Min_Y() {
	return define_value.MIN_WINDOW_Y > vector3->y;
}

// �e�ۂ���ʊO�ɏo�Ă��邩�𔻒f
bool Bullet::Bullet_Off_Screen(Bullet& player_bullet) {
	return player_bullet.Is_Over_Max_X() || player_bullet.Is_Over_Min_X() ||
		   player_bullet.Is_Over_Max_Y() || player_bullet.Is_Over_Min_Y();
}
