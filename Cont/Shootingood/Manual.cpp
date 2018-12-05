#include "Manual.h"

// コンストラクタ
Manual::Manual() {
	manual_graph[0] = LoadGraph("Picture/Manual/スライド1.PNG");
	manual_graph[1] = LoadGraph("Picture/Manual/スライド2.PNG");
	manual_graph[2] = LoadGraph("Picture/Manual/スライド3.PNG");

	// スタートは0ページから
	now_page_number = 0;
}

// デストラクタ
Manual::~Manual() {
}

// 毎フレーム呼ばれる処理
void Manual::Update() {
	Page_Ejection();
}

// 描画
void Manual::Render() {
	DrawExtendGraph(0, 0, define_value.WINDOW_X, define_value.WINDOW_Y, manual_graph[now_page_number], TRUE);
}

// マニュアルを閉じたときにページを最初に戻す
void Manual::Set_Initialize_Page_Number(int intialize_page) {
	now_page_number = intialize_page;
}

// キー入力でページ送りをする
void Manual::Page_Ejection() {
	if (key_checker->key[KEY_INPUT_LEFT] == 1) {
		if (now_page_number <= 0) {
			return;
		}
		now_page_number--;
	}
	else if (key_checker->key[KEY_INPUT_RIGHT] == 1) {
		if (now_page_number >= define_value.MAX_PAGE_NUBER) {
			return;
		}
		now_page_number++;
	}
}