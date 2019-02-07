#include "Enemy_Status.h"

#include"Enemy_Manager.h"

// コンストラクタ
Enemy_Status::Enemy_Status() {};

// コピーコンストラクタ
Enemy_Status::Enemy_Status(eStage stage) :
	is_dead(false),
	is_damage(false),
	move_direction(eMove_Direction::Right) {
}

// デストラクタ
Enemy_Status::~Enemy_Status() {
}

// 移動速度を返す
int Enemy_Status::Get_Speed() {
	return speed;
}

// Uターンさせる
void Enemy_Status::U_Turn() {
	speed = -speed;
}

// 現在の体力を返す
int Enemy_Status::Get_Hit_Point() {
	return hit_point;
}

// 攻撃間隔を返す
int Enemy_Status::Get_Attack_Span() {
	return attack_span;
}

// 弾の速度を返す
int Enemy_Status::Get_Bullet_Speed() {
	return bullet_speed;
}

// 死んでいるかを返す
bool Enemy_Status::Is_Dead() {
	return is_dead;
}

// 死んでもらう。攻撃を受けたときに呼ばれる
void Enemy_Status::Dead() {
	is_dead = true;
}

// ダメージ判定を元に戻す
void Enemy_Status::Initialize_Is_Damage() {
	is_damage = false;
}

void Enemy_Status::Initialize_IsDead()
{
	is_dead = false;
}
