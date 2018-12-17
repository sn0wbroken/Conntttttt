#pragma once

#include"DxLib.h"
#include"Rect.h"
#include"Bullet.h"
#include"Character.h"
#include"Enemy_Status.h"

#include<map>
#include<vector>

// エネミー本体のクラス
class Enemy : public Character{
public:
	// コンストラクタ
	Enemy();
	// コピーコンストラクタ
	Enemy(Vector3D position);
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
	// 被せる区画(当たり判定に使用)
	std::map<std::string, Rect*> rects;
};
