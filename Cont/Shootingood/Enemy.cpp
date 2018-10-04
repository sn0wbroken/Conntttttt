#include "Enemy.h"
#include"Game_Manager.h"


// �R���X�g���N�^
Enemy::Enemy(int set_x, int set_y) {
	// �v���C����X�e�[�W���擾
	std::unique_ptr<Game_Manager>& game_manager = Game_Manager::Get_Instance();

	x = set_x;
	y = set_y;

	initialize_position_x = set_x;
	initialize_position_y = set_y;

	// �G�l�~�[�̕�
	width = define_value.ENEMY_WIDTH;
	// �G�l�~�[�̍���
	height = define_value.ENEMY_HEIGHT;

	// �X�e�[�^�X���Z�b�g
	enemy_status = std::make_shared<Enemy_Status>(game_manager->Get_Stage());

	// �G�l�~�[�̉摜�����[�h
	enemy_graph = LoadGraph("Picture/Enemy/Evil_Enemy.png");
	damage_enemy_graph = LoadGraph("Picture/Enemy/Damage_Evil_Enemy.png");
}

// �f�X�g���N�^
Enemy::~Enemy() {}

// �`��
void Enemy::Render() {	
	// ������`��
	if (!enemy_status->Is_Damage()) {
		DrawExtendGraph(x, y, x + width, y + height, enemy_graph, FALSE);
		return;
	}
	if (enemy_status->Is_Damage()) {
		DrawExtendGraph(x, y, x + width, y + height, damage_enemy_graph, FALSE);
	}
}

// �G�l�~�[�̉E�[�̍��W��Ԃ�
int Enemy::Get_Right_Edge() {
	return x + width;
}

// �G�l�~�[�̍��[�̍��W��Ԃ�
int Enemy::Get_Left_Edge() {
	return x;
}

// �G�l�~�[�̏�[�̍��W��Ԃ�
int Enemy::Get_Top_Edge() {
	return y;
}

// �G�l�~�[�̉��[�̍��W��Ԃ�
int Enemy::Get_Bottom_Edge() {
	return y + height;
}

// �e�̔��˂���ʒu��Ԃ�
int Enemy::Get_Shot_Point() {
	return x + (width / 2);
}

// ����x���W��Ԃ�
int Enemy::Get_Initialize_Position_X() {
	return initialize_position_x;
}

// ����y���W��Ԃ�
int Enemy::Get_Initialize_Position_Y() {
	return initialize_position_y;
}
