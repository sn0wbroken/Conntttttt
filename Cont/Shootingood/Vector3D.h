#pragma once

#include"DxLib.h"

#include<numeric>
#include<cmath>

// 座標関係を扱うクラス
class Vector3D {
public:
	// コンストラクタ
	Vector3D();
	// コピーコンストラクタ
	Vector3D(float x,float y,float z=0);
	// コピーコンストラクタ
	Vector3D(const Vector3D &vec);
	// コピーコンストラクタ
	Vector3D(const VECTOR &vec);
	// デストラクタ
	~Vector3D();

	// DxlibのVECTORを使う(Dxlibの機能でこの型を扱うものが多い為合わせる)
	VECTOR GetVECTOR();
	// 引数の要素を自作のVector3D型にして返す
	Vector3D Get_Vector(float set_x, float set_y, float set_z);
	// X座標を返す
	float Get_X();
	// Y座標を返す
	float Get_Y();
	// Z座標を返す
	float Get_Z();
	// 値をセットする
	void Set_Vector(float set_x = 0.0f, float set_y = 0.0f, float set_z = 0.0f);

	// 移動
	void Move(float set_x, float set_y, float set_z);

	// X座標に引数の値を加算したVectorを返す
	Vector3D Add_VectorX(float add_value);
	// Y座標に引数の値を加算したVectorを返す
	Vector3D Add_VectorY(float add_value);
	// Z座標に引数の値を加算したVectorを返す
	Vector3D Add_VectorZ(float add_value);
	// X座標に引数の値を減算したVectorを返す
	Vector3D Subtract_VectorX(float add_value);
	// Y座標に引数の値を減算したVectorを返す
	Vector3D Subtract_VectorY(float add_value);
	// Z座標に引数の値を減算したVectorを返す
	Vector3D Subtract_VectorZ(float add_value);
	
	// X座標に引数の値を加算した数値を返す
	float Add_X(float add_value);
	// Y座標に引数の値を加算した数値を返す
	float Add_Y(float add_value);
	// Z座標に引数の値を加算した数値を返す
	float Add_Z(float add_value);
	// X座標に引数の値を減算した数値を返す
	float Subtract_X(float add_value);
	// Y座標に引数の値を減算した数値を返す
	float Subtract_Y(float add_value);
	// Z座標に引数の値を減算した数値を返す
	float Subtract_Z(float add_value);

	// x座標
	float x;
	// y座標
	float y;
	// z座標
	float z;

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

	inline bool operator==(const Vector3D& vec)
	{
		if (x == vec.x)
		{
			if (y == vec.y)
			{
				if (z == vec.z)
				{
					return true;
				}
			}
		}
		return false;
	}

	// DxLibのVector変換
	inline operator DxLib::VECTOR() const
	{
		return DxLib::VGet(x, y, z);
	}
#pragma endregion

#pragma region Math
	// ベクトルレングス
	static Vector3D VectorLength(Vector3D vector) {
		Vector3D tmp;

		tmp.x = vector.x * vector.x;
		tmp.y = vector.y * vector.y;
		tmp.z = vector.z * vector.z;

		return tmp;
	}
	// ノルムを返す
	static float Norm(float x, float y, float z = 0) {
		return sqrt(pow(x, 2) + pow(y , 2) + pow(z, 2));
	}

	// 2点からベクトルを生成　第1引数が引かれる値
	static Vector3D Make_Vector(Vector3D point1, Vector3D point2) {
		return point1.operator-(point2);
	}

	// 2点間の距離を求める(3次元用)
	static float Norm_3D(float x1, float y1, float z1, float x2, float y2, float z2) {
		return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2));
	}

	// 平方根計算（バビロニア人メソッド）
	static float sqrt(float s) {
		float tmp_x = s / 2.0f; // Is there any better way to determine initial value?
		float last_x = 0.0; // the value one before the last step

		while (tmp_x != last_x) // until the difference is not significant
		{ // apply Babylonian method step
			last_x = tmp_x;
			tmp_x = static_cast<float>((tmp_x + s / tmp_x) / 2.0);
		}

		return tmp_x;
	}
	// ベクトルのノーマライズ
	static Vector3D normalize(Vector3D vector) {
		float mag = 1 / Norm(vector.x, vector.y);
		float _x = vector.x * mag;
		float _y = vector.y * mag;

		return Vector3D(VGet(_x, _y, 0));
	}
	//内積計算
	static float Dot(Vector3D vector,Vector3D vector2)
	{
		//スタンダードライブラリの内積計算からDXライブラリの内積計算に変更
		float result = DxLib::VDot(vector, vector2);

		return result;
	}
	// 外積計算
	static Vector3D Cross(Vector3D vector1 ,Vector3D vector2) {
		Vector3D result;
		result.x = vector1.y * vector2.z - vector1.z * vector2.y;
		result.y = vector1.x * vector2.z - vector1.z * vector2.x;
		result.z = vector1.x * vector2.y - vector1.y * vector2.x;

		return result;
	}
	// スカラー3重積
	static Vector3D Scalar_Triple(Vector3D vector1, Vector3D vector2, Vector3D vector3) {
		Vector3D result;
		auto vec1 = vector1.operator*(vector3);
		auto vec2 = vector2.operator*(vector3);

		return result = vec1.operator*(vec2);
	};
	// 仰角を計算する　返り値はラジアンを返す。
	static float AngleOfElevation(Vector3D vector, Vector3D vector2) {
		const double px = static_cast<double> (vector.x - vector2.x);
		const double pz = static_cast<double> (vector.z - vector2.z);
		return static_cast<float> (std::atan2(pz, px));
	}
#pragma endregion
};
