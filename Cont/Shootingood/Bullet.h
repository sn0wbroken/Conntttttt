#pragma once

#include"DxLib.h"
#include"Actor.h"
#include"Vector3D.h"
#include"Define_Value.h"

// アクターが打ち出す弾丸
class Bullet : public Actor {
public:
	// コンストラクタ
	Bullet();
	// デストラクタ
	~Bullet();

	// 毎フレーム呼ばれる
	void Update() override;
	// 描画
	void Render() override;

	// x座標を返す
	float Get_X();
	// x座標を設定する
	void Set_X(float set_x);
	// y座標を返す
	float Get_Y();
	// y座標を設定する
	void Set_Y(float set_y);
	// z座標を返す
	float Get_Z();
	// z座標を設定する
	void Set_Z(float set_z);
	// 半径を返す
	int Get_Radius();

	// 弾の移動
	void Move(float x = 0.0f, float y = 0.0f, float z = 0.0f);
	// 飛んでいく角度を設定する
	void Set_Radian(float set_radian);
	// 飛んでいく速度を設定する
	void Set_Speed(float set_speed);

private:
	// 弾の半径
	int radius;
	// 飛んでいく角度
	float radian;
	// 飛んでいく速度
	float speed;

	//弾の進む方向
	Vector3D Direction;
	
	// 画面右端から出ようとしてないか
	bool Is_Over_Max_X();
	// 画面下端から出ようとしていないか
	bool Is_Over_Max_Y();
	// 画面上端から出ようとしていないか
	bool Is_Over_Min_X();
	// 画面左端から出ようとしてないか
	bool Is_Over_Min_Y();
	// 弾丸が表示範囲外に出ているかを判断
	bool Bullet_Off_Screen();
};
