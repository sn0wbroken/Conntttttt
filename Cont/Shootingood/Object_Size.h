#pragma once

// �I�u�W�F�N�g�̃T�C�Y���܂Ƃ߂ĕێ�
class Object_Size {
public:
	// �R���X�g���N�^
	Object_Size() {};

	// �R�s�[�R���X�g���N�^
	Object_Size(float set_width, float set_height, float set_depth) :
	width(set_width),
	height(set_height),
	depth(set_depth) {};

	// ��
	float width;
	// ����
	float height;
	// ���s
	float depth;

	// ���̔����̒l���擾
	float Get_Helf_Width() {
		return width / 2;
	}
	// �����̔����̒l���擾
	float Get_Helf_Height() {
		return height / 2;
	}	
	// ���s�̔����̒l���擾
	float Get_Helf_Depth() {
		return depth / 2;
	}
	
	// �傫����ݒ肷��
	void Set_Size(float set_width, float set_height, float set_depth) {
		width = set_width;
		height = set_height;
		depth = set_depth;
	}
};