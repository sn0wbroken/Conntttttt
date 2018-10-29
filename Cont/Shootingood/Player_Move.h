#pragma once

#define _USE_MATH_DEFINES

#include"DxLib.h"
#include"Player.h"
#include"Player_Status.h"

#include<cmath>
#include<memory>

// �v���C���[�̈ړ����Ǘ�����
class Player_Move {
public:
	// �R���X�g���N�^
	Player_Move();
	// �R�s�[�R���X�g���N�^
	Player_Move(std::shared_ptr<Player> set_player, std::shared_ptr<Player_Status> set_player_status);
	// �f�X�g���N�^
	~Player_Move();

	// �v���C���[���ړ�������
	void Move();

private:
	std::shared_ptr<Player> player;
	std::shared_ptr<Player_Status> player_status;
};

