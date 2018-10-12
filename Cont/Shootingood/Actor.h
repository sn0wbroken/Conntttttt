#pragma once

#include"DxLib.h"
#include"Vector3D.h"
#include"Define_Value.h"

// �A�N�^�[�̊��̃N���X
class Actor {
public:
	// �R���X�g���N�^
	Actor() {};
	// �f�X�g���N�^
	virtual ~Actor() {};

	// �A�N�^�[��`��
	virtual void Render() = 0;

	// ���݂�x���W��Ԃ�
	float Get_X();
	// x���W��ݒ肷��
	void Set_X(float set_x);
	// ���݂�y���W��Ԃ�
	float Get_Y();
	// y���W��ݒ肷��
	void Set_Y(float set_y);
	// ����Ԃ�
	int Get_Width();
	// ������Ԃ�
	int Get_Height();

	Vector3D* Get_Vector3D() {
		return vector3;
	}
	
	// �A�N�^�[�̉E�[�̍��W��Ԃ�
	virtual int Get_Right_Edge() = 0;
	// �A�N�^�[�̍��[�̍��W��Ԃ�
	virtual int Get_Left_Edge() = 0;
	// �A�N�^�[�̏�[�̍��W��Ԃ�
	virtual int Get_Top_Edge() = 0;
	// �A�N�^�[�̉��[�̍��W��Ԃ�
	virtual int Get_Bottom_Edge() = 0;

protected:
	// ���W�֌W�̃N���X
	Vector3D* vector3;// = new Vector3D();

	// �萔���܂Ƃ߂Ă����\����
	Define_Value define_value;

	// �A�N�^�[�̑傫��(��)
	int width;
	// �A�N�^�[�̑傫��(����)
	int height;

	// ���S���� true�Ŏ��S
	bool is_dead;
};