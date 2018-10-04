#pragma once

#include"DxLib.h"
#include"Define_Value.h"
#include"Enemy_Manager.h"
#include"Player_Manager.h"

#include<sstream>

// UI�\���N���X
class UI {
public:
	// �R���X�g���N�^
	UI();
	// �f�X�g���N�^
	~UI() {};

	// �`��
	void Render();

private:
	std::unique_ptr<Enemy_Manager>& enemy_manager   = Enemy_Manager::Get_Instance();
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();

	// �G�l�~�[�̐���\��
	void Enemy_Number();
	// �v���C���[�̍U���^�C�v��\��
	void Player_Shot_Type();
	// ���݃v���C���̃X�e�[�W��\��
	void Now_Stage();
	// �v���C���[�̎c�@��\��
	void Player_Life();
	
	// �萔���܂Ƃ߂Ă����\����s
	Define_Value define_value;

	// UI�\����̔w�i
	int UI_background_graph;
};