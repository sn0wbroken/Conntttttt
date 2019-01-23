#include "Rect.h"

// ��ƂȂ��`�A�T�C�Y���󂯎�蓖���蔻��p�̔�������ĕԂ��B���`�͓V�䕔�B
std::unordered_map<std::string, Rect> Rect::Make_3DBox(Rect top_face, Object_Size size, std::unordered_map<std::string, Rect>& rects) {
	// �O�ʍ쐬
	Rect front_face;
	// 4�̒��_�̍��W��ݒ�
	front_face.top_right    = top_face.top_right;
	front_face.top_left     = top_face.top_left;
	front_face.bottom_right = front_face.top_right.Subtract_VectorY(size.height);
	front_face.bottom_left  = front_face.top_left.Subtract_VectorY(size.height);
	
	// ���A������ݒ�
	front_face.width  = front_face.top_right.x - front_face.top_left.x;
	front_face.height = size.height;

	// �ʂ̒��S�_��ݒ�
	front_face.Set_Centor_Position();
	//TEST
	Set_Normal_Vector(front_face);
	rects["front_face"] = front_face;
	
	// �w�ʍ쐬
	Rect back_face;
	back_face.top_right    = top_face.bottom_right;
	back_face.top_left     = top_face.bottom_left;
	back_face.bottom_right = back_face.top_right.Subtract_VectorY(size.height);
	back_face.bottom_left  = back_face.top_left.Subtract_VectorY(size.height);
	
	back_face.width  = back_face.top_right.x - back_face.top_left.x;
	back_face.height = size.height;

	rects["back_face"] = back_face;
	
	// �E�ʍ쐬
	Rect right_face;
	right_face.top_right    = top_face.top_right;
	right_face.top_left     = back_face.top_right;
	right_face.bottom_right = right_face.top_right.Subtract_VectorY(size.height);
	right_face.bottom_left  = right_face.top_left.Subtract_VectorY(size.height);
	
	right_face.width  = right_face.top_right.x - right_face.top_left.x;
	right_face.height = size.height;

	rects["right_face"] = right_face;
	
	// ���ʍ쐬
	Rect left_face;
	left_face.top_right    = top_face.top_left;
	left_face.top_left     = top_face.bottom_left;
	left_face.bottom_right = left_face.top_right.Subtract_VectorY(size.height);
	left_face.bottom_left  = left_face.top_left.Subtract_VectorY(size.height);
	
	left_face.width  = left_face.top_right.x - left_face.top_left.x;
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
	result.top_right    = top_vertex;
	result.top_left     = top_vertex.Subtract_VectorX(size.width);
	result.bottom_right = top_vertex.Subtract_VectorZ(size.depth);
	result.bottom_left  = result.top_left.Subtract_VectorZ(size.depth);

	result.Set_Centor_Position();

	result.width  = top_right.x - top_left.x;
	result.height = size.height;
	
	return result;
}

// �\���Ă��郂�f���ɍ��킹�ē�����
void Rect::Move(float speed, float radian) {
	// ��`(�����̎����Ă��钸�_)�̈ړ�
	top_right   .Move(speed * cosf(radian), 0.0f, speed * sinf(radian));
	top_left    .Move(speed * cosf(radian), 0.0f, speed * sinf(radian));
	bottom_right.Move(speed * cosf(radian), 0.0f, speed * sinf(radian));
	bottom_left .Move(speed * cosf(radian), 0.0f, speed * sinf(radian));

	//TEST
	auto color = GetColor(0,0,0);
	DrawLine3D(top_right   , top_left    , color);
	DrawLine3D(top_right   , bottom_right, color);
	DrawLine3D(top_left    , bottom_left , color);
	DrawLine3D(bottom_right, bottom_left , color);

}

// �O�ʂ̒��S���W��ݒ肷��
void Rect::Set_Centor_Position() {
	center_position = calcurator.Get_Vector(top_right.x - (width / 2), top_right.y - (height / 2), top_right.z);
}
// �O�ʂ̒��S���W��Ԃ�
Vector3D Rect::Get_Centor_Position() {
	return center_position;
}

// �@���x�N�g�������߂Đݒ肷��
void Rect::Set_Normal_Vector(Rect& rect) {
	Vector3D result;

	auto vec1 = calcurator.Make_Vector(rect.center_position, rect.top_left);
	auto vec2 = calcurator.Make_Vector(rect.center_position, rect.top_right);
	result = calcurator.Cross(vec1, vec2);

	result.x = vec2.y * vec1.z - vec1.y * vec2.z;
	result.y = vec2.x * vec1.z - vec1.x * vec2.z;
	result.z = vec2.x * vec1.y - vec1.x * vec2.y;

	rect.normal_vector = result;
}

// ��`����]������ //TODO:map���C�e���[�^�ŉ񂷂̂�낵���Ȃ��H
std::unordered_map<std::string, Rect> Rect::Rotation_Rectangle(std::unordered_map<std::string, Rect>& rects, Vector3D axis, float radian) {
	// rects�Ɋi�[����Ă����`�S�Ă���]������
	for (auto iterator = begin(rects); iterator != end(rects); ++iterator) {
		auto rotate_value = MMult(MGetTranslate(VScale(axis, -1.0f)), MMult(MGetRotY(radian), MGetTranslate(axis)));

		iterator->second.top_right    = VTransform(iterator->second.top_right   , rotate_value);
		iterator->second.top_left     = VTransform(iterator->second.top_left    , rotate_value);
		iterator->second.bottom_right = VTransform(iterator->second.bottom_right, rotate_value);
		iterator->second.bottom_left  = VTransform(iterator->second.bottom_left , rotate_value);

		//TODO: ���X�G���H
		if (iterator == rects.find("front_face")) {
			iterator->second.center_position = VTransform(iterator->second.center_position, rotate_value);
		}
	}

	return rects;
}
