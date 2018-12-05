#pragma once

#include"DxLib.h"
#include"Bullet.h"
#include"Enemy_Status.h"
#include"Enemy_Controller.h"
#include"Enemy_AI.h"

#include<vector>
#include<memory>

// エネミー本体のクラス
class Enemy : public Enemy_Controller {
public:
	// コンストラクタ
	Enemy();
	// コピーコンストラクタ
	Enemy(float set_x, float set_y);
	// デストラクタ
	~Enemy();

	// エネミーのステータス関係のクラス
	std::shared_ptr<Enemy_Status> enemy_status;

private:
	
	// エネミーの画像
	int enemy_graph;
	// 攻撃を受けているときのエネミーの画像
	int damage_enemy_graph;
	// 打ち出す弾の速度
	int bullet_speed;
};
