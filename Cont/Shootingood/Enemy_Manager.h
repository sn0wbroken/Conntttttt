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
	std::shared_ptr<Enemy_Status> enemy_status = std::make_shared<Enemy_Status>();
	// エネミーのAIを管理
	std::shared_ptr<Enemy_AI> enemy_AI = std::make_shared<Enemy_AI>();

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

	// x座標
	int x;
	// y 座標
	int y;

	// 出現する敵を配置
	void Arrange(int set_x, int set_y);

	// 定数をまとめておく構造体
	Define_Value define_value;

	// 引数に自身を指定したものだけに生成をゆるす
	friend class Unique_Component<Enemy_Manager>;
};
