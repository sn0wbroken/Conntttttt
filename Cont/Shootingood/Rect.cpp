#include "Rect.h"

// キャラクターの当たり判定用の箱を作って返す
std::unordered_map<std::string, Rect> Rect::Make_3DBox(std::unordered_map<std::string, Rect>& rects) {
	std::unordered_map<std::string, Rect> result;

	return  rects;
}

// 面の中心座標を返す
Vector3D Rect::Get_Centor_Point(float width, float height, float depth, Vector3D max_vertex) {
	Vector3D vector3;
	vector3 = vector3.Get_Vector(max_vertex.x - width, max_vertex.y - height, max_vertex.z - depth);

	return vector3;
}
