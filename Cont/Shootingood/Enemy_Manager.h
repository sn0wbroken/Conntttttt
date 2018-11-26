#pragma once

#include"Enemy.h"
#include"Enemy_AI.h"
#include"Enemy_Status.h"
#include"Define_Value.h"
#include"Unique_Component.h"

#include<memory>
#include<vector>

// エネミーのマネージャークラス(エネミーの情報(各クラス)を知っておく)
class Enemy_Manager : public  Unique_Component<Enemy_Manager> {
public:
	// エネミーのステータス関係を扱うクラス
	std::shared_ptr<Enemy_Status> enemy_status;
	// エネミーのAIを管理	
	std::shared_ptr<Enemy_AI> enemy_AI;

	// 毎フレーム呼ばれる
	void Update();

	// エネミーを配置
	void Enemy_Arrange();

	// エネミーが全滅したかどうか
	bool Is_Enemy_All_Ded();

	// デストラクタ
	~Enemy_Manager() {}

private:
	// コンストラクタ
	Enemy_Manager();

	// 定数をまとめておくクラス
	Define_Value define_value;

	// 引数に自身を指定したものだけに生成をゆるす
	friend class Unique_Component<Enemy_Manager>;
};
