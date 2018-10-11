#include "Vector2D.h"


template <typename T>
Vector2D<T>::Vector2D()
{
}

template <typename T>
Vector2D<T>::~Vector2D()
{
}
template <typename T>
void Vector2D<T>::Move(T set_x, T set_y) {
	x += set_x;
	y += set_y;
}

// ”z’u
template <typename T>
void Vector2D<T>::Arrange(T set_x, T set_y) {
	x = set_x;
	y = set_y;
}
