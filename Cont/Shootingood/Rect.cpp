#include "Rect.h"

// ��ƂȂ��`�A�T�C�Y���󂯎�蓖���蔻��p�̔�������ĕԂ��B���`�͓V�䕔�B
std::unordered_map<std::string, Rect> Rect::Make_3DBox(Rect top_face, Object_Size size, std::unordered_map<std::string, Rect>& rects) {
	// �O�ʍ쐬
	Rect front_face;
	front_face.max_vertex   = top_face.max_vertex;
	front_face.top_left     = top_face.top_left;
	front_face.bottom_right = front_face.max_vertex.Subtract_VectorY(size.height);
	front_face.bottom_left  = front_face.top_left.Subtract_VectorY(size.height);
	
	front_face.width  = front_face.max_vertex.x - front_face.top_left.x;
	front_face.height = size.height;
	
	rects["front_face"] = front_face;
	
	// �w�ʍ쐬
	Rect back_face;
	back_face.max_vertex   = top_face.bottom_right;
	back_face.top_left     = top_face.bottom_left;
	back_face.bottom_right = back_face.max_vertex.Subtract_VectorY(size.height);
	back_face.bottom_left  = back_face.top_left.Subtract_VectorY(size.height);
	
	back_face.width  = back_face.max_vertex.x - back_face.top_left.x;
	back_face.height = size.height;

	rects["back_face"] = back_face;
	
	// �E�ʍ쐬
	Rect right_face;
	right_face.max_vertex   = top_face.max_vertex;
	right_face.top_left     = back_face.max_vertex;
	right_face.bottom_right = right_face.max_vertex.Subtract_VectorY(size.height);
	right_face.bottom_left  = right_face.top_left.Subtract_VectorY(size.height);
	
	right_face.width  = right_face.max_vertex.x - right_face.top_left.x;
	right_face.height = size.height;

	rects["right_face"] = right_face;
	
	// ���ʍ쐬
	Rect left_face;
	left_face.max_vertex    = top_face.top_left;
	left_face.top_left     = top_face.max_vertex;
	left_face.bottom_right = left_face.max_vertex.Subtract_VectorY(size.height);
	left_face.bottom_left  = left_face.top_left.Subtract_VectorY(size.height);
	
	left_face.width  = left_face.max_vertex.x - left_face.top_left.x;
	left_face.height = size.height;
	
	rects["left_face"] = left_face;

	return rects;
}

// �I�u�W�F�N�g�̑傫���ƍ��W����V�������ĕԂ��B�󂯎����W�͍���`�̍ő�_
Rect Rect::Make_Top_Face(Vector3D position, Object_Size size) {
	// ��`�̍ő�_�̍��W
	Vector3D top_vertex = VGet(position.x + size.Get_Helf_Width(), position.y + size.height, position.z + size.Get_Helf_Depth());

	//��ʂ��쐬
	Rect result;
	result.max_vertex    = top_vertex;
	result.top_left     = top_vertex.Subtract_VectorX(size.width);
	result.bottom_right = top_vertex.Subtract_VectorZ(size.depth);
	result.bottom_left  = result.top_left.Subtract_VectorZ(size.depth);

	result.width  = max_vertex.x - top_left.x;
	result.height = size.height;
	
	return result;
}

// �ʂ̒��S���W��Ԃ�
Vector3D Rect::Get_Centor_Point() {
	Vector3D result;
	result = result.Get_Vector(max_vertex.x - width, max_vertex.y - height, max_vertex.z);

	return result;
}
