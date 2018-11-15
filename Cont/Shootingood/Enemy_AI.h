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

private:
	// 定数をまとめておく構造体
	Define_Value define_value;
};
