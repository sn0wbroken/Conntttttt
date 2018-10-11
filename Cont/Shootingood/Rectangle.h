#pragma once

#if _MSC_VER >= 1900
#pragma  warning(disable: 4458) // Visual Studio 2015 �� C4458 ���`�F�b�N���Ȃ��l�ɂ���
#endif
	// ��`�N���X
	template<class T> class Rectangle
	{
	public:
		T left;		// �����X���W
		T top;		// �����Y���W
		T right;	// �E����X���W(�̈�O)
		T bottom;	// �E����Y���W(�̈�O)

		// �f�t�H���g�E�R���X�g���N�^
		explicit inline Rectangle() throw()
		{
			initializeFieldsForConstructor();
		}

		// �R�s�[�E�R���X�g���N�^
		inline Rectangle(const Rectangle & right) throw()
		{
			copyFieldsForConstructor(right);
		}

		// �f�X�g���N�^
		virtual inline ~Rectangle() throw()
		{
		}

		// �R���X�g���N�^
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

		// �w�肳�ꂽ�_���܂ނ��ǂ����𔻒肷�郁�\�b�h
		inline bool contains(const T x, const T y) const throw()
		{
			return x >= left && x < right && y >= top && y < bottom;
		}
		inline bool contains(const Point<T> & point) const throw()
		{
			return contains(point.x, point.y);
		}

		// �w�肳�ꂽ��`�����S�Ɋ܂ނ��ǂ����𔻒肷�郁�\�b�h
		inline bool contains(const Rectangle & right) const throw()
		{
			return !(right.left < left || right.top < top || right.right > this->right || right.bottom > bottom);
		}

		// ������̈ʒu���Œ肵�ăT�C�Y���k�߂�(�c��܂���)���\�b�h
		inline Rectangle & deflate(const T h, const T v) throw()
		{
			right -= h;
			bottom -= v;
			return *this;
		}

		// ���������߂郁�\�b�h
		inline T getHeight() const throw()
		{
			return bottom - top;
		}

		// �ʒu(������̍��W)�����߂郁�\�b�h
		inline Point<T> getLocation() const throw()
		{
			return Point<T>(left, top);
		}

		// ���S�̍��W�����߂郁�\�b�h
		inline Point<T> getCenter() const throw()
		{
			return Point<T>((left + right) / static_cast<T> (2), (top + bottom) / static_cast<T> (2));
		}

		// �傫��(���ƍ���)�����߂郁�\�b�h
		inline Dimension<T> getSize() const throw()
		{
			return Dimension<T>(getWidth(), getHeight());
		}

		// �������߂郁�\�b�h
		inline T getWidth() const throw()
		{
			return right - left;
		}

		// ���������̈ʒu(�������X���W)�����߂郁�\�b�h
		inline T getX() const throw()
		{
			return left;
		}

		// ���������̈ʒu(�������Y���W)�����߂郁�\�b�h
		inline T getY() const throw()
		{
			return top;
		}

		// ���������Ɛ��������̗����ɃT�C�Y�ύX���郁�\�b�h
		inline Rectangle & grow(const T h, const T v) throw()
		{
			left -= h;
			top -= v;
			right += h;
			bottom += v;
			return *this;
		}

		// �w�肳�ꂽ��`�Ƃ̋��ʕ��������߂郁�\�b�h
		inline Rectangle intersection(const Rectangle & right) const throw()
		{
			const T l = std::max(left, right.left);
			const T t = std::max(top, right.top);
			const T r = std::min(this->right, right.right);
			const T b = std::min(bottom, right.bottom);
			return Rectangle(l, t, r, b);
		}

		// �w�肳�ꂽ��`�ƌ������邩�ǂ����𔻒肷�郁�\�b�h
		inline bool intersects(const Rectangle & right) const throw()
		{
			return left < right.right && top < right.bottom && right.left < this->right && right.top < bottom;
		}

		// ��(��`�ɂȂ�Ȃ�)���ǂ����𔻒肷�郁�\�b�h
		inline bool isEmpty() const throw()
		{
			return !(left < right && top < bottom);
		}

		// �w�肳�ꂽ��`�ɒu�������郁�\�b�h
		inline Rectangle & setBounds(const T left, const T top, const T right, const T bottom) throw()
		{
			this->left = left;
			this->top = top;
			this->right = right;
			this->bottom = bottom;
			return *this;
		}

		// ��ɐݒ肷�郁�\�b�h
		inline Rectangle & setEmpty() throw()
		{
			return setBounds(static_cast<T> (0), static_cast<T> (0), static_cast<T> (0), static_cast<T> (0));
		}

		// �w�肳�ꂽ�ʒu�Ɉړ������郁�\�b�h
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

		// �w�肳�ꂽ�傫��(���ƍ���)�ɕύX���郁�\�b�h
		inline Rectangle & setSize(const T width, const T height) throw()
		{
			right = left + width;
			bottom = top + height;
			return *this;
		}

		// �w�肳�ꂽ���������𕽍s�ړ������郁�\�b�h
		inline Rectangle & translate(const T & dx, const T & dy) throw()
		{
			left += dx;
			top += dy;
			right += dx;
			bottom += dy;
			return *this;
		}

		// �w�肳�ꂽ��`�Ƃ̌������������߂郁�\�b�h
		inline Rectangle unionRect(const Rectangle & right) const throw()
		{
			const T l = std::min(left, right.left);
			const T t = std::min(top, right.top);
			const T r = std::max(this->right, right.right);
			const T b = std::max(bottom, right.bottom);
			return Rectangle(l, t, r, b);
		}

		// ������Z�q
		inline Rectangle & operator=(const Rectangle & right) throw()
		{
			if (this != &right) {
				copyFieldsForConstructor(right);
			}
			return *this;
		}

		// �������Z�q
		inline bool operator==(const Rectangle & right) const throw()
		{
			return left == right.left && top == right.top && this->right == right.right && bottom == right.bottom;
		}

		// �񓙉����Z�q
		inline bool operator!=(const Rectangle & right) const throw()
		{
			return !operator==(right);
		}

		// �^�ϊ����Z�q(RECT)
		inline operator RECT() const throw()
		{
			const RECT rc = { static_cast<LONG> (left), static_cast<LONG> (top), static_cast<LONG> (right), static_cast<LONG> (bottom) };
			return rc;
		}

		// �^�ϊ����Z�q(D2D1_RECT_F)
		inline operator D2D1_RECT_F() const throw()
		{
			return D2D1::RectF(static_cast<float> (left), static_cast<float> (top), static_cast<float> (right), static_cast<float> (bottom));
		}

		// �^�ϊ����Z�q(D2D1_RECT_U)
		inline operator D2D1_RECT_U() const throw()
		{
			return D2D1::RectU(static_cast<UINT32> (left), static_cast<UINT32> (top), static_cast<UINT32> (right), static_cast<UINT32> (bottom));
		}

	private:
		// �t�B�[���h�E�N���A�E���\�b�h(��ɃR���X�g���N�^��������ꍇ�Ɏg�p)
		inline void initializeFieldsForConstructor(const T left = static_cast<T> (0), const T top = static_cast<T> (0), const T right = static_cast<T> (0), const T bottom = static_cast<T> (0)) throw()
		{
			this->left = left;
			this->top = top;
			this->right = right;
			this->bottom = bottom;
		}

		// �t�B�[���h���ʃ��\�b�h(��ɃR�s�[�E�R���X�g���N�^�Ƒ�����Z�q���g�p)
		inline void copyFieldsForConstructor(const Rectangle & right) throw()
		{
			left = right.left;
			top = right.top;
			this->right = right.right;
			bottom = right.bottom;
		}
	};
#if _MSC_VER >= 1900
#pragma  warning(default: 4458) // Visual Studio 2015 �� C4458 ���`�F�b�N����悤�ɗl�ɂ���
#endif
