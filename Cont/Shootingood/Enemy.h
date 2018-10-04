#pragma once

#include"DxLib.h"
#include"Actor.h"
#include"Bullet.h"
#include"Enemy_Status.h"

#include<vector>
#include<memory>

// エネミー本体のクラス
class Enemy : public Actor {
public:
	// コンストラクタ
	Enemy() {};
	// コピーコンストラクタ
	Enemy(int set_x, int set_y);
	// デストラクタ
	~Enemy();

	// エネミーを描画
	void Render() override;

	// エネミーの右端の座標を返す
	int Get_Right_Edge() override;
	// エネミーの左端の座標を返す
	int Get_Left_Edge() override;
	// エネミーの上端の座標を返す
	int Get_Top_Edge() override;
	// エネミーの下端の座標を返す
	int Get_Bottom_Edge() override;
	// 弾の発射する位置を返す
	int Get_Shot_Point();
	// 初期x座標を返す
	int Get_Initialize_Position_X();
	// 初期y座標を返す
	int Get_Initialize_Position_Y();

	// エネミーのステータス関係のクラス
	std::shared_ptr<Enemy_Status> enemy_status;

private:
	// 初期x座標を覚えておく
	int initialize_position_x;
	// 初期y座標を覚えておく
	int initialize_position_y;

	// エネミーの画像
	int enemy_graph;
	// 攻撃を受けているときのエネミーの画像
	int damage_enemy_graph;
	// 打ち出す弾の速度
	int bullet_speed;
};
