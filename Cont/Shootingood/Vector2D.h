#pragma once

// 座標関係を扱うクラス(2D)
template <typename T>
class Vector2D {
public:
	// コンストラクタ
	Vector2D();
	// デストラクタ
	~Vector2D();

	// 移動
	void Move(T set_x,T set_y);
	// 配置
	void Arrange(T set_x, T set_y);

	// x座標
	T x;
	// y座標
	T y;
};

