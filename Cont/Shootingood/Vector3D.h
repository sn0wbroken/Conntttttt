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
<<<<<<< Updated upstream
	// ベクトルの長さを返す
	static float Norm(float x, float y) {
		return sqrt(pow(x, 2) + pow(y , 2) + pow(x, 2));
=======
	// ノルムを返す
	static float Norm(float x, float y, float z = 0) {
		return sqrt(pow(x, 2) + pow(y , 2) + pow(z, 2));
>>>>>>> Stashed changes
	}

	// 2点からベクトルを生成 point1を減算するため　point1 > point2になるように
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
<<<<<<< Updated upstream
	// 内積計算
	static float dot(Vector3D vector,Vector3D vector2) {
		float a[] = { vector.x,vector.y,vector.z };
		float b[] = { vector2.x,vector2.y,vector2.z };
		// スタンダードライブラリの内積計算
		float result = static_cast<float>(std::inner_product(a, a + sizeof(a) / sizeof(a[0]), b, 0));
=======
	//内積計算
	static float dot(Vector3D vector,Vector3D vector2)
	{
		//DXライブラリの内積計算
		float result = DxLib::VDot(vector, vector2);
>>>>>>> Stashed changes

		return result;
	}
	// クロス積計算
	static Vector3D cross(Vector3D vector,Vector3D vector2) {
		Vector3D TempVector;
		TempVector.x = vector.y * vector2.z - vector.z * vector2.y;
		TempVector.y = vector.x * vector2.z - vector.z * vector2.x;
		TempVector.z = vector.x * vector2.y - vector.y * vector2.x;

		return TempVector;
	}
	// ラジアン計算 (進行方向計算用)
	static float MoveOnAngleOfElevation(Vector3D vector,Vector3D vector2) {
		const double px = static_cast<double> (vector.x - vector2.x);
		const double pz = static_cast<double> (vector.z - vector2.z);
		//atan2 は 引数がy xのため pz,pxの順で挿入する
		return static_cast<float> (std::atan2(pz, px));
	}
	// ラジアン計算(モデル回転)
	static float RotateOnAngleOfElevation(Vector3D vector, Vector3D vector2) {
		const double px = static_cast<double> (vector.x - vector2.x);
		const double pz = static_cast<double> (vector.z - vector2.z);
		//atan2 は 引数がy xだが、なぜか回転がおかしくなるのでx zで挿入する
		return static_cast<float> (std::atan2(px, pz));
	}
#pragma endregion
};
