#pragma once

#include"DxLib.h"
#include"Define_Value.h"

// �A�N�^�[���ł��o���e��
class Bullet {
public:
	// �R���X�g���N�^
	Bullet(int set_x, int set_y, int set_direction_x, int set_direction_y);
	// �f�X�g���N�^
	~Bullet();

	// ���t���[���Ă΂��
	void Update();
	// �`��
	void Render();

	// x���W��Ԃ�
	int Get_X();
	// y���W��Ԃ�
	int Get_Y();
	// ���a��Ԃ�
	int Get_Radius();

	// �e�̈ړ�
	void Move(int x, int y);

	// ��ʉ�������o�悤�Ƃ��Ă��Ȃ���
	bool Is_Over_Max_Y();
	// ��ʏ㕔����o�悤�Ƃ��Ă��Ȃ���
	bool Is_Over_Min_Y();

private:
	// x���W
	int x;
	// y���W
	int y;
	// �e�̔��a
	int radius;
	// �e�̔��ł�������x
	int direction_x;
	// �e�̔��ł�������y
	int direction_y;

	// �萔���܂Ƃ߂Ă����\����
	Define_Value define_value;
};
