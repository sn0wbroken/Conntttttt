#pragma once

#include"DxLib.h"
#include"Enum.h"
#include"Player.h"
#include"Player_Move.h"
#include"Key_Checker.h"
#include"Player_Status.h"

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

private:
	// �萔���܂Ƃ߂Ă����N���X
	Define_Value define_value;

	// �v���C���[�{�̂̃N���X
	std::shared_ptr<Player> player;
	// �v���C���[�̈ړ����Ǘ�����N���X
	std::shared_ptr<Player_Move> player_move;
	// �v���C���[�̃X�e�[�^�X�֌W�̃N���X
	std::shared_ptr<Player_Status> player_status;

	// �L�[���͂��`�F�b�N����N���X
	std::unique_ptr<Key_Checker>& key_checker = Key_Checker::Get_Instance();
};
