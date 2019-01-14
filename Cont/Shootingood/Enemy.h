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
	Enemy(Vector3D position, Vector3D set_playerpos);
	// デストラクタ
	~Enemy();

	// エネミーのステータス関係のクラス
	std::shared_ptr<Enemy_Status> enemy_status;

	// 被せる矩形(当たり判定に使用) TODO:キーに難あり 左面、右面では合わない
	std::unordered_map<std::string, Rect> rects;

<<<<<<< Updated upstream
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

=======
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


	int anim_handle;
	float Anim_CurrentFrame;
	//現在のフレームを増やす
	float AddAnimIndex()
	{
		Anim_CurrentFrame++;
		if (Anim_CurrentFrame >= MV1GetAttachAnimTotalTime(model_handle,anim_handle))//TODO::MAGICNUMBER
		{
			Anim_CurrentFrame = 1; //TODO::MAGICNUMBER
		}
		return Anim_CurrentFrame;
	}
>>>>>>> Stashed changes
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
