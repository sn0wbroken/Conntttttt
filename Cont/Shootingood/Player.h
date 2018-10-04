#pragma once

#include"Actor.h"
#include"Bullet.h"

#include<vector>

// プレイヤー本体のクラス
class Player : public Actor{
public:
	// コンストラクタ
	Player();
	// デストラクタ
	~Player();

	// 初期化
	void Initialize();

	// プレイヤーを描画
	void Render() override;

	// アクターの右端の座標を返す
	virtual int Get_Right_Edge() override;
	// アクターの左端の座標を返す
	virtual int Get_Left_Edge() override;
	// アクターの上端の座標を返す
	virtual int Get_Top_Edge() override;
	// アクターの下端の座標を返す
	virtual int Get_Bottom_Edge() override;

	// 弾が出る位置を返す
	int Get_Shoot_Point();

	// パワーアップ状態であるかをセットする
	void Set_Power_Up(bool set_is_power_up);
	// パワーアップ状態であるかを返す
	bool Get_Power_Up();

	// プレイヤーが撃つ弾
	std::vector<Bullet> player_bullet;

private:
	// 画像データ
	int player_graph;

	// 死亡判定。死んでいたらtrue
	bool is_dead;

	// パワーアップ状態か
	bool is_power_up;
};
