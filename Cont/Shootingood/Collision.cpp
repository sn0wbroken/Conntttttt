#include "Collision.h"

Collision::Collision() {

}

// 毎フレーム呼ばれる更新処理
void Collision::Update() {
	//std::unique_ptr<Actor>& actor = Actor::Get_Instance();
	////TEST
	//Line_To_Face(std::static_pointer_cast<Enemy>(actor->children["Enemy_1"]));
	//Line_To_Face(std::static_pointer_cast<Enemy>(actor->children["Enemy_2"]));
	std::unique_ptr<Enemy_Manager>& enemy_manager = Enemy_Manager::Get_Instance();
	auto enemys = enemy_manager->active_enemies;
	for (auto enemy : enemys) {
		Line_To_Face(enemy);
	}
}

// 引数の2点間の距離を求めて返す
float Collision::Get_Distance(Vector3D coordinates_1, Vector3D coordinates_2) {
	return calculator.Norm_3D(coordinates_1.x, coordinates_1.y, coordinates_1.z, coordinates_2.x, coordinates_2.y, coordinates_2.z);
}

// 線分と平面(プレイヤーの通常攻撃とエネミーの前面)の当たり判定
bool Collision::Line_To_Face(std::shared_ptr<Enemy> enemy) {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	auto player_position = player_manager->player->vector3d;
	auto limit_fire_range = player_manager->player_weapon->Get_Limit_Range();
	auto front_face = enemy->rects["front_face"];
	auto normal_vector = front_face.normal_vector;

	//TODO:pla_posじゃなくて通常攻撃の出る位置か
	// 面の点から始点
	auto vector1 = calculator.Make_Vector(front_face.Get_Centor_Position(), player_position);
	// 面の点から終点
	auto vector2 = calculator.Make_Vector(front_face.Get_Centor_Position(), limit_fire_range);	
	// 面の点から始点の内積
	auto dot1 = calculator.Dot(vector1, normal_vector);
	// 面の点から始点の内積
	auto dot2 = calculator.Dot(vector2, normal_vector);
	
	// 線分が平面を貫いているか
	if (dot1 * dot2 <= 0) {
		// 交点を求める
		Vector3D intersection = Get_Intersection(vector1, vector2, limit_fire_range, player_position, front_face);
		// 交点が判定基準の面に接しているかを調べる
		if (Point_To_Rectangle(intersection,player_position, limit_fire_range, normal_vector, front_face)) {
			return true;
		}	
	}

	return false;
}

// 点が矩形に内接しているかを調べる 同一平面上にあることが前提
bool Collision::Point_To_Rectangle(Vector3D intersection, Vector3D start_point, Vector3D end_point, Vector3D normal_vector, Rect face) {
	face.Split_Rect();
	
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

		//float w = calculator.Scalar_Triple(pq, pb, pa);
	}

	//// 調べる線分のベクトル
	//auto segment_vector = calculator.Make_Vector(end_point, start_point);
	//auto vector1 = calculator.Make_Vector(end_point, face.triangles[0].vertex1);
	//
	//Vector3D e = calculator.Cross(segment_vector, vector1);
	//auto v = calculator.Dot()

	return true;
}

// 距離で見る当たり判定
bool Collision::Distance_Collition() {
		
	return true;
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
