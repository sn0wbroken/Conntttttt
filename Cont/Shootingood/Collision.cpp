#include "Collision.h"

Collision::Collision()
{
}

// 毎フレーム呼ばれる更新処理
void Collision::Update() {
	//Line_To_Face(Actor::children);
}

// プレイヤーからエネミーまでの距離を求めて返す
float Collision::Get_Distance_Player_To_Enemy(std::shared_ptr<Enemy> enemy) {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	auto player_position = player_manager->player->vector3d;
	auto enemy_position = enemy->vector3d;

	return calculator.Norm_3D(player_position.x, player_position.y, player_position.z, enemy_position.x, enemy_position.y, enemy_position.z);
}

// 線分と平面(プレイヤーの通常攻撃とエネミーの前面)の当たり判定
bool Collision::Line_To_Face(std::shared_ptr<Enemy> enemy, Vector3D normal_vector) {
	//auto hoge = Actor::children["Enemy"];
	//auto fuga = std::static_pointer_cast<Enemy>(hoge);
	//
	//return (norm_1 * normal_vector.x + norm_1 * normal_vector.y + norm_1 * normal_vector.z) *
	//	   (norm_2 * normal_vector.x + norm_2 * normal_vector.y + norm_2 * normal_vector.z) <= 0;
	return 0;
}
