#pragma once

#include "DxLib.h"

// 座標関係を扱うクラス
class Vector3D {
public:
	// コンストラクタ
	Vector3D();
	//コンストラクタ
	Vector3D(float x,float y,float z=0);
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
	// DxlibのVECTORを使う
	VECTOR GetVECTOR();

	// 移動
	void Move(float set_x, float set_y, float set_z);
	// 配置
	void Arrange(float set_x = 0.0f, float set_y = 0.0f, float set_z = 0.0f);
#pragma region operator
	//単体演算子
	inline const Vector3D operator+(const Vector3D& vec)const
	{
		Vector3D tmp;
		tmp.x = x + vec.x;
		tmp.y = y + vec.y;
		tmp.z = z + vec.z;
		return tmp;
	}

	inline const Vector3D operator-(const Vector3D& vec)const
	{
		Vector3D tmp;
		tmp.x = x - vec.x;
		tmp.y = y - vec.y;
		tmp.z = z - vec.z;
		return tmp;
	}

	inline const Vector3D operator*(const Vector3D& vec) const
	{
		Vector3D tmp;
		tmp.x = x * vec.x;
		tmp.y = y * vec.y;
		tmp.z = z * vec.z;
		return tmp;
	}

	inline const Vector3D operator*(const float& flt)
	{
		Vector3D tmp;
		tmp.x = x * flt;
		tmp.y = y * flt;
		tmp.z = z * flt;
		return tmp;
	}

	inline const Vector3D operator/(const Vector3D& vec)const
	{
		Vector3D tmp;
		tmp.x = x / vec.x;
		tmp.y = y / vec.y;
		tmp.z = z / vec.z;
		return tmp;
	}
	// 演算子+イコール系
	inline Vector3D operator+=(const Vector3D& vec)
	{
		x += vec.x;
		y += vec.y;
		z += vec.z;
		return *this;
	}
	//DxLibのVector変換
	inline operator DxLib::VECTOR() const throw
	{
		return DxLib::VGet(x, y, z);
	}
#pragma endregion
};
