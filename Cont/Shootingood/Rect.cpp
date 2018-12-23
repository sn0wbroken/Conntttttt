#include "Rect.h"

// 基準となる矩形、サイズを受け取り当たり判定用の箱を作って返す。基準矩形は天井部。
std::unordered_map<std::string, Rect> Rect::Make_3DBox(Rect top_face, Object_Size size, std::unordered_map<std::string, Rect>& rects) {
	Rect front_face;
	front_face.top_right    = top_face.bottom_right;
	front_face.top_left     = top_face.bottom_left;
	front_face.bottom_right = front_face.top_right.Subtract_VectorY(size.height);
	front_face.bottom_left  = front_face.top_left.Subtract_VectorY(size.height);
	rects["front_face"] = front_face;

	Rect back_face;
	back_face.top_right    = top_face.top_right;
	back_face.top_left     = top_face.top_left;
	back_face.bottom_right = back_face.top_right.Subtract_VectorY(size.height);
	back_face.bottom_left  = back_face.top_left.Subtract_VectorY(size.height);
	rects["back_face"] = back_face;


	return rects;
}

// オブジェクトの大きさと座標から天井を作って返す。受け取る座標は作る矩形の最大点
Rect Rect::Make_Top_Face(Vector3D position, Object_Size size) {
	// 矩形の最大点の座標
	Vector3D top_vertex = VGet(position.x + size.Get_Helf_Width(), position.y + size.height, position.z + size.Get_Helf_Depth());

	Rect result;
	result.top_right    = top_vertex;
	result.top_left     = top_vertex.Subtract_VectorX(size.width);
	result.bottom_right = top_vertex.Subtract_VectorZ(size.depth);
	result.bottom_left  = result.top_left.Subtract_VectorZ(size.depth);
	return result;
}

// 面の中心座標を返す
Vector3D Rect::Get_Centor_Point(float width, float height, float depth, Vector3D max_vertex) {
	Vector3D vector3;
	vector3 = vector3.Get_Vector(max_vertex.x - width, max_vertex.y - height, max_vertex.z - depth);

	return vector3;
}
