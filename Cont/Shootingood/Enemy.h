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
	// コンストラクタ
	Enemy(Vector3D position,Vector3D set_playerpos);
	// デストラクタ
	~Enemy();

	// エネミーのステータス関係のクラス
	std::shared_ptr<Enemy_Status> enemy_status;

	// 被せる矩形(当たり判定に使用) TODO:キーに難あり 左面、右面では合わない
	std::unordered_map<std::string, Rect> rects;

	//TEST 合ってたらSetはプライベート
	// 当たり判定用の箱の中心
	Vector3D collision_centor;
	void Set_Collision_Centor(std::unordered_map<std::string, Rect> rects);

	// ラジアンを設定
	void Set_Radian(Vector3D set_playerpos);

	// 角度を取得
	inline float Get_Degree();
	// ラジアンを取得
	inline float Get_Radian();

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
