#pragma once

#include"Vector3D.h"
#include"Object_Size.h"

#include<memory>
#include<string>
#include<unordered_map>

// 対角線で割った時にできる三角形。当たり判定に使用
struct Triangle {
	Vector3D vertex1;
	Vector3D vertex2;
	Vector3D vertex3;

	// 各頂点の座標を設定し、三角形を作る
	void Set_Triangle(Vector3D set_vertex_1, Vector3D set_vertex_2, Vector3D set_vertex_3) {
		vertex1 = set_vertex_1;
		vertex2 = set_vertex_2;
		vertex3 = set_vertex_3;
	};
};

// 矩形クラス
class Rect {
public:
	// コンストラクタ
	Rect() {};
	
	// 基準となる矩形、サイズを受け取り、当たり判定用の箱を作って返す。基準矩形は天井部。
	std::unordered_map<std::string ,Rect> Make_3DBox(Rect top_face, Object_Size size, std::unordered_map<std::string, Rect>& rects);

	// オブジェクトの大きさと座標から天井を作って返す。受け取る座標は作る矩形の最大点
	Rect Make_Top_Face(Vector3D posiotin, Object_Size size);

	// 貼られているモデルに合わせて動かす
	void Move(std::unordered_map<std::string, Rect>& rects, float speed, float radian);

	// 前面の中心座標を設定する
	void Set_Centor_Position();
	// 前面の中心座標を返す
	Vector3D Get_Centor_Position();

	// 法線ベクトルを返す
	void Set_Normal_Vector(Rect& rect);
	
	// 矩形を回転させる
	std::unordered_map<std::string, Rect> Rotation_Rectangle(std::unordered_map<std::string, Rect>& rects, Vector3D axis, float radian);

	// 四角形の左上隅の座標
	Vector3D top_left;
	// 四角形の左下隅の座標
	Vector3D bottom_left;
	// 四角形の右下隅の座標
	Vector3D bottom_right;
	// 四角形の角で一番大きいもの(基準点に使う)
	Vector3D top_right;
	// 法線ベクトル。線分との判定に使う
	Vector3D normal_vector;

	// 幅
	float width;
	// 高さ
	float height;

	// 面の中心座標
	Vector3D center_position;
	// 分割したときの3角形2つを格納
	Triangle triangles[2];

	// 自身を対角線で分断し、2つの三角形に分ける
	void Split_Rect();

private:
	// 3次元数の取得、計算に使用
	Vector3D calcurator;

	/*// 指定された点を含むかどうかを判定するメソッド
	inline bool contains(const float x, const float y) const throw() {
		return x >= left && x < right && y >= top && y < bottom;
	}
	inline bool contains(const Vector3D point) const throw()
	{
		return contains(point.x, point.y);
	}

	//当たり判定 四角 クラス渡す
	bool Intersects(const Rect<T> &right) {
		return left < right.right &&
			top < right.bottom &&
			right.top < bottom &&
			right.left < this->right;
	}
	//当たり判定 四角 指定バージョン
	bool Intersects(T aTop, T aLeft, T aRight, T aBottom) {
		return left < right && top < bottom && left < right && top < bottom;
	}
	*/
};
