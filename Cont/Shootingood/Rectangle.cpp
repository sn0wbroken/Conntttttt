#include "Rectangle.h"

// �R���X�g���N�^
Rectangle::Rectangle() {
	normal_vector.Set_Vector(1, 0, 0);
}

// �ʂ̒��S���W��Ԃ�
Vector3D Rectangle::Get_Centor_Point(float width, float height, Vector3D top_right) {
	auto centor_position = top_right;

	centor_position.x -= width / 2;
	centor_position.y -= height / 2;

	return centor_position;
}
