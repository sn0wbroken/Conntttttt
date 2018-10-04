#pragma once

#define _USE_MATH_DEFINES

#include"DxLib.h"
#include"Enum.h"
#include"Player.h"
#include"Key_Checker.h"
#include"Player_Status.h"

#include<cmath>
#include<memory>
#include<functional>

// �v���C���[�̍s�����Ǘ�����N���X
class Player_Action {
public:
	// �R���X�g���N�^
	Player_Action(std::shared_ptr<Player> player, 
				  std::shared_ptr<Player_Status> player_statsu);
	// �f�X�g���N�^
	~Player_Action();

	// �v���C���[�̑�����܂Ƃ߂� ���t���[���Ăяo��
	void Player_Controll();

	// ������
	void Initialize();

	// �v���C���[�̃V���b�g�^�C�v
	ePlayer_Shot_Type shot_type;

private:
	// �萔���܂Ƃ߂Ă����\����
	Define_Value define_value;
	
	// �v���C���[�{�̂̃N���X
	std::shared_ptr<Player> player;
	// �v���C���[�̃X�e�[�^�X�֌W�̃N���X
	std::shared_ptr<Player_Status> player_status;
	
	// �L�[���͂��`�F�b�N����N���X
	std::unique_ptr<Key_Checker>& key_checker = Key_Checker::Get_Instance();

	// �v���C���[���ړ�������
	void Move();
	// �e�𔭎�
	void Fire();
	// �U���̎�ނ�؂�ւ���B���t���[����t����
	void Change_Fire_Type();

	// �E�[����o�Ă��邩 �ړ��̎��Ƀ`�F�b�N����
	bool Is_Over_Max_X();
	// ���[����o�Ă��邩 �ړ��̎��Ƀ`�F�b�N����
	bool Is_Over_Min_X();
	
	// �e���̎��
	std::function<void()> fire_type;

	// �p�x
	float rad;
	// �e�����Ԃ����ʒu
	double position_x;
	// sin�g����邽�߂ɉ��Z����l
	int counter;
	// �U�ꕝ
	double amplitude;
};
