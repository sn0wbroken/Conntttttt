#pragma once

#define _USE_MATH_DEFINES

#include"DxLib.h"
#include"Define_Value.h"

#include<cmath>
#include<memory>

// プレイヤーの移動を管理する
class Player_Move {
public:
	// コンストラクタ
	Player_Move();
	// デストラクタ
	~Player_Move();

	// キー入力でプレイヤーを移動させる
	void Move();
	// キー入力でプレイヤーを回転させる
	void Rotation();

private:
	// 定数をまとめておくクラス
	Define_Value define_value;
};
