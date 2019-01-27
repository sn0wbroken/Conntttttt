#include"Collision.h"

#include"Object_Creater.h"

Collision::Collision() {

}

// 毎フレーム呼ばれる更新処理
void Collision::Update() {
	std::unique_ptr<Enemy_Manager>& enemy_manager = Enemy_Manager::Get_Instance();
	auto enemys = enemy_manager->active_enemies;
	
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	auto player_weapon = player_manager->player_weapon;

	for (auto enemy : enemys) {
		// プレイヤーとエネミーの当たり判定
		if (Player_To_Enemy(player_manager->player, enemy)) {
			// 当たっていたらダメージ
			player_manager->player_status->Damage();
			// 当たった敵は死亡。戦車にぶつかるんだから当たりまえだよなぁ
			enemy->enemy_status->Dead();
		}

		// 通常攻撃との当たり判定を行う
		if (!player_weapon->Get_Is_Shooting()) {
			continue;
		}
		else if (Nomal_Attack_To_Enemy(enemy)) {
			enemy->enemy_status->Dead();
		}
	}
	// 通常攻撃は敵を貫通するのでフラグを戻すのは最後
	player_weapon->Initialize_Is_Shooting();
}

// 引数の2点間の距離を求めて返す
float Collision::Get_Distance(Vector3D coordinates_1, Vector3D coordinates_2) {
	return calculator.Norm_3D(coordinates_1.x, coordinates_1.y, coordinates_1.z, coordinates_2.x, coordinates_2.y, coordinates_2.z);
}

// 通常攻撃を行ったときにエネミーにヒットしたかを調べる
bool Collision::Nomal_Attack_To_Enemy(std::shared_ptr<Enemy> enemy) {
	// 線分と平面の当たり判定を行う
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	auto muzzule_position = player_manager->player_weapon->Get_Position();
	auto limit_fire_range = player_manager->player_weapon->Get_Limit_Range();
	auto front_face = enemy->rects["front_face"];
	auto normal_vector = front_face.normal_vector;

	// 面の点から始点
	auto vector1 = calculator.Make_Vector(front_face.Get_Centor_Position(), muzzule_position);
	// 面の点から終点
	auto vector2 = calculator.Make_Vector(front_face.Get_Centor_Position(), limit_fire_range);	
	// 面の点から始点の内積
	auto dot1 = calculator.Dot(vector1, normal_vector);
	// 面の点から始点の内積
	auto dot2 = calculator.Dot(vector2, normal_vector);
	DrawLine3D(vector1, vector2, GetColor(0, 255, 0));
	// 線分が平面を貫いているか
	if (dot1 * dot2 <= 0) {
		// 交点を求める
		Vector3D intersection = Get_Intersection(vector1, vector2, limit_fire_range, muzzule_position, front_face);
		DrawLine3D(vector1,vector2, GetColor(0,0,255));
		// 交点が判定基準の面に接しているかを調べる
		if (Point_To_Rectangle(intersection, muzzule_position, limit_fire_range, normal_vector, front_face)) {
			OutputDebugString("Bell");
			DrawLine3D(vector1,vector2,GetColor(255,0,0));
			return true;
		}
	}

	return false;
}

// 点が矩形に内接しているかを調べる 同一平面上にあることが前提
bool Collision::Point_To_Rectangle(Vector3D intersection, Vector3D start_point, Vector3D end_point, Vector3D normal_vector, Rect face) {
	// 始点をp,終点をqとする
	auto p = start_point;
	auto q = end_point;
	// 調べる面の各頂点を反時計回りにabcdとする
	auto a = face.top_left;
	auto b = face.bottom_left;
	auto c = face.bottom_right;
	auto d = face.top_right;

	// 調べる線分
	auto pq = calculator.Make_Vector(end_point, start_point);

	auto pa = calculator.Make_Vector(a, p);
	auto pb = calculator.Make_Vector(b, p);
	auto pc = calculator.Make_Vector(c, p);

	auto m = calculator.Cross(pc, pq);
	auto v = calculator.Dot(pa, m);

	if (v <= 0.0f) {
		float u = -calculator.Dot(pb, m);
		if (u < 0.0f) return false;

		float w = calculator.Dot(calculator.Cross(pq, pb), pa);
		if (w < 0.0f) return false;
	}
	else {
		auto pd = d - p;

		float u = calculator.Dot(pd, m);
		if (u < 0.0f) return false;
		
		float w = calculator.Dot(calculator.Cross(pq, pa), pd);
		if (w < 0.0f) return false;
	}

	return true;
}

// 距離で見る当たり判定。距離が判定の値より短いと当たっている
bool Collision::Distance_Collition(float distance, float judge_value) {
	return distance < judge_value;
}

// プレイヤーとエネミーの当たり判定。距離で行う
bool Collision::Player_To_Enemy(std::shared_ptr<Player> player, std::shared_ptr<Enemy> enemy) {
	// プレイヤー、エネミー間の距離
	auto distance = Get_Distance(player->Get_Position(), enemy->Get_Position());
	// お互いの幅を足したもの
	auto judge_value = player->Get_Size().depth + enemy->Get_Size().height;

	return Distance_Collition(distance, judge_value);
}

// 線分と平面の交点を求める
Vector3D Collision::Get_Intersection(Vector3D vector1, Vector3D vector2, Vector3D start_point, Vector3D end_point, Rect face) {
	auto dot1 = calculator.Dot(vector1, face.Get_Centor_Position());
	auto dot2 = calculator.Dot(vector2, face.Get_Centor_Position());

	// ベクトル
	auto vector = calculator.Make_Vector(end_point, start_point);
	// 交点から、始点の距離 : 終点の距離の比率
	auto ratio = std::abs(dot1) / (std::abs(dot1) + std::abs(dot2));

	// 交点を格納
	Vector3D result;
	result.x = start_point.x + (vector.x + ratio);
	result.y = start_point.y + (vector.y + ratio);
	result.z = start_point.z + (vector.z + ratio);
	
	return result;
}
