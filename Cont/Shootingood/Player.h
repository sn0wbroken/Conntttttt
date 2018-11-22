#pragma once

#include"Rect.h"
#include"Bullet.h"
#include"Character.h"

#include<vector>

// �v���C���[�{�̂̃N���X
class Player : public Character {
public:
	// �R���X�g���N�^
	Player();
	// �f�X�g���N�^
	~Player();

	// ������
	void Initialize();

	//// �A�N�^�[�̉E�[�̍��W��Ԃ�
	//virtual float Get_Right_Edge() override;
	//// �A�N�^�[�̍��[�̍��W��Ԃ�
	//virtual float Get_Left_Edge() override;
	//// �A�N�^�[�̏�[�̍��W��Ԃ�
	//virtual float Get_Top_Edge() override;
	//// �A�N�^�[�̉��[�̍��W��Ԃ�
	//virtual float Get_Bottom_Edge() override;

	// �e���o��ʒu��Ԃ�
	float Get_Shoot_Point();

	// �p���[�A�b�v��Ԃł��邩���Z�b�g����
	void Set_Power_Up(bool set_is_power_up);
	// �p���[�A�b�v��Ԃł��邩��Ԃ�
	bool Get_Power_Up();

	// �v���C���[�����e
	std::vector<Bullet> player_bullet;

private:
	// ��`�N���X
	Rect<float> rectangle;

	// ���S����B����ł�����true
	bool is_dead;
	// �p���[�A�b�v��Ԃ�
	bool is_power_up;
};
