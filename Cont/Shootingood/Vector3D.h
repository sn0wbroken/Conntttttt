#pragma once

#include "DxLib.h"

// 座標関係を扱うクラス
class Vector3D {
public:
	// コンストラクタ
	Vector3D();
	// コピーコンストラクタ
	Vector3D(const Vector3D &vec);
	// コピーコンストラクタ
	Vector3D(const VECTOR &vec);
	// デストラクタ
	~Vector3D();

	// x座標
	float x;
	// y座標
	float y;
	// z座標
	float z;
	// DxlibのVECTORを使う(Dxlibの機能でこの型を扱うものが多い為合わせる)
	VECTOR GetVECTOR();

	// 移動
	void Move(float set_x, float set_y, float set_z);
	// 値をセットする
	void Set_Vector(float set_x = 0.0f, float set_y = 0.0f, float set_z = 0.0f);
	// ノルム　ベクトルの長さ計算
	void Norm2() const;
};
