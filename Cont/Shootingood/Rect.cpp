#include "Rect.h"

// �L�����N�^�[�̓����蔻��p�̔�������ĕԂ�
std::unordered_map<std::string, Rect> Rect::Make_3DBox(std::unordered_map<std::string, Rect>& rects) {
	std::unordered_map<std::string, Rect> result;

	return  rects;
}

// �ʂ̒��S���W��Ԃ�
Vector3D Rect::Get_Centor_Point(float width, float height, float depth, Vector3D max_vertex) {
	Vector3D vector3;
	vector3 = vector3.Get_Vector(max_vertex.x - width, max_vertex.y - height, max_vertex.z - depth);

	return vector3;
}
