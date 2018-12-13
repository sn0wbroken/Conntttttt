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

	void MoveAI0();

#pragma region Getter
	//Enemy_Status GetEnemyStatus()
	//{
	//	return *m_enemy->enemy_status;
	//}
#pragma endregion
	std::shared_ptr<Enemy> enemy;
private:
	// 定数をまとめておくクラス
	Define_Value define_value;
};
