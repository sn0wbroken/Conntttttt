#include "Vector3D.h"

// �R���X�g���N�^
template <typename T>
Vector3D<T>::Vector3D() {

}
// �f�X�g���N�^
template <typename T>
Vector3D<T>::~Vector3D() {

}

// �ړ�
template <typename T>
void Vector3D<T>::Move(T set_x, T set_y, T set_z) {
	x += set_x;
	y += set_y;
	z += set_z;
}
// �z�u
template <typename T>
void Vector3D<T>::Arrange(T set_x, T set_y, T set_z) {
	x = set_x;
	y = set_y;
	z = set_z;
}
