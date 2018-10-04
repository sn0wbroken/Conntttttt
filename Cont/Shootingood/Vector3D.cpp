#include "Vector3D.h"

// コンストラクタ
Vector3D::Vector3D() {

}
// デストラクタ
Vector3D::~Vector3D() {

}

// 移動
void Vector3D::Move(float set_x, float set_y, float set_z) {
	x += set_x;
	y += set_y;
	z += set_z;
}
// 配置
void Vector3D::Arrange(float set_x, float set_y, float set_z) {
	x = set_x;
	y = set_y;
	z = set_z;
}
