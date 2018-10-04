#pragma once

// �����蔻����s��
class Collision {
public:
	// �R���X�g���N�^
	Collision() {};
	// �f�X�g���N�^
	~Collision() {};

	// �A�N�^�[���m�ł̓����蔻��
	bool Box_To_Box(int right_edge1, int left_edge1, int top_edge1, int right_edge2, int left_edge2, int bottom_edge2);

	// �v���C���[�ƃG�l�~�[�̒e�̓����蔻��
	bool Player_To_Enemy_Bullet(int right_edge, int left_edge, int top_edge, int bottom_edge, int bullet_position_x, int bullet_position_y, int bullet_radius);

	// �G�l�~�[�ƃv���C���[�̒e�̓����蔻��
	bool Enemy_To_Player_Bullet(int right_edge, int left_edge, int top_edge, int bottom_edge, int bullet_position_x, int bullet_position_y, int bullet_radius);
};

