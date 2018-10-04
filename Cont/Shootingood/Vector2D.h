#pragma once

// 座標関係を扱うクラス(2D)
class Vector2D {
public:
	// コンストラクタ
	Vector2D();
	// デストラクタ
	~Vector2D();

	// 移動
	void Move(float set_x, float set_y);
	// 配置
	void Arrange(float set_x, float set_y);

	// x座標
	float x;
	// y座標
	float y;
};

