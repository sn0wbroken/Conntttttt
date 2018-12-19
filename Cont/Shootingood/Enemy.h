#pragma once

#include"DxLib.h"
#include"Rect.h"
#include"Bullet.h"
#include"Character.h"
#include"Enemy_Status.h"

#include<map>
#include<vector>

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

	//TEST
	void RENDER();

private:
	// 角度(度数法)
	float degree;
	// 角度(弧度法)
	float radian;

	// 打ち出す弾の速度
	int bullet_speed;
	// エネミーの前方向の当たり判定の座標(プレイヤーの通常攻撃の当たり判定に使用)
	Vector3D flont_face_position;
	// 被せる区画(当たり判定に使用)
	std::map<std::string, Rect*> rects;

	//TEST
	// モデルの原点からキャラクターの向きを基準に左端までの幅
	float width_1;
	// モデルの原点からキャラクターの向きを基準に右端までの幅
	float width_2;
	// モデルの原点からキャラクターの向きを基準に上端までの高さ
	float height_1;
	// モデルの原点からキャラクターの向きを基準に奥の端までの奥行
	float depth_1;
	// モデルの原点からキャラクターの向きを基準に手前の端までの奥行
	float depth_2;
};
