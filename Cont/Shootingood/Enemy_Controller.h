#pragma once
#include<memory>
#include"Enemy_AI.h"
#include"Enemy_Status.h"

// エネミーの動きを制御する
class Enemy_Controller {
public:
	// エネミーのAIを管理	
	std::shared_ptr<Enemy_AI> enemy_AI;
	// コンストラクタ
	Enemy_Controller();
	// デストラクタ
	virtual ~Enemy_Controller();
	//アップデート処理
	void Update();
};
