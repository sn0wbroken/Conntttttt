#pragma once

#include"Vector3D.h"
#include"Object_Size.h"

#include<memory>
#include<string>
#include<unordered_map>

// ��`�N���X
class Rect {
public:
	// �R���X�g���N�^
	Rect() {};
	
	// ��ƂȂ��`�A�T�C�Y���󂯎��A�����蔻��p�̔�������ĕԂ��B���`�͓V�䕔�B
	std::unordered_map<std::string ,Rect> Make_3DBox(Rect top_face, Object_Size size, std::unordered_map<std::string, Rect>& rects);

	// �I�u�W�F�N�g�̑傫���ƍ��W����V�������ĕԂ��B�󂯎����W�͍���`�̍ő�_
	Rect Make_Top_Face(Vector3D posiotin, Object_Size size);

	// �\���Ă��郂�f���ɍ��킹�ē�����
	void Move(std::unordered_map<std::string, Rect>& rects, float speed, float radian);

	// �O�ʂ̒��S���W��ݒ肷��
	void Set_Centor_Position();
	// �O�ʂ̒��S���W��Ԃ�
	Vector3D Get_Centor_Position();

	// �@���x�N�g����Ԃ�
	void Set_Normal_Vector(Rect& rect);
	
	// ��`����]������
	std::unordered_map<std::string, Rect> Rotation_Rectangle(std::unordered_map<std::string, Rect>& rects, Vector3D axis, float radian);

	// �l�p�`�̍�����̍��W
	Vector3D top_left;
	// �l�p�`�̊p�ň�ԑ傫������(��_�Ɏg��)
	Vector3D top_right;
	// �l�p�`�̉E�����̍��W
	Vector3D bottom_right;
	// �l�p�`�̍������̍��W
	Vector3D bottom_left;
	// �@���x�N�g���B�����Ƃ̔���Ɏg��
	Vector3D normal_vector;

	// ��
	float width;
	// ����
	float height;

	// �ʂ̒��S���W
	Vector3D centor_positon;

private:
	// 3�������̎擾�A�v�Z�Ɏg�p
	Vector3D vector;

	/*// �w�肳�ꂽ�_���܂ނ��ǂ����𔻒肷�郁�\�b�h
	inline bool contains(const float x, const float y) const throw() {
		return x >= left && x < right && y >= top && y < bottom;
	}
	inline bool contains(const Vector3D point) const throw()
	{
		return contains(point.x, point.y);
	}

	//�����蔻�� �l�p �N���X�n��
	bool Intersects(const Rect<T> &right) {
		return left < right.right &&
			top < right.bottom &&
			right.top < bottom &&
			right.left < this->right;
	}
	//�����蔻�� �l�p �w��o�[�W����
	bool Intersects(T aTop, T aLeft, T aRight, T aBottom) {
		return left < right && top < bottom && left < right && top < bottom;
	}
	*/
};
