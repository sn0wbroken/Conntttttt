#pragma once
#include <windows.h>

template <typename T> 
class Rectangle{
public:
	//上
	T Top;
	//左
	T Left;
	//右
	T Right;
	//下
	T Bottom;

	// コンストラクタ
	Rectangle(T aTop, T aLeft,T aRight, T aBottom) {
		Top = aTop;
		Left = aLeft;
		Right = aRight;
		Bottom = aBottom;
	}
	// コピーコンストラクタ
	Rectangle(const Rectangle<T> &right) {
		Top = a1.Top;
		Left = a1.Left;
		Right = a1.Right;
		Bottom = a1.Bottom;
	}
	//当たり判定 四角 クラス渡す
	bool Intersects(const Rectangle<T> &right) {
		return left < right.right && top < right.bottom && right.left < this->right && right.top < bottom;
	}
	//当たり判定 四角 指定バージョン
	bool Intersects(T aTop, T aLeft, T aRight, T aBottom) {
		return left < right && top < bottom && left < right && top < bottom;
	}



};