#pragma once

#include"DxLib.h"
#include"Vector3D.h"
#include"Define_Value.h"

// アクターの基底のクラス
class Actor {
public:
	// コンストラクタ
	Actor() {};
	// デストラクタ
	virtual ~Actor() {};

	// アクターを描画
	virtual void Render() = 0;

	// 現在のx座標を返す
	float Get_X();
	// x座標を設定する
	void Set_X(float set_x);
	// 現在のy座標を返す
	float Get_Y();
	// y座標を設定する
	void Set_Y(float set_y);
	// 幅を返す
	int Get_Width();
	// 高さを返す
	int Get_Height();

	Vector3D* Get_Vector3D() {
		return vector3;
	}
	
	// アクターの右端の座標を返す
	virtual int Get_Right_Edge() = 0;
	// アクターの左端の座標を返す
	virtual int Get_Left_Edge() = 0;
	// アクターの上端の座標を返す
	virtual int Get_Top_Edge() = 0;
	// アクターの下端の座標を返す
	virtual int Get_Bottom_Edge() = 0;

protected:
	// 座標関係のクラス
	Vector3D* vector3;// = new Vector3D();

	// 定数をまとめておく構造体
	Define_Value define_value;

	// アクターの大きさ(幅)
	int width;
	// アクターの大きさ(高さ)
	int height;

	// 死亡判定 trueで死亡
	bool is_dead;
};