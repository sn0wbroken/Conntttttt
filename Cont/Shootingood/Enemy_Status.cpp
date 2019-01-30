#include "Enemy_Status.h"

#include"Enemy_Manager.h"

// �R���X�g���N�^
Enemy_Status::Enemy_Status() {};

// �R�s�[�R���X�g���N�^
Enemy_Status::Enemy_Status(eStage stage) :
	is_dead(false),
	is_damage(false),
	move_direction(eMove_Direction::Right) {
}

// �f�X�g���N�^
Enemy_Status::~Enemy_Status() {
}

// �ړ����x��Ԃ�
int Enemy_Status::Get_Speed() {
	return speed;
}

// U�^�[��������
void Enemy_Status::U_Turn() {
	speed = -speed;
}

// ���݂̗̑͂�Ԃ�
int Enemy_Status::Get_Hit_Point() {
	return hit_point;
}

// �U���Ԋu��Ԃ�
int Enemy_Status::Get_Attack_Span() {
	return attack_span;
}

// �e�̑��x��Ԃ�
int Enemy_Status::Get_Bullet_Speed() {
	return bullet_speed;
}

// ����ł��邩��Ԃ�
bool Enemy_Status::Is_Dead() {
	return is_dead;
}

// ����ł��炤�B�U�����󂯂��Ƃ��ɌĂ΂��
void Enemy_Status::Dead() {
	is_dead = true;
}

// �_���[�W��������ɖ߂�
void Enemy_Status::Initialize_Is_Damage() {
	is_damage = false;
}

void Enemy_Status::Initialize_IsDead()
{
	is_dead = false;
}
