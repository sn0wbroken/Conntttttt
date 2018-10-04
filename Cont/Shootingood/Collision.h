#pragma once

// 当たり判定を行う
class Collision {
public:
	// コンストラクタ
	Collision() {};
	// デストラクタ
	~Collision() {};

	// アクター同士での当たり判定
	bool Box_To_Box(int right_edge1, int left_edge1, int top_edge1, int right_edge2, int left_edge2, int bottom_edge2);

	// プレイヤーとエネミーの弾の当たり判定
	bool Player_To_Enemy_Bullet(int right_edge, int left_edge, int top_edge, int bottom_edge, int bullet_position_x, int bullet_position_y, int bullet_radius);

	// エネミーとプレイヤーの弾の当たり判定
	bool Enemy_To_Player_Bullet(int right_edge, int left_edge, int top_edge, int bottom_edge, int bullet_position_x, int bullet_position_y, int bullet_radius);
};

