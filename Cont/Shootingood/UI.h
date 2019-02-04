#pragma once

#include"DxLib.h"
#include"Define_Value.h"
#include"Enemy_Manager.h"
#include"Player_Manager.h"


#include <sstream>
// UI�\���N���X
class UI {
public:
	// �R���X�g���N�^
	UI();
	// �f�X�g���N�^
	~UI() {};

	// �`��
	void Render();

	// �C���^�[�o�����̃A�i�E���X��\��
	void Interval_Announce();
private:
	std::shared_ptr<Player_Weapon> player_weapon;

	std::vector<Enemy> enemies;

	// �G�l�~�[�̐���\��
	void Enemy_Number();
	// ���݃v���C���̃X�e�[�W��\��
	void Now_Stage();
	// �v���C���[�̎c�@��\��
	void Player_Life();
	// ��Ԃ̎c�e��\��
	void Tank_ammo();

	// �萔���܂Ƃ߂Ă����N���Xs
	Define_Value define_value;

	// UI�\����̔w�i
	int UI_background_graph;
};