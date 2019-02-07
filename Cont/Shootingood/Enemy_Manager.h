#pragma once

#include"Enemy_Controller.h"
#include"Enemy.h"
#include"Enemy_AI.h"
#include"Enemy_Status.h"
#include"Define_Value.h"
#include"Unique_Component.h"

#include<memory>
#include<vector>

class Effect_Info
{
public:
	Effect_Info(Vector3D t_pos, int sec)
	{
		pos = t_pos;
		effect_sec = sec;
	}

	bool operator==(const Effect_Info& Ei)
	{
		if (pos == Ei.pos)
		{
			if (Ei.effect_sec == effect_sec)
			{
				return true;
			}
		}
		return false;
	}

	Vector3D pos;
	int		 effect_sec;
};

// エネミーのマネージャークラス(エネミーの情報(各クラス)を知っておく)
class Enemy_Manager : public Unique_Component<Enemy_Manager> {
public:
	//エネミーのコントローラー ここから動きを制御する
	std::shared_ptr<Enemy_Controller> enemy_controller;
	std::list<std::shared_ptr<Enemy>> active_enemies;
	std::list<std::shared_ptr<Enemy>> inactive_enemies;

	// 毎フレーム呼ばれる
	void Update();

	// エネミーが全滅したかどうか
	bool Is_Enemy_All_Dead();

	// デストラクタ
	~Enemy_Manager() {}

	// 座標
	Vector3D position;

	void PlayEffect();

private:
	// コンストラクタ
	Enemy_Manager();

	int e_explosionhandle[7];

	// 定数をまとめておくクラス
	Define_Value define_value;

	// 引数に自身を指定したものだけに生成をゆるす
	friend class Unique_Component<Enemy_Manager>;

	std::list<Effect_Info> active_effectList;
};
