#pragma once

#include"Rect.h"
#include"Actor.h"
#include"DxLib.h"
#include"Vector3D.h"
#include"Object_Size.h"
#include"Define_Value.h"

// アクターの基底のクラス
class Character : public Actor {
public:
	// コンストラクタ
	Character();
	// デストラクタ
	virtual ~Character() {};

	// 現在のx座標を返す
	float Get_X();
	// x座標を設定する
	void Set_X(float set_x);
	// 現在のy座標を返す
	float Get_Y();
	// y座標を設定する
	void Set_Y(float set_y);
	//現在のz座標を返す
	float Get_Z();
	//z座標を設定する
	void Set_Z(float set_z);

	// 出現位置を設定する
	void Set_Arrange_Poisition(float set_x, float set_y, float set_z);
	// 座標を設定する
	void Set_Position(Vector3D set_ecor3);
	// 座標を返す
	Vector3D Get_Position();

	// 大きさを返す
	Object_Size Get_Size();

	// アクターの右端の座標を返す
	float Get_Right_Edge();
	// アクターの左端の座標を返す
	float Get_Left_Edge();
	// アクターの上端の座標を返す
	float Get_Top_Edge();
	// アクターの下端の座標を返す
	float Get_Bottom_Edge();
	
	// アクターのモデルハンドルを返す
	int &Get_Model_Handle();

protected:
	// 自分の中心の座標
	Vector3D center_position;

	// 定数をまとめておくクラス
	Define_Value define_value;

	// 自身のインスタンスを保持
	std::shared_ptr<Character> character;

	// モデルのハンドル
	int model_handle;

	// 死亡判定 trueで死亡
	bool is_dead;
	
	// アクターオブジェクトを生成する
	void Create_Actor(TCHAR* model_path) override;

	// 描画を行う
	void Render() override;

	// 矩形の作成に使用
	Rect rect;
	
	// 大きさをまとめて保持
	Object_Size size;
};