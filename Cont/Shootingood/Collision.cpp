#include "Collision.h"

Collision::Collision()
{
}

// ���t���[���Ă΂��X�V����
void Collision::Update() {
	//TEST
	Line_To_Face(std::static_pointer_cast<Enemy>(Actor::children["Enemy_1"]));
	Line_To_Face(std::static_pointer_cast<Enemy>(Actor::children["Enemy_2"]));
}

// �v���C���[����G�l�~�[�܂ł̋��������߂ĕԂ�
float Collision::Get_Distance_Player_To_Enemy(std::shared_ptr<Enemy> enemy) {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	auto player_position = player_manager->player->vector3d;
	auto enemy_position = enemy->vector3d;

	return calculator.Norm_3D(player_position.x, player_position.y, player_position.z, enemy_position.x, enemy_position.y, enemy_position.z);
}

// �����ƕ���(�v���C���[�̒ʏ�U���ƃG�l�~�[�̑O��)�̓����蔻��
bool Collision::Line_To_Face(std::shared_ptr<Enemy> enemy) {
	auto norm_1 = Get_Distance_Player_To_Enemy(enemy);
	
	///norm2�̓v���C���[�̒ʏ�U���̓͂��ő�n�_�̍��W�B///
	return (norm_1 * enemy->rects["front_face"]->normal_vector.x + norm_1 * enemy->rects["front_face"]->normal_vector.y + norm_1 * enemy->rects["front_face"]->normal_vector.z) *
		   (norm_2 * enemy->rects["front_face"]->normal_vector.x + norm_2 * enemy->rects["front_face"]->normal_vector.y + norm_2 * enemy->rects["front_face"]->normal_vector.z) <= 0;
	return 0;
}
