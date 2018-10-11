#include "Vector3D.h"

// コンストラクタ
template <typename T>
Vector3D<T>::Vector3D() {

}
// デストラクタ
template <typename T>
Vector3D<T>::~Vector3D() {

}

// 移動
template <typename T>
void Vector3D<T>::Move(T set_x, T set_y, T set_z) {
	x += set_x;
	y += set_y;
	z += set_z;
}
// 配置
template <typename T>
void Vector3D<T>::Arrange(T set_x, T set_y, T set_z) {
	x = set_x;
	y = set_y;
	z = set_z;
}
