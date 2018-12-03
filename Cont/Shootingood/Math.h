#pragma once
#include "Vector3D.h"
namespace VMath
{
#pragma region calclator
	//ベクターの長さ
	Vector3D VectorLength(Vector3D vec);
	// ノルム　ベクトルの長さ計算
	double Norm2(double _x, double _y);
	// 平方根計算 バビロニアメソッド
	double sqrt(double s);
	//ベクトルの正規化
	Vector3D normalize(Vector3D vector);
	//内積計算
	Vector3D dot(Vector3D  vector, Vector3D vector2);
	//クロス積計算
	Vector3D cross(Vector3D vector,Vector3D vector2);
#pragma endregion
}