#pragma once

#include"Actor.h"
#include"Enemy_Manager.h"
#include"Player_Manager.h"

// 当たり判定を行う
class Collision : public Actor {
public:
	// コンストラクタ
	Collision();
	// デストラクタ
	~Collision() {};

	// 計算式を利用する
	Vector3D calculator;

	// 毎フレーム呼ばれる更新処理
	void Update() override;

	// プレイヤーからエネミーまでの距離を求めて返す
	float Get_Distance_Player_To_Enemy(std::shared_ptr<Enemy> enemy);

	// 線分と平面の当たり判定
	bool Line_To_Face(std::shared_ptr<Enemy> enemy, Vector3D normal_vector);
};
