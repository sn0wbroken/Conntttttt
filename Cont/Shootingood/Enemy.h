#pragma once

#include"DxLib.h"
#include"Rect.h"
#include"Bullet.h"
#include"Character.h"
#include"Enemy_Status.h"

#include<vector>
#include<unordered_map>

// エネミー本体のクラス
class Enemy : public Character {
public:
	// コンストラクタ
	Enemy();
	// コピーコンストラクタ
	Enemy(Vector3D position, float set_degree);
	// デストラクタ
	~Enemy();

	// エネミーのステータス関係のクラス
	std::shared_ptr<Enemy_Status> enemy_status;

	// 当たり判定に使用する矩形を生成する
	void Set_Rects();

	//TEST
	void RENDER();
	// 被せる矩形(当たり判定に使用)
	std::unordered_map<std::string, Rect> rects;

	//角度を設定
	void set_degree(float t_degree) {
		degree = t_degree;
	}
private:
	// 角度(度数法)
	float degree;
	// 角度(弧度法)
	float radian;

	// 打ち出す弾の速度
	int bullet_speed;
	// エネミーの前方向の当たり判定の座標(プレイヤーの通常攻撃の当たり判定に使用)
	Vector3D flont_face_position;
};
