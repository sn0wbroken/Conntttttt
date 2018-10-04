#pragma once

#include"DxLib.h"
#include"Define_Value.h"

// アクターが打ち出す弾丸
class Bullet {
public:
	// コンストラクタ
	Bullet(int set_x, int set_y, int set_direction_x, int set_direction_y);
	// デストラクタ
	~Bullet();

	// 毎フレーム呼ばれる
	void Update();
	// 描画
	void Render();

	// x座標を返す
	int Get_X();
	// y座標を返す
	int Get_Y();
	// 半径を返す
	int Get_Radius();

	// 弾の移動
	void Move(int x, int y);

	// 画面下部から出ようとしていないか
	bool Is_Over_Max_Y();
	// 画面上部から出ようとしていないか
	bool Is_Over_Min_Y();

private:
	// x座標
	int x;
	// y座標
	int y;
	// 弾の半径
	int radius;
	// 弾の飛んでいく方向x
	int direction_x;
	// 弾の飛んでいく方向y
	int direction_y;

	// 定数をまとめておく構造体
	Define_Value define_value;
};
