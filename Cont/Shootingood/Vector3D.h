#pragma once

// 座標関係を扱うクラス(3D)
template <typename T>
class Vector3D {
public:
	// コンストラクタ
	Vector3D();
	// デストラクタ
	~Vector3D();

	// x座標
	T x;
	// y座標
	T y;
	// z座標
	T z;

	// 移動
	void Move(T set_x, T set_y, T set_z);
	// 配置
	void Arrange(T set_x, T set_y, T set_z);
};

