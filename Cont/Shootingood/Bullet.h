#pragma once

#include"DxLib.h"
#include"Actor.h"
#include"Vector3D.h"
#include"Define_Value.h"

// �A�N�^�[���ł��o���e��
class Bullet : public Actor {
public:
	// �R���X�g���N�^
	Bullet();
	// �f�X�g���N�^
	~Bullet();

	// ���t���[���Ă΂��
	void Update() override;
	// �`��
	void Render() override;

	// x���W��Ԃ�
	float Get_X();
	// x���W��ݒ肷��
	void Set_X(float set_x);
	// y���W��Ԃ�
	float Get_Y();
	// y���W��ݒ肷��
	void Set_Y(float set_y);
	// z���W��Ԃ�
	float Get_Z();
	// z���W��ݒ肷��
	void Set_Z(float set_z);
	// ���a��Ԃ�
	int Get_Radius();

	// �e�̈ړ�
	void Move(float x = 0.0f, float y = 0.0f, float z = 0.0f);
	// ���ł����p�x��ݒ肷��
	void Set_Radian(float set_radian);
	// ���ł������x��ݒ肷��
	void Set_Speed(float set_speed);

private:
	// �e�̔��a
	int radius;
	// ���ł����p�x
	float radian;
	// ���ł������x
	float speed;

	//�e�̐i�ޕ���
	Vector3D Direction;
	
	// ��ʉE�[����o�悤�Ƃ��ĂȂ���
	bool Is_Over_Max_X();
	// ��ʉ��[����o�悤�Ƃ��Ă��Ȃ���
	bool Is_Over_Max_Y();
	// ��ʏ�[����o�悤�Ƃ��Ă��Ȃ���
	bool Is_Over_Min_X();
	// ��ʍ��[����o�悤�Ƃ��ĂȂ���
	bool Is_Over_Min_Y();
	// �e�ۂ��\���͈͊O�ɏo�Ă��邩�𔻒f
	bool Bullet_Off_Screen();
};
