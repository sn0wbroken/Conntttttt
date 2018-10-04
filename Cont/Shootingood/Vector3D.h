#pragma once

// 座標関係を扱うクラス(3D)
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

	// 移動
	void Move(float set_x, float set_y, float set_z);
	// 配置
	void Arrange(float set_x, float set_y, float set_z);
};

