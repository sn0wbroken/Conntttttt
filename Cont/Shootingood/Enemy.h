#pragma once

#include"DxLib.h"
#include"Bullet.h"
#include"Character.h"
#include"Enemy_Status.h"

#include<vector>
#include<memory>

// �G�l�~�[�{�̂̃N���X
class Enemy : public Character {
public:
	// �R���X�g���N�^
	Enemy();
	// �R�s�[�R���X�g���N�^
	Enemy(float set_x, float set_y);
	// �f�X�g���N�^
	~Enemy();

	// �G�l�~�[��`��
	void Render() override;

	// �G�l�~�[�̉E�[�̍��W��Ԃ�
	float Get_Right_Edge() override;
	// �G�l�~�[�̍��[�̍��W��Ԃ�
	float Get_Left_Edge() override;
	// �G�l�~�[�̏�[�̍��W��Ԃ�
	float Get_Top_Edge() override;
	// �G�l�~�[�̉��[�̍��W��Ԃ�
	float Get_Bottom_Edge() override;
	// �e�̔��˂���ʒu��Ԃ�
	float Get_Shot_Point();
	// ����x���W��Ԃ�
	float Get_Initialize_Position_X();
	// ����y���W��Ԃ�
	float Get_Initialize_Position_Y();

	// �G�l�~�[�̃X�e�[�^�X�֌W�̃N���X
	std::shared_ptr<Enemy_Status> enemy_status;

private:
	// ����x���W���o���Ă���
	float initialize_position_x;
	// ����y���W���o���Ă���
	float initialize_position_y;

	// �G�l�~�[�̉摜
	int enemy_graph;
	// �U�����󂯂Ă���Ƃ��̃G�l�~�[�̉摜
	int damage_enemy_graph;
	// �ł��o���e�̑��x
	int bullet_speed;
};
