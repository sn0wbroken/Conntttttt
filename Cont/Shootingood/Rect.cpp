#include "Rect.h"

// 基準となる矩形、サイズを受け取り当たり判定用の箱を作って返す。基準矩形は天井部。
std::unordered_map<std::string, Rect> Rect::Make_3DBox(Rect top_face, Object_Size size, std::unordered_map<std::string, Rect>& rects) {
	// 前面作成
	Rect front_face;
	// 4つの頂点の座標を設定
	front_face.top_right    = top_face.top_right;
	front_face.top_left     = top_face.top_left;
	front_face.bottom_right = front_face.top_right.Subtract_VectorY(size.height);
	front_face.bottom_left  = front_face.top_left.Subtract_VectorY(size.height);
	
	// 幅、高さを設定
	front_face.width  = front_face.top_right.x - front_face.top_left.x;
	front_face.height = size.height;

	// 面の中心点を設定
	front_face.Set_Centor_Position();
	//TEST
	Get_Normal_Vector(front_face);
	rects["front_face"] = front_face;
	
	// 背面作成
	Rect back_face;
	back_face.top_right    = top_face.bottom_right;
	back_face.top_left     = top_face.bottom_left;
	back_face.bottom_right = back_face.top_right.Subtract_VectorY(size.height);
	back_face.bottom_left  = back_face.top_left.Subtract_VectorY(size.height);
	
	back_face.width  = back_face.top_right.x - back_face.top_left.x;
	back_face.height = size.height;

	rects["back_face"] = back_face;
	
	// 右面作成
	Rect right_face;
	right_face.top_right    = top_face.top_right;
	right_face.top_left     = back_face.top_right;
	right_face.bottom_right = right_face.top_right.Subtract_VectorY(size.height);
	right_face.bottom_left  = right_face.top_left.Subtract_VectorY(size.height);
	
	right_face.width  = right_face.top_right.x - right_face.top_left.x;
	right_face.height = size.height;

	rects["right_face"] = right_face;
	
	// 左面作成
	Rect left_face;
	left_face.top_right    = top_face.top_left;
	left_face.top_left     = top_face.bottom_left;
	left_face.bottom_right = left_face.top_right.Subtract_VectorY(size.height);
	left_face.bottom_left  = left_face.top_left.Subtract_VectorY(size.height);
	
	left_face.width  = left_face.top_right.x - left_face.top_left.x;
	left_face.height = size.height;
	
	rects["left_face"] = left_face;

	return rects;
}

// オブジェクトの大きさと座標から天井を作って返す。受け取る座標は作る矩形の最大点
Rect Rect::Make_Top_Face(Vector3D position, Object_Size size) {
	// 矩形の最大点の座標
	Vector3D top_vertex = VGet(position.x + size.Get_Helf_Width(), position.y + size.height, position.z + size.Get_Helf_Depth());

	//上面を作成
	Rect result;
	result.top_right    = top_vertex;
	result.top_left     = top_vertex.Subtract_VectorX(size.width);
	result.bottom_right = top_vertex.Subtract_VectorZ(size.depth);
	result.bottom_left  = result.top_left.Subtract_VectorZ(size.depth);

	result.Set_Centor_Position();

	result.width  = top_right.x - top_left.x;
	result.height = size.height;
	
	return result;
}

// 貼られているモデルに合わせて動かす
void Rect::Move(std::unordered_map<std::string, Rect>& rects, float speed, float radian) {
	// rectsに格納されている矩形全てを回転させる
	for (auto iterator = begin(rects); iterator != end(rects); ++iterator) {
		iterator->second.top_right   .Move(speed * cosf(radian), 0.0f, speed * sinf(radian));
		iterator->second.top_left    .Move(speed * cosf(radian), 0.0f, speed * sinf(radian));
		iterator->second.bottom_right.Move(speed * cosf(radian), 0.0f, speed * sinf(radian));
		iterator->second.bottom_left .Move(speed * cosf(radian), 0.0f, speed * sinf(radian));
		
		//TODO: 少々雑か？
		if (iterator == rects.find("front_face")) {
			iterator->second.centor_positon.Move(speed * cosf(radian), 0.0f, speed * sinf(radian));
		}
	}
}

// 前面の中心座標を設定する
void Rect::Set_Centor_Position() {
	centor_positon = vector.Get_Vector(top_right.x - (width / 2), top_right.y - (height / 2), top_right.z);
}
// 前面の中心座標を返す
Vector3D Rect::Get_Centor_Position() {
	return centor_positon;
}

// 法線ベクトルを返す
Vector3D Rect::Get_Normal_Vector(Rect rect) {
	Vector3D result;
	
	auto AO = vector.Hoge(rect.centor_positon, rect.top_left);
	auto BO = vector.Hoge(rect.centor_positon, rect.top_right);

	//TODO:機能ある cross
	result.x = BO.y * AO.z - AO.y * BO.z;
	result.y = BO.x * AO.z - AO.x * BO.z;
	result.z = BO.x * AO.y - AO.x * BO.y;

	return result;
}

// 矩形を回転させる //TODO:mapをイテレータで回すのよろしくない？
std::unordered_map<std::string, Rect> Rect::Rotation_Rectangle(std::unordered_map<std::string, Rect>& rects, float radian) {
	// rectsに格納されている矩形全てを回転させる
	for (auto iterator = begin(rects); iterator != end(rects); ++iterator) {
		MATRIX matrix;

		matrix = MGetRotY(radian);

//		auto t = MMult(MGetTranslate(MGetTranslate(VScale(collision_centor, -1.0f)), MMult(MGetRotZ(radian), MGetTranslate(centor_position));

		iterator->second.top_right    = VTransform(iterator->second.top_right   , matrix);
		iterator->second.top_left     = VTransform(iterator->second.top_left    , matrix);
		iterator->second.bottom_right = VTransform(iterator->second.bottom_right, matrix);
		iterator->second.bottom_left  = VTransform(iterator->second.bottom_left , matrix);

		//TODO: 少々雑か？
		if (iterator == rects.find("front_face")) {
			iterator->second.centor_positon = VTransform(iterator->second.centor_positon, matrix);
		}
	}

	return rects;
}
