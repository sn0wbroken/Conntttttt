#pragma once

#include"Enemy_Controller.h"
#include"Enemy.h"
#include"Enemy_AI.h"
#include"Enemy_Status.h"
#include"Define_Value.h"
#include"Unique_Component.h"

#include<memory>
#include<vector>

// エネミーのマネージャークラス(エネミーの情報(各クラス)を知っておく)
class Enemy_Manager : public Unique_Component<Enemy_Manager> {
public:
	//エネミーのコントローラー ここから動きを制御する
	std::shared_ptr<Enemy_Controller> enemy_controller;
	std::list<std::shared_ptr<Enemy>> active_enemies;
	std::list<std::shared_ptr<Enemy>> inactive_enemies;

	// 毎フレーム呼ばれる
	void Update();

	// エネミーが全滅したかどうか
	bool Is_Enemy_All_Dead();

	// デストラクタ
	~Enemy_Manager() {}

	// 座標
	Vector3D position;

private:
	// コンストラクタ
	Enemy_Manager();

	// 定数をまとめておくクラス
	Define_Value define_value;

	// 引数に自身を指定したものだけに生成をゆるす
	friend class Unique_Component<Enemy_Manager>;
};
