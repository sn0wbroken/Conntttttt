#pragma once

// 矩形クラス
template <typename T> 
class Rect{
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
	// コピーコンストラクタ
	Rect(int x, int y) {}
	// コピーコンストラクタ
	Rect(T aTop, T aLeft,T aRight, T aBottom) {
		top = aTop;
		left = aLeft;
		right = aRight;
		bottom = aBottom;
	}
	// コピーコンストラクタ
	Rect(const Rect<T> &right) {
		top    = right.top;
		left   = right.left;
		right  = right.right;
		bottom = right.bottom;
	}

	void Initialize() {
		
	};

	//当たり判定 四角 クラス渡す
	bool Intersects(const Rect<T> &right) {
		return left       < right.right &&
			   top        < right.bottom &&
			   right.top  < bottom &&
			   right.left < this->right;
	}
	//当たり判定 四角 指定バージョン
	bool Intersects(T aTop, T aLeft, T aRight, T aBottom) {
		return left < right && top < bottom && left < right && top < bottom;
	}
};
