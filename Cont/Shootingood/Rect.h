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

	// コンストラクタ
	Rect() {}

	//中心から作るコンストラクタ 座標と大きさ
	Rect(T _x, T _y,T _width,T _height) {
		x = _x;
		y = _y;

		width = _width;
		height = _height;

		//中心から作る
		left = x - (width /2);
		right = x + (width / 2);
		top = y - (height / 2);
		bottom = y + (height / 2);
	}
	//中心から 座標と半径
	Rect(T _x, T _y, T _r)
	{
		x = _x;
		y = _y;

		left	= _x - _r;
		right	= _x + _r;
		top		= _y - _r;
		bottom	= _y + _r;
	}

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
