#pragma once

#include"Player.h"
#include"Define_Value.h"

#include<memory>

// プレイヤーのステータスとその処理を管理
class Player_Status {
public:
	// コンストラクタ
	Player_Status();
	// デストラクタ
	~Player_Status();

	// 死んだら呼ばれる。残機を1減らす
	void Dead();
	// 残機をリセットする
	void Reset_Life();
	// 残機を返す
	int Get_Life();

	// 移動速度を返す
	int Get_Speed();

private:
	std::shared_ptr<Player> player;

	// 定数をまとめておく構造体
	Define_Value define_value;

	// 攻撃力(敵のHP - 攻撃力で計算)
	int attack;
	// 移動速度
	int speed;
	// 残機
	int life;
};
