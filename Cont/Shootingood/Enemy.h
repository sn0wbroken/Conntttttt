#pragma once

#include"DxLib.h"
#include"Rect.h"
#include"Bullet.h"
#include"Enemy_Status.h"
#include"Enemy_Controller.h"

#include<map>
#include<vector>
#include<memory>

// エネミー本体のクラス
class Enemy : public Enemy_Controller {
public:
	// コンストラクタ
	Enemy();
	// コピーコンストラクタ
	Enemy(Vector3D position);
	// デストラクタ
	~Enemy();

	// エネミーのステータス関係のクラス
	std::shared_ptr<Enemy_Status> enemy_status;

	// 被せる区画(当たり判定に使用)
	std::map<std::string, Rect*> rects;
};
