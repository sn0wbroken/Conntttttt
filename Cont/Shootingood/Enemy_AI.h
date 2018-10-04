#pragma once

#include"Define_Value.h"

// エネミーのAIを管理
class Enemy_AI {
public:
	// コンストラクタ
	Enemy_AI();
	// デストラクタ
	~Enemy_AI();

	// 毎フレーム入る
	void Update();
	// 移動
	void Move();
	// 攻撃
	void Fire();

private:
	// 定数をまとめておく構造体
	Define_Value define_value;

	// エネミーが右端から出ようとしてないか
	bool Is_Over_Max_X(int coordinate_x);
	// エネミーが左端から出ようとしてないか
	bool Is_Over_MIn_X(int coordinate_x);

	// エネミーの撃った弾が画面下端から出たら消す
	void Bullet_Over_Max_Y_Erase();

	// これとエネミーの攻撃間隔を見て攻撃を繰り出す
	int attack_counter;

	// カウンターの初期化フラグ
	bool is_counter_reset;
};
