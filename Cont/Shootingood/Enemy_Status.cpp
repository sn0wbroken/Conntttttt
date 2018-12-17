#include "Enemy_Status.h"

#include"Enemy_Manager.h"

// �R���X�g���N�^
Enemy_Status::Enemy_Status() {};

// �R�s�[�R���X�g���N�^
Enemy_Status::Enemy_Status(eStage stage) :
	hit_point(define_value.ENEMY_MAX_HP),
	is_damage(false),
	move_direction(eMove_Direction::Right) {
	// �X�e�[�W�ɍ��킹���X�^�[�^�X���Z�b�g
	Fake_Factory(stage);
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

// ���S����B����ł�����true
bool Enemy_Status::Is_Dead() {
	return hit_point <= 0;
}

// �_���[�W��������ɖ߂�
void Enemy_Status::Initialize_Is_Damage() {
	is_damage = false;
}

void Enemy_Status::Initialize_HitPoint()
{
	hit_point = define_value.ENEMY_MAX_HP;
}

// �_���[�W���󂯂����ǂ�����Ԃ�
bool Enemy_Status::Is_Damage() {
	return is_damage;
}

// �_���[�W���󂯂�B�v���C���[�̒e�ɓ����������ɌĂ΂��
void Enemy_Status::Damage() {
	--hit_point;
	is_damage = true;
}

// �ȈՃt�@�N�g���[ �X�e�[�W�ɍ��킹�ăX�e�[�^�X��ύX
void Enemy_Status::Fake_Factory(eStage stage) {
	switch (stage) {
	case eStage::stage1:
		speed = 5;
		hit_point = 15;
		attack_span = 80;
		bullet_speed = 5;
		break;
	case eStage::stage2:
		speed = 8;
		hit_point = 30;
		attack_span = 60;
		bullet_speed = 8;
		break;
	case eStage::stage3:
		speed = 12;
		hit_point = 45;
		attack_span = 50;
		bullet_speed = 12;
		break;
	}
}