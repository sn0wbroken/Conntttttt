#pragma once
#include "Vector3D.h"

// 矩形クラス
template <typename T>
class Rect {
public:
	//上
	T top;
	//左
	T left;
	//右
	T right;
	//下
	T bottom;
	// 幅
	T width;
	// 高さ
	T height;
	
	Rect() {}

	// コンストラクタ
	Rect(T aTop, T aLeft, T aRight, T aBottom) {
		top = aTop;
		left = aLeft;
		right = aRight;
		bottom = aBottom;

		width = right - left;
		height = bottom - top;
	}
	// コピーコンストラクタ
	Rect(const Rect<T> &Right) {
		top = Right.top;
		left = Right.left;
		right = Right.right;
		bottom = Right.bottom;
		width = Right.width;
		height = Right.height;
	}

	void Initialize() {
	};

	// 指定された点を含むかどうかを判定するメソッド
	inline bool contains(const T x, const T y) const throw()
	{
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
};
