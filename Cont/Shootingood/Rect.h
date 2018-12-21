#pragma once

#include"Vector3D.h"

#include<memory>
#include<string>
#include<unordered_map>

// 矩形クラス
class Rect {
public:
	// コンストラクタ
	Rect() {};
	
	// キャラクターの当たり判定用の箱を作って返す
	std::unordered_map<std::string ,Rect> Make_3DBox(std::unordered_map<std::string, Rect>& actor);

	// エネミーの矩形を作って返す
	Rect Make_Enemy_Rectangle(Vector3D posiotin, float width, float height, float depth);

	// 面の中心座標を返す
	Vector3D Get_Centor_Point(float width, float height, float depth, Vector3D top_right);

	// 四角形の左上隅の座標
	Vector3D top_left;
	// 四角形の右上隅の座標
	Vector3D top_right;
	// 四角形の右下隅の座標
	Vector3D bottom_right;
	// 四角形の左下隅の座標
	Vector3D bottom_left;
	// 法線ベクトル。線分との判定に使う
	Vector3D normal_vector;

	// 幅
	float width;
	// 高さ
	float height;

	// 3次元数の取得、計算に使用
	Vector3D vector;

	/*// 指定された点を含むかどうかを判定するメソッド
	inline bool contains(const float x, const float y) const throw() {
		return x >= left && x < right && y >= top && y < bottom;
	}
	inline bool contains(const Vector3D point) const throw()
	{
		return contains(point.x, point.y);
	}

	//当たり判定 四角 クラス渡す
	bool Intersects(const Rect<T> &right) {
		return left < right.right &&
			top < right.bottom &&
			right.top < bottom &&
			right.left < this->right;
	}
	//当たり判定 四角 指定バージョン
	bool Intersects(T aTop, T aLeft, T aRight, T aBottom) {
		return left < right && top < bottom && left < right && top < bottom;
	}
	*/
};
