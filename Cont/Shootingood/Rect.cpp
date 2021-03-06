#include "Rect.h"

// 基準となる矩形、サイズを受け取り当たり判定用の箱を作って返す。基準矩形は天井部。
std::unordered_map<std::string, Rect> Rect::Make_3DBox(Rect top_face, Object_Size size, std::unordered_map<std::string, Rect>& rects) {
	// 左面作成
	Rect left_face;
	// 4つの頂点の座標を設定
	left_face.top_right    = top_face.top_right;
	left_face.top_left     = top_face.top_left;
	left_face.bottom_right = left_face.top_right.Subtract_VectorY(size.height);
	left_face.bottom_left  = left_face.top_left.Subtract_VectorY(size.height);
	
	// 幅、高さを設定
	left_face.width  = left_face.top_right.x - left_face.top_left.x;
	left_face.height = size.height;

	// 面の中心点を設定
	left_face.Set_Centor_Position();
	// 法線ベクトルを求める
	Set_Normal_Vector(left_face);
	rects["left_face"] = left_face;
	
	// 右面作成
	Rect right_face;
	right_face.top_right    = top_face.bottom_right;
	right_face.top_left     = top_face.bottom_left;
	right_face.bottom_right = right_face.top_right.Subtract_VectorY(size.height);
	right_face.bottom_left  = right_face.top_left.Subtract_VectorY(size.height);
	
	right_face.width  = right_face.top_right.x - right_face.top_left.x;
	right_face.height = size.height;

	// 面の中心点を設定
	right_face.Set_Centor_Position();
	// 法線ベクトルを求める
	Set_Normal_Vector(right_face);
	rects["right_face"] = right_face;
	
	// 前面作成
	Rect front_face;
	front_face.top_right    = top_face.top_right;
	front_face.top_left     = top_face.bottom_right;
	front_face.bottom_right = front_face.top_right.Subtract_VectorY(size.height);
	front_face.bottom_left  = front_face.top_left.Subtract_VectorY(size.height);
	
	front_face.width  = front_face.top_right.z - front_face.top_left.z;
	front_face.height = size.height;

	// 面の中心点を設定
	front_face.Set_Centor_Position();
	// 法線ベクトルを求める
	Set_Normal_Vector(front_face);
	rects["front_face"] = front_face;
	
	// 背面作成
	Rect back_face;
	back_face.top_right    = top_face.bottom_left;
	back_face.top_left     = top_face.top_left;
	back_face.bottom_right = back_face.top_right.Subtract_VectorY(size.height);
	back_face.bottom_left  = back_face.top_left.Subtract_VectorY(size.height);
	
	back_face.width  = back_face.top_left.z - back_face.top_right.z;
	back_face.height = size.height;
	
	// 面の中心点を設定
	back_face.Set_Centor_Position();
	// 法線ベクトルを求める
	Set_Normal_Vector(back_face);
	rects["back_face"] = back_face;

	return rects;
}

// オブジェクトの大きさと座標から天井を作って返す。受け取る座標は作る矩形の最大点
Rect Rect::Make_Top_Face(Vector3D position, Object_Size size) {
	// 矩形の最大点の座標
	Vector3D top_vertex = VGet(position.x + size.Get_Helf_Depth(), position.y + size.height, position.z + size.Get_Helf_Width());

	//上面を作成
	Rect result;
	result.top_right    = top_vertex;
	result.top_left     = top_vertex.Subtract_VectorX(size.depth);
	result.bottom_right = top_vertex.Subtract_VectorZ(size.width);
	result.bottom_left  = result.top_left.Subtract_VectorZ(size.width);

	result.Set_Centor_Position();

	result.width  = top_right.x - bottom_right.x;
	result.height = size.height;
	
	return result;
}

// 貼られているモデルに合わせて動かす
void Rect::Move(float speed, float radian) {
	// 矩形(自分の持っている頂点)の移動
	top_right   .Move(speed * cosf(radian), 0.0f, speed * sinf(radian));
	top_left    .Move(speed * cosf(radian), 0.0f, speed * sinf(radian));
	bottom_left .Move(speed * cosf(radian), 0.0f, speed * sinf(radian));
	bottom_right.Move(speed * cosf(radian), 0.0f, speed * sinf(radian));
}

// 前面の中心座標を設定する
void Rect::Set_Centor_Position() {
	center_position = calcurator.Get_Vector(top_right.x - (width / 2), top_right.y - (height / 2), top_right.z);
}
// 前面の中心座標を返す
Vector3D Rect::Get_Centor_Position() {
	return center_position;
}

// 法線ベクトルを求めて設定する
void Rect::Set_Normal_Vector(Rect& rect) {
	Vector3D result;

	auto vec1 = calcurator.Make_Vector(rect.center_position, rect.top_left);
	auto vec2 = calcurator.Make_Vector(rect.center_position, rect.top_right);
	result = calcurator.Cross(vec1, vec2);

	result.x = vec2.y * vec1.z - vec1.y * vec2.z;
	result.y = vec2.x * vec1.z - vec1.x * vec2.z;
	result.z = vec2.x * vec1.y - vec1.x * vec2.y;

	rect.normal_vector = result;
}

// 矩形を回転させる
std::unordered_map<std::string, Rect> Rect::Rotation_Rectangle(std::unordered_map<std::string, Rect>& rects, Vector3D axis, float radian) {
	// rectsに格納されている矩形全てを回転させる
	for (auto iterator = begin(rects); iterator != end(rects); ++iterator) {
		auto rotate_value = MMult(MGetTranslate(VScale(axis, -1.0f)), MMult(MGetRotY(radian), MGetTranslate(axis)));

		iterator->second.top_right    = VTransform(iterator->second.top_right   , rotate_value);
		iterator->second.top_left     = VTransform(iterator->second.top_left    , rotate_value);
		iterator->second.bottom_right = VTransform(iterator->second.bottom_right, rotate_value);
		iterator->second.bottom_left  = VTransform(iterator->second.bottom_left , rotate_value);

		if (iterator == rects.find("front_face")) {
			iterator->second.center_position = VTransform(iterator->second.center_position, rotate_value);
		}
	}

	return rects;
}
