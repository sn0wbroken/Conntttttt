#pragma once

// 座標関係を扱うクラス
class Vector3D {
public:
	// コンストラクタ
	Vector3D();
	// デストラクタ
	~Vector3D();

	// x座標
	float x;
	// y座標
	float y;
	// z座標
	float z;

	DxLib::VECTOR GetVECTOR();

	// 移動
	void Move(float set_x, float set_y, float set_z);
	// 配置
	void Arrange(float set_x = 0.0f, float set_y = 0.0f, float set_z = 0.0f);
};

