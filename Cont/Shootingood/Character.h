#pragma once

#include"Actor.h"
#include"DxLib.h"
#include"Vector3D.h"
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
	// 幅を返す
	int Get_Width();
	// 高さを返す
	int Get_Height();

	Vector3D Get_Vector3D() {
		return vector3d;
	}

	// 出現位置を設定する
	void Set_Arrange_Poisition(float set_x, float set_y, float set_z);
	// vectorを設定する
	void Set_Vector3D(Vector3D Vec3);

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
	// 自分のちゅうしｎの座標
	Vector3D center_position;

	// 定数をまとめておくクラス
	Define_Value define_value;

	// 自身のインスタンスを保持
	std::shared_ptr<Character> character;

	// モデルのハンドル
	int model_handle;

	// アクターの大きさ(幅)
	int width;
	// アクターの大きさ(高さ)
	int height;

	// 死亡判定 trueで死亡
	bool is_dead;
	
	// アクターオブジェクトを生成する
	void Create_Actor(TCHAR* model_path) override;
	// 描画を行う
	void Render() override;
};