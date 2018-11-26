#pragma once

#include"Enum.h"
#include"Define_Value.h"

// エネミーのステータスとその処理を管理
class Enemy_Status {
public:
	// 移動する方向
	eMove_Direction move_direction;

	// コントラクタ
	Enemy_Status();
	// コピーコンストラクタ
	Enemy_Status(eStage stage);
	// デストラクタ
	~Enemy_Status();

	// 移動速度を返す
	int Get_Speed();
	// Uターンさせる
	void U_Turn();
	// 現在の体力を返す
	int Get_Hit_Point();
	// 攻撃間隔を返す
	int Get_Attack_Span();
	// 弾の速度を返す
	int Get_Bullet_Speed();

	// 死亡判定。trueで死亡。ダメージを受けたときに判断
	bool Is_Dead();
	// ダメージ判定を元に戻す
	void Initialize_Is_Damage();
	// ダメージを受けたかどうかを返す
	bool Is_Damage();

	// ダメージを受ける。プレイヤーの弾に当たったら呼ばれる
	void Damage();
private:
	// 簡易ファクトリー ステージに合わせてステータスを変更
	void Fake_Factory(eStage stage);

	// 定数をまとめておくクラス
	Define_Value define_value;

	// 移動速度
	int speed;
	// 体力 0で死亡
	int hit_point;
	// 攻撃の間隔
	int attack_span;
	// 打ち出す弾の速度
	int bullet_speed;

	// 死亡判定 trueで死亡
	bool is_dead;
	// ダメージ判定(ダメージを受けたかどうか) ダメージを受けたらtrue
	bool is_damage;
};
