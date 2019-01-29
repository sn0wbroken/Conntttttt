#pragma once

#include"Actor.h"
#include"Enemy_Manager.h"
#include"Player_Manager.h"

#include<cmath>

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

	// 引数の2点間の距離を求めて返す
	float Get_Distance(Vector3D coordinates_1, Vector3D coordinates_2);

private:
	// 線分と平面の交点を求める
	Vector3D Get_Intersection(Vector3D vector1, Vector3D vector2, Vector3D start_point, Vector3D end_point, Rect face);

	// 通常攻撃を行ったときにエネミーにヒットしたかを調べる
	bool Nomal_Attack_To_Enemy(std::shared_ptr<Enemy> enemy);
	// 点が面に内接しているかを調べる。同一平面上にあることが前提
	bool Point_To_Rectangle(Vector3D start_point, Vector3D end_position, Vector3D normal_vector, Rect face);

	// 距離で見る当たり判定。距離が判定の値より短いと当たっている
	bool Distance_Collition(float distance, float judge_value);

	// プレイヤーとエネミーの当たり判定。距離で行う
	bool Player_To_Enemy(std::shared_ptr<Player> player, std::shared_ptr<Enemy> enemy);
};
