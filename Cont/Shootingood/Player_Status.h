#pragma once

#include"Define_Value.h"

#include<memory>

// プレイヤーのステータスとその処理を管理
class Player_Status {
public:
	// コンストラクタ
	Player_Status();
	// デストラクタ
	~Player_Status();

	// 攻撃を受けたら呼ばれる。体力を1減らす
	void Damage();
	// 残機をリセットする
	void Reset_Life();

	// 残機を返す
	int Get_Life();

	// 死んでいるかを返す
	bool Get_Is_Dead();

private:
	// 定数をまとめておくクラス
	Define_Value define_value;

	// 攻撃力(敵のHP - 攻撃力で計算)
	int attack;
	// 移動速度
	int speed;
	// 残機
	int life;
};
