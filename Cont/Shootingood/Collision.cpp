#include "Collision.h"

Collision::Collision() {

}

// ���t���[���Ă΂��X�V����
void Collision::Update() {
	std::unique_ptr<Actor>& actor = Actor::Get_Instance();
	//TEST
	Line_To_Face(std::static_pointer_cast<Enemy>(actor->children["Enemy_1"]));
	Line_To_Face(std::static_pointer_cast<Enemy>(actor->children["Enemy_2"]));
	std::unique_ptr<Enemy_Manager>& enemy_manager = Enemy_Manager::Get_Instance();
	auto enemys = enemy_manager->enemies;
	for (auto enemy : enemys) {
		Line_To_Face(enemy);
	}
}

// ������2�_�Ԃ̋��������߂ĕԂ�
float Collision::Get_Distance(Vector3D coordinates_1, Vector3D coordinates_2) {
	return calculator.Norm_3D(coordinates_1.x, coordinates_1.y, coordinates_1.z, coordinates_2.x, coordinates_2.y, coordinates_2.z);
}

Vector3D Collision::Get_Vector(Vector3D point1, Vector3D point2) {
	return calculator.Make_Vector(point1, point2);
}

// �����ƕ���(�v���C���[�̒ʏ�U���ƃG�l�~�[�̑O��)�̓����蔻��
bool Collision::Line_To_Face(std::shared_ptr<Enemy> enemy) {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	auto player_position = player_manager->player->vector3d;

	//TODO:pla_pos����Ȃ��Ēʏ�U���̏o��ʒu��
	auto vector1 = calculator.Make_Vector(enemy->rects["front_face"].Get_Centor_Position(), player_position);
	auto vector2 = calculator.Make_Vector(enemy->rects["front_face"].Get_Centor_Position(), player_manager->player_weapon->Get_Limit_Range());

	// ����Ɏg���ʂ̖@���x�N�g��
	auto normal_vector = enemy->rects["front_face"].normal_vector;

	//TEST
	auto hoge = VDot(vector1, normal_vector);
	auto fuga = VDot(vector2, normal_vector);
	if (hoge * fuga <= 0) {
		auto piyo = 0;
	}

	return hoge * fuga <= 0;
}
