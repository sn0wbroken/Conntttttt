#include "Collision.h"

Collision::Collision()
{
}

// 毎フレーム呼ばれる更新処理
void Collision::Update() {
	std::unique_ptr<Actor>& actor = Actor::Get_Instance();
	//TEST
	Line_To_Face(std::static_pointer_cast<Enemy>(actor->children["Enemy_1"]));
	Line_To_Face(std::static_pointer_cast<Enemy>(actor->children["Enemy_2"]));
}

// 引数の2点間の距離を求めて返す
float Collision::Get_Distance(Vector3D coordinates_1, Vector3D coordinates_2) {
	return calculator.Norm_3D(coordinates_1.x, coordinates_1.y, coordinates_1.z, coordinates_2.x, coordinates_2.y, coordinates_2.z);
}

// 線分と平面(プレイヤーの通常攻撃とエネミーの前面)の当たり判定
bool Collision::Line_To_Face(std::shared_ptr<Enemy> enemy) {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	auto player_position = player_manager->player->vector3d;

	auto norm_1 = Get_Distance(player_position, enemy->rects["front_face"].Get_Centor_Point());
	auto norm_2 = Get_Distance(player_manager->player_weapon->Get_Limit_Range(), enemy->rects["front_face"].Get_Centor_Point());
	auto normal_vector = enemy->rects["front_face"].normal_vector;

	return (norm_1 * normal_vector.x + norm_1 * normal_vector.y + norm_1 * normal_vector.z) *
		   (norm_2 * normal_vector.x + norm_2 * normal_vector.y + norm_2 * normal_vector.z) <= 0;
}
