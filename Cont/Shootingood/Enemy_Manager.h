#pragma once

#include"Enemy.h"
#include"Enemy_AI.h"
#include"Enemy_Status.h"
#include"Define_Value.h"
#include"Unique_Component.h"

#include<memory>
#include<vector>

// エネミーのマネージャークラス
class Enemy_Manager : public  Unique_Component<Enemy_Manager> {
public:
	// エネミーのステータス関係を扱うクラス
	std::shared_ptr<Enemy_Status> enemy_status;
	// エネミーのAIを管理	
	std::shared_ptr<Enemy_AI> enemy_AI;

	// 初期化
	void Initialize();

	// 毎フレーム呼ばれる
	void Update();
	// 描画
	void Render();

	// エネミーを配置
	void Enemy_Arrange();
	// エネミーを元の位置に配置しなおす
	void Reset_Enemy();

	// 画面上で動く敵
	std::vector<Enemy> enemies;

	// エネミーが撃つ弾
	std::vector<Bullet> enemy_bullet;

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
