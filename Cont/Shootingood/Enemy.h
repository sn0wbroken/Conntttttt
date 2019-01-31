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

	// 被せる矩形(当たり判定に使用)
	std::unordered_map<std::string, Rect> rects;

	//TODO:箱と向きのずれはこれで直るかも…？一応取っておく
	//// モデルのではなく、当たり判定用の箱の中心座標を返す
	//Vector3D Get_Collition_Center();

	// ラジアンを設定
	void Set_Radian(Vector3D set_playerpos);

	// 角度を取得
	float Get_Degree();
	// ラジアンを取得
	float Get_Radian();

	void Set_Vector3D(Vector3D vector);

	//アニメーションの現在の時間
	float Anim_CurrentFrame;
	//アニメーションの現在の時間を増やし、モデルの動きをセットする。 
	void Add_WalkAnimIndex();

private:
	// 角度(度数法)
	float degree;
	// 角度(弧度法)
	float radian;

	//歩くアニメーションのハンドル
	int walk_animhandle;

	// 打ち出す弾の速度
	int bullet_speed;
	// エネミーの前方向の当たり判定の座標(プレイヤーの通常攻撃の当たり判定に使用)
	Vector3D flont_face_position;
	
	// 当たり判定用の箱の中心
	Vector3D collision_centor;
	// モデルではなく、当たり判定に使う箱の中心座標を設定
	void Set_Collision_Centor(std::unordered_map<std::string, Rect> rects);
};
