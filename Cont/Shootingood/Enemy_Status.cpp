#include "Enemy_Status.h"

#include"Enemy_Manager.h"

// コンストラクタ
Enemy_Status::Enemy_Status() {};

// コピーコンストラクタ
Enemy_Status::Enemy_Status(eStage stage) :
	hit_point(define_value.ENEMY_MAX_HP),
	is_damage(false),
	move_direction(eMove_Direction::Right) {
	// ステージに合わせたスタータスをセット
	Fake_Factory(stage);
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

// 死亡判定。死んでいたらtrue
bool Enemy_Status::Is_Dead() {
	return hit_point <= 0;
}

// ダメージ判定を元に戻す
void Enemy_Status::Initialize_Is_Damage() {
	is_damage = false;
}

void Enemy_Status::Initialize_HitPoint()
{
	hit_point = define_value.ENEMY_MAX_HP;
}

// ダメージを受けたかどうかを返す
bool Enemy_Status::Is_Damage() {
	return is_damage;
}

// ダメージを受ける。プレイヤーの弾に当たった時に呼ばれる
void Enemy_Status::Damage() {
	--hit_point;
	is_damage = true;
}

// 簡易ファクトリー ステージに合わせてステータスを変更
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