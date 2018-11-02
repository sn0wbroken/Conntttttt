#pragma once

#define _USE_MATH_DEFINES

#include"DxLib.h"
#include"Enum.h"
#include"Player.h"
#include"Player_Move.h"
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

	// ���t���[���Ă΂��
	void Update();

	// ������
	void Initialize();

	// �v���C���[�̃V���b�g�^�C�v
	ePlayer_Shot_Type shot_type;

private:
	// �萔���܂Ƃ߂Ă����\����
	Define_Value define_value;

	// �v���C���[�{�̂̃N���X
	std::shared_ptr<Player> player;
	// �v���C���[�̈ړ����Ǘ�����N���X
	std::shared_ptr<Player_Move> player_move;
	// �v���C���[�̃X�e�[�^�X�֌W�̃N���X
	std::shared_ptr<Player_Status> player_status;

	// �L�[���͂��`�F�b�N����N���X
	std::unique_ptr<Key_Checker>& key_checker = Key_Checker::Get_Instance();


	// �e�𔭎�
	void Fire();
	// �U���̎�ނ�؂�ւ���B���t���[����t����
	void Change_Fire_Type();
	// ��Ԃɉ������V���b�g��ݒ肷��
	void Player_Action::Set_Shot_Pattern();

	// �ł��o�����e�ۂ���ʊO�֏o�Ă��邩�𔻒f����
	bool Player_Action::Check_Off_Screen(Bullet& player_Bullet);
	// �ł��o�����e�ۂ���ʊO�ɏo�Ă��������
	void Player_Action::Bullet_Off_Screen_Erase();

	// �e���̎�� //TODO:�ϐ��������킩��Â炢��
	std::function<void()> fire_type;

	// �p�x
	float rad;
	// �e�����˂����ʒu
	double position_x;
	// sin�g����邽�߂ɉ��Z����l
	int counter;
	// �U�ꕝ
	double amplitude;
};
