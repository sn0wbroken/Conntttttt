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

	void Move_AI0();

	std::shared_ptr<Enemy> enemy;
private:
	// 定数をまとめておくクラス
	Define_Value define_value;
};
