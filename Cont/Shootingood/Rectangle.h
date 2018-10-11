#pragma once

#if _MSC_VER >= 1900
#pragma  warning(disable: 4458) // Visual Studio 2015 で C4458 をチェックしない様にする
#endif
	// 矩形クラス
	template<class T> class Rectangle
	{
	public:
		T left;		// 左上隅X座標
		T top;		// 左上隅Y座標
		T right;	// 右下隅X座標(領域外)
		T bottom;	// 右下隅Y座標(領域外)

		// デフォルト・コンストラクタ
		explicit inline Rectangle() throw()
		{
			initializeFieldsForConstructor();
		}

		// コピー・コンストラクタ
		inline Rectangle(const Rectangle & right) throw()
		{
			copyFieldsForConstructor(right);
		}

		// デストラクタ
		virtual inline ~Rectangle() throw()
		{
		}

		// コンストラクタ
		explicit inline Rectangle(const Dimension<T> & dimension) throw()
		{
			initializeFieldsForConstructor(static_cast<T> (0), static_cast<T> (0), dimension.width, dimension.height);
		}
		explicit inline Rectangle(const D2D1_SIZE_F & size) throw()
		{
			initializeFieldsForConstructor(static_cast<T> (0), static_cast<T> (0), static_cast<T> (size.width), static_cast<T> (size.height));
		}
		explicit inline Rectangle(const D2D1_SIZE_U & size) throw()
		{
			initializeFieldsForConstructor(static_cast<T> (0), static_cast<T> (0), static_cast<T> (size.width), static_cast<T> (size.height));
		}
		explicit inline Rectangle(const T width, const T height) throw()
		{
			initializeFieldsForConstructor(static_cast<T> (0), static_cast<T> (0), width, height);
		}
		explicit inline Rectangle(const T left, const T top, const T right, const T bottom) throw()
		{
			initializeFieldsForConstructor(left, top, right, bottom);
		}
		explicit inline Rectangle(const Point<T> & point) throw()
		{
			initializeFieldsForConstructor(point.x, point.y, point.x, point.y);
		}
		explicit inline Rectangle(const Point<T> & point, const Dimension<T> & dimension) throw()
		{
			initializeFieldsForConstructor(point.x, point.y, point.x + dimension.width, point.y + dimension.height);
		}
		explicit inline Rectangle(const RECT & rect) throw()
		{
			initializeFieldsForConstructor(static_cast<T> (rect.left), static_cast<T> (rect.top), static_cast<T> (rect.right), static_cast<T> (rect.bottom));
		}
		explicit inline Rectangle(const D2D1_RECT_F & rect) throw()
		{
			initializeFieldsForConstructor(static_cast<T> (rect.left), static_cast<T> (rect.top), static_cast<T> (rect.right), static_cast<T> (rect.bottom));
		}
		explicit inline Rectangle(const D2D1_RECT_U & rect) throw()
		{
			initializeFieldsForConstructor(static_cast<T> (rect.left), static_cast<T> (rect.top), static_cast<T> (rect.right), static_cast<T> (rect.bottom));
		}

		// 指定された点を含むかどうかを判定するメソッド
		inline bool contains(const T x, const T y) const throw()
		{
			return x >= left && x < right && y >= top && y < bottom;
		}
		inline bool contains(const Point<T> & point) const throw()
		{
			return contains(point.x, point.y);
		}

		// 指定された矩形を完全に含むかどうかを判定するメソッド
		inline bool contains(const Rectangle & right) const throw()
		{
			return !(right.left < left || right.top < top || right.right > this->right || right.bottom > bottom);
		}

		// 左上隅の位置を固定してサイズを縮める(膨らませる)メソッド
		inline Rectangle & deflate(const T h, const T v) throw()
		{
			right -= h;
			bottom -= v;
			return *this;
		}

		// 高さを求めるメソッド
		inline T getHeight() const throw()
		{
			return bottom - top;
		}

		// 位置(左上隅の座標)を求めるメソッド
		inline Point<T> getLocation() const throw()
		{
			return Point<T>(left, top);
		}

		// 中心の座標を求めるメソッド
		inline Point<T> getCenter() const throw()
		{
			return Point<T>((left + right) / static_cast<T> (2), (top + bottom) / static_cast<T> (2));
		}

		// 大きさ(幅と高さ)を求めるメソッド
		inline Dimension<T> getSize() const throw()
		{
			return Dimension<T>(getWidth(), getHeight());
		}

		// 幅を求めるメソッド
		inline T getWidth() const throw()
		{
			return right - left;
		}

		// 水平方向の位置(左上隅のX座標)を求めるメソッド
		inline T getX() const throw()
		{
			return left;
		}

		// 垂直方向の位置(左上隅のY座標)を求めるメソッド
		inline T getY() const throw()
		{
			return top;
		}

		// 水平方向と垂直方向の両方にサイズ変更するメソッド
		inline Rectangle & grow(const T h, const T v) throw()
		{
			left -= h;
			top -= v;
			right += h;
			bottom += v;
			return *this;
		}

		// 指定された矩形との共通部分を求めるメソッド
		inline Rectangle intersection(const Rectangle & right) const throw()
		{
			const T l = std::max(left, right.left);
			const T t = std::max(top, right.top);
			const T r = std::min(this->right, right.right);
			const T b = std::min(bottom, right.bottom);
			return Rectangle(l, t, r, b);
		}

		// 指定された矩形と交差するかどうかを判定するメソッド
		inline bool intersects(const Rectangle & right) const throw()
		{
			return left < right.right && top < right.bottom && right.left < this->right && right.top < bottom;
		}

		// 空(矩形にならない)かどうかを判定するメソッド
		inline bool isEmpty() const throw()
		{
			return !(left < right && top < bottom);
		}

		// 指定された矩形に置き換えるメソッド
		inline Rectangle & setBounds(const T left, const T top, const T right, const T bottom) throw()
		{
			this->left = left;
			this->top = top;
			this->right = right;
			this->bottom = bottom;
			return *this;
		}

		// 空に設定するメソッド
		inline Rectangle & setEmpty() throw()
		{
			return setBounds(static_cast<T> (0), static_cast<T> (0), static_cast<T> (0), static_cast<T> (0));
		}

		// 指定された位置に移動させるメソッド
		inline Rectangle & setLocation(const T x, const T y) throw()
		{
			right += x - left;
			bottom += y - top;
			left = x;
			top = y;
			return *this;
		}
		inline Rectangle & setLocation(const Point<T> & point) throw()
		{
			return setLocation(point.x, point.y);
		}

		// 指定された大きさ(幅と高さ)に変更するメソッド
		inline Rectangle & setSize(const T width, const T height) throw()
		{
			right = left + width;
			bottom = top + height;
			return *this;
		}

		// 指定された距離だけを平行移動させるメソッド
		inline Rectangle & translate(const T & dx, const T & dy) throw()
		{
			left += dx;
			top += dy;
			right += dx;
			bottom += dy;
			return *this;
		}

		// 指定された矩形との結合部分を求めるメソッド
		inline Rectangle unionRect(const Rectangle & right) const throw()
		{
			const T l = std::min(left, right.left);
			const T t = std::min(top, right.top);
			const T r = std::max(this->right, right.right);
			const T b = std::max(bottom, right.bottom);
			return Rectangle(l, t, r, b);
		}

		// 代入演算子
		inline Rectangle & operator=(const Rectangle & right) throw()
		{
			if (this != &right) {
				copyFieldsForConstructor(right);
			}
			return *this;
		}

		// 等価演算子
		inline bool operator==(const Rectangle & right) const throw()
		{
			return left == right.left && top == right.top && this->right == right.right && bottom == right.bottom;
		}

		// 非等価演算子
		inline bool operator!=(const Rectangle & right) const throw()
		{
			return !operator==(right);
		}

		// 型変換演算子(RECT)
		inline operator RECT() const throw()
		{
			const RECT rc = { static_cast<LONG> (left), static_cast<LONG> (top), static_cast<LONG> (right), static_cast<LONG> (bottom) };
			return rc;
		}

		// 型変換演算子(D2D1_RECT_F)
		inline operator D2D1_RECT_F() const throw()
		{
			return D2D1::RectF(static_cast<float> (left), static_cast<float> (top), static_cast<float> (right), static_cast<float> (bottom));
		}

		// 型変換演算子(D2D1_RECT_U)
		inline operator D2D1_RECT_U() const throw()
		{
			return D2D1::RectU(static_cast<UINT32> (left), static_cast<UINT32> (top), static_cast<UINT32> (right), static_cast<UINT32> (bottom));
		}

	private:
		// フィールド・クリア・メソッド(主にコンストラクタ複数ある場合に使用)
		inline void initializeFieldsForConstructor(const T left = static_cast<T> (0), const T top = static_cast<T> (0), const T right = static_cast<T> (0), const T bottom = static_cast<T> (0)) throw()
		{
			this->left = left;
			this->top = top;
			this->right = right;
			this->bottom = bottom;
		}

		// フィールド複写メソッド(主にコピー・コンストラクタと代入演算子が使用)
		inline void copyFieldsForConstructor(const Rectangle & right) throw()
		{
			left = right.left;
			top = right.top;
			this->right = right.right;
			bottom = right.bottom;
		}
	};
#if _MSC_VER >= 1900
#pragma  warning(default: 4458) // Visual Studio 2015 で C4458 をチェックするように様にする
#endif
