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

	// 当たり判定に使用する矩形を生成する
	void Set_Rects();

	//TEST
	void RENDER();
	// 被せる矩形(当たり判定に使用)
	std::unordered_map<std::string, Rect> rects;

	//ラジアンを設定
	void set_radian(Vector3D set_playerpos) {

		radian = Vector3D::MoveOnAngleOfElevation(set_playerpos, vector3d);
		MV1SetRotationXYZ(model_handle, VGet(0, Vector3D::RotateOnAngleOfElevation(set_playerpos, vector3d), 0));
	}
	//角度を取得
	inline float get_degree()
	{
		return degree;
	}
	//ラジアンを取得
	inline float get_radian()
	{
		return radian;
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
