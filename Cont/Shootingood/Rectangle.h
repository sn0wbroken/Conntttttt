#pragma once

#include"Vector3D.h"

// 矩形を扱うクラス
class Rectangle {
public:
	// コンストラクタ
	Rectangle();
	// デストラクタ
	~Rectangle() {};

	// 四角形の左上隅の座標
	Vector3D top_left;
	// 四角形の右上隅の座標
	Vector3D top_right;
	// 四角形の右下隅の座標
	Vector3D bottom_right;
	// 四角形の左下隅の座標
	Vector3D bottom_left;

	// 法線ベクトル。線分との判定に使う
	Vector3D normal_vector;

	// 面の中心座標を返す
	Vector3D Get_Centor_Point(float width, float height, Vector3D top_right);

	// 幅
	float width;
	// 高さ
	float height;
};
