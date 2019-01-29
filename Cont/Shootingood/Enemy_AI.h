#pragma once

#include"Define_Value.h"
#include"Vector3D.h"
#include"Enemy.h"

// エネミーのAIを管理
class Enemy_AI {
public:
	// コンストラクタ
	Enemy_AI();
	// デストラクタ
	~Enemy_AI();

	// 毎フレーム入る
	void Update();

	// 敵を動かす
	void Move_Enemy();

private:
	// 定数をまとめておくクラス
	Define_Value define_value;
};
