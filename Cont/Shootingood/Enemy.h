#pragma once

#include"DxLib.h"
#include"Actor.h"
#include"Bullet.h"
#include"Enemy_Status.h"

#include<vector>
#include<memory>

// �G�l�~�[�{�̂̃N���X
class Enemy : public Actor {
public:
	// �R���X�g���N�^
	Enemy() {};
	// �R�s�[�R���X�g���N�^
	Enemy(int set_x, int set_y);
	// �f�X�g���N�^
	~Enemy();

	// �G�l�~�[��`��
	void Render() override;

	// �G�l�~�[�̉E�[�̍��W��Ԃ�
	int Get_Right_Edge() override;
	// �G�l�~�[�̍��[�̍��W��Ԃ�
	int Get_Left_Edge() override;
	// �G�l�~�[�̏�[�̍��W��Ԃ�
	int Get_Top_Edge() override;
	// �G�l�~�[�̉��[�̍��W��Ԃ�
	int Get_Bottom_Edge() override;
	// �e�̔��˂���ʒu��Ԃ�
	int Get_Shot_Point();
	// ����x���W��Ԃ�
	int Get_Initialize_Position_X();
	// ����y���W��Ԃ�
	int Get_Initialize_Position_Y();

	// �G�l�~�[�̃X�e�[�^�X�֌W�̃N���X
	std::shared_ptr<Enemy_Status> enemy_status;

private:
	// ����x���W���o���Ă���
	int initialize_position_x;
	// ����y���W���o���Ă���
	int initialize_position_y;

	// �G�l�~�[�̉摜
	int enemy_graph;
	// �U�����󂯂Ă���Ƃ��̃G�l�~�[�̉摜
	int damage_enemy_graph;
	// �ł��o���e�̑��x
	int bullet_speed;
};