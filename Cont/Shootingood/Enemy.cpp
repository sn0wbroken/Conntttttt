#include"Enemy.h"
#include"Scene_Manager.h"

// �R���X�g���N�^
Enemy::Enemy() {}

// �R�s�[�R���X�g���N�^
Enemy::Enemy(float set_x, float set_y) {
	// �v���C����X�e�[�W���擾
	std::unique_ptr<Scene_Manager>& scene_manager = Scene_Manager::Get_Instance();

	// �z�u
	vector3.Arrange(set_x, set_y, 0);

	initialize_position_x = set_x;
	initialize_position_y = set_y;

	// �G�l�~�[�̕�
	width = define_value.ENEMY_WIDTH;
	// �G�l�~�[�̍���
	height = define_value.ENEMY_HEIGHT;

	// �X�e�[�^�X���Z�b�g
	enemy_status = std::make_shared<Enemy_Status>(scene_manager->Get_Stage());

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
		DrawExtendGraph((int)vector3.x, (int)vector3.y, (int)vector3.x + width,
			(int)vector3.y + height, enemy_graph, FALSE);
		return;
	}
	if (enemy_status->Is_Damage()) {
		DrawExtendGraph((int)vector3.x, (int)vector3.y, (int)vector3.x + width,
			(int)vector3.y + height, damage_enemy_graph, FALSE);
	}
}

// �G�l�~�[�̉E�[�̍��W��Ԃ�
float Enemy::Get_Right_Edge() {
	return vector3.x + width;
}

// �G�l�~�[�̍��[�̍��W��Ԃ�
float Enemy::Get_Left_Edge() {
	return vector3.x;
}

// �G�l�~�[�̏�[�̍��W��Ԃ�
float Enemy::Get_Top_Edge() {
	return vector3.y;
}

// �G�l�~�[�̉��[�̍��W��Ԃ�
float Enemy::Get_Bottom_Edge() {
	return vector3.y + height;
}

// �e�̔��˂���ʒu��Ԃ�
float Enemy::Get_Shot_Point() {
	return vector3.x + (width / 2);
}

// ����x���W��Ԃ�
float Enemy::Get_Initialize_Position_X() {
	return initialize_position_x;
}

// ����y���W��Ԃ�
float Enemy::Get_Initialize_Position_Y() {
	return initialize_position_y;
}