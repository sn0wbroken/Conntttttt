#pragma once

// オブジェクトのサイズをまとめて保持
class Object_Size {
public:
	// コンストラクタ
	Object_Size() {};

	// コピーコンストラクタ
	Object_Size(float set_width, float set_height, float set_depth) :
	width(set_width),
	height(set_height),
	depth(set_depth) {};

	// 幅
	float width;
	// 高さ
	float height;
	// 奥行
	float depth;

	// 幅の半分の値を取得
	float Get_Helf_Width() {
		return width / 2;
	}
	// 高さの半分の値を取得
	float Get_Helf_Height() {
		return height / 2;
	}	
	// 奥行の半分の値を取得
	float Get_Helf_Depth() {
		return depth / 2;
	}
	
	// 大きさを設定する
	void Set_Size(float set_width, float set_height, float set_depth) {
		width = set_width;
		height = set_height;
		depth = set_depth;
	}
};