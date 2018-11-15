#include "Collision.h"

// �A�N�^�[���m�ł̓����蔻��
bool Collision::Box_To_Box(int right_edge1, int left_edge1, int top_edge1, int right_edge2, int left_edge2, int bottom_edge2) {
	return
		right_edge1 >= left_edge2 && left_edge1 <= right_edge2 &&
		top_edge1 <= bottom_edge2;
}

// �v���C���[�ƃG�l�~�[�̒e�̓����蔻��
bool Collision::Player_To_Enemy_Bullet(int right_edge, int left_edge, int top_edge, int bottom_edge, int bullet_position_x, int bullet_position_y, int bullet_radius) {
	return
		right_edge >= bullet_position_x - bullet_radius && left_edge <= bullet_position_x + bullet_radius &&
		top_edge <= bullet_position_y + bullet_radius && bottom_edge >= bullet_position_y + bullet_radius;
}

// �G�l�~�[�ƃv���C���[�̒e�̓����蔻��
bool Collision::Enemy_To_Player_Bullet(int right_edge, int left_edge, int top_edge, int bottom_edge, int bullet_position_x, int bullet_position_y, int bullet_radius) {
	return
		right_edge >= bullet_position_x - bullet_radius && left_edge <= bullet_position_x + bullet_radius &&
		top_edge <= bullet_position_y - bullet_radius && bottom_edge >= bullet_position_y + bullet_radius;
}