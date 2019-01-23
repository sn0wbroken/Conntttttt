#pragma once

#include"Rect.h"
#include"Actor.h"
#include"DxLib.h"
#include"Vector3D.h"
#include"Object_Size.h"
#include"Define_Value.h"

// �A�N�^�[�̊��̃N���X
class Character : public Actor {
public:
	// �R���X�g���N�^
	Character();
	// �f�X�g���N�^
	virtual ~Character() {};

	// ���݂�x���W��Ԃ�
	float Get_X();
	// x���W��ݒ肷��
	void Set_X(float set_x);
	// ���݂�y���W��Ԃ�
	float Get_Y();
	// y���W��ݒ肷��
	void Set_Y(float set_y);
	//���݂�z���W��Ԃ�
	float Get_Z();
	//z���W��ݒ肷��
	void Set_Z(float set_z);

	// �o���ʒu��ݒ肷��
	void Set_Arrange_Poisition(float set_x, float set_y, float set_z);
	// ���W��ݒ肷��
	void Set_Position(Vector3D set_ecor3);
	// ���W��Ԃ�
	Vector3D Get_Position();

	// �傫����Ԃ�
	Object_Size Get_Size();

	// �A�N�^�[�̉E�[�̍��W��Ԃ�
	float Get_Right_Edge();
	// �A�N�^�[�̍��[�̍��W��Ԃ�
	float Get_Left_Edge();
	// �A�N�^�[�̏�[�̍��W��Ԃ�
	float Get_Top_Edge();
	// �A�N�^�[�̉��[�̍��W��Ԃ�
	float Get_Bottom_Edge();
	
	// �A�N�^�[�̃��f���n���h����Ԃ�
	int &Get_Model_Handle();

protected:
	// �����̒��S�̍��W
	Vector3D center_position;

	// �萔���܂Ƃ߂Ă����N���X
	Define_Value define_value;

	// ���g�̃C���X�^���X��ێ�
	std::shared_ptr<Character> character;

	// ���f���̃n���h��
	int model_handle;

	// ���S���� true�Ŏ��S
	bool is_dead;
	
	// �A�N�^�[�I�u�W�F�N�g�𐶐�����
	void Create_Actor(TCHAR* model_path) override;

	// �`����s��
	void Render() override;

	// ��`�̍쐬�Ɏg�p
	Rect rect;
	
	// �傫�����܂Ƃ߂ĕێ�
	Object_Size size;
};