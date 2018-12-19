#pragma once

#include"DxLib.h"
#include<numeric>

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
	// DxlibのVECTORを使う(Dxlibの機能でこの型を扱うものが多い為合わせる)
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

	inline const Vector3D operator*(const float& flt) const
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
	inline operator DxLib::VECTOR() const
	{
		return DxLib::VGet(x, y, z);
	}
#pragma endregion

#pragma region Math
	//ベクトルレングス
	static Vector3D VectorLength(Vector3D vector)
	{
		Vector3D tmp;

		tmp.x = vector.x * vector.x;
		tmp.y = vector.y * vector.y;
		tmp.z = vector.z * vector.z;

		return tmp;
	}
	// ノルムを返す
	static double Norm(double x, double y, double z = 0) {
		return sqrt(pow(x, 2) + pow(y , 2) + pow(x, 2));
	}

	// 2点間の距離を求める(3次元用)
	static float Norm_3D(float x1, float y1, float z1, float x2, float y2, float z2) {
		return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2));
	}

	//平方根計算（バビロニア人メソッド）
	static double sqrt(double s)
	{
		double tmp_x = s / 2.0; // Is there any better way to determine initial value?
		double last_x = 0.0; // the value one before the last step

		while (tmp_x != last_x) // until the difference is not significant
		{ // apply Babylonian method step
			last_x = tmp_x;
			tmp_x = (tmp_x + s / tmp_x) / 2.0;
		}

		return tmp_x;
	}
	//ベクトルのノーマライズ
	static Vector3D normalize(Vector3D vector)
	{
		float mag = 1 / Norm(vector.x, vector.y);
		float _x = vector.x * mag;
		float _y = vector.y * mag;

		return Vector3D(VGet(_x, _y, 0));
	}
	//内積計算
	static Vector3D dot(Vector3D vector,Vector3D vector2)
	{
		float a[] = { vector.x,vector.y,vector.z };
		float b[] = { vector2.x,vector2.y,vector2.z };
		//スタンダードライブラリの内積計算
		std::inner_product(a, a + sizeof(a) / sizeof(a[0]), b, 0);

		return Vector3D();
	}
	//クロス積計算
	static Vector3D cross(Vector3D vector,Vector3D vector2)
	{
		Vector3D TempVector;
		TempVector.x = vector.y * vector2.z - vector.z * vector2.y;
		TempVector.y = vector.x * vector2.z - vector.z * vector2.x;
		TempVector.z = vector.x * vector2.y - vector.y * vector2.x;

		return TempVector;
	}
#pragma endregion
	// 値をセットする
	void Set_Vector(float set_x = 0.0f, float set_y = 0.0f, float set_z = 0.0f);
	// ノルム　ベクトルの長さ計算
	//void Norm2() const;
};
