#pragma once

#include"Define_Value.h"
#include"Vector3D.h"
#include"Math.h"

// エネミーのAIを管理
class Enemy_AI {
public:
	// コンストラクタ
	Enemy_AI(int Enemy_Model,Vector3D *EnemyPosition);
	// デストラクタ
	~Enemy_AI();

	// 毎フレーム入る
	void Update();


	void MoveAI0(Vector3D enemy,Vector3D player);
private:
	// 定数をまとめておくクラス
	Define_Value define_value;
	Vector3D * m_EPosition; //TODO::要修正
	int m_EnemyModel;
};
