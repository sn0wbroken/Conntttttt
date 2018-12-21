#include "Rect.h"

// ��ƂȂ��`�A�T�C�Y���󂯎��A�����蔻��p�̔�������ĕԂ��B���`�͓V�䕔�B
std::unordered_map<std::string, Rect> Rect::Make_3DBox(Rect rect, Object_Size size, std::unordered_map<std::string, Rect>& rects) {
	std::unordered_map<std::string, Rect> result;

	return  rects;
}

// �I�u�W�F�N�g�̑傫���ƍ��W�����`������ĕԂ��B���W�͍���`�̍ő�_
Rect Rect::Make_Rectangle(Vector3D position, Object_Size size) {
	// ��`�̍ő�_�̍��W
	Vector3D top_vertex = VGet(position.x + size.Get_Helf_Depth(), position.y + size.height, position.z + size.Get_Helf_Width());

	Rect result;
	result.top_right    = top_vertex;
	result.top_left     = top_vertex.Subtract_VectorX(size.depth);
	result.bottom_right = top_vertex.Subtract_VectorZ(size.width);
	result.bottom_left  = result.top_left.Subtract_VectorZ(size.width);
	return result;
}

// �ʂ̒��S���W��Ԃ�
Vector3D Rect::Get_Centor_Point(float width, float height, float depth, Vector3D max_vertex) {
	Vector3D vector3;
	vector3 = vector3.Get_Vector(max_vertex.x - width, max_vertex.y - height, max_vertex.z - depth);

	return vector3;
}
