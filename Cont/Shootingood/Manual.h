#pragma once

#include"DxLib.h"
#include"Define_Value.h"
#include"Key_Checker.h"

// 説明UIを管理するクラス
class Manual {
public:
	// コンストラクタ
	Manual();
	// デストラクタ
	~Manual();

	// 毎フレーム呼ばれる
	void Update();
	// 描画
	void Render();

	// マニュアルを閉じたときにページを最初に戻す
	void Set_Initialize_Page_Number(int intialize_page);

private:
	// 定数をまとめておくクラス
	Define_Value define_value;

	// キー入力をチェックするクラス
	std::unique_ptr<Key_Checker>& key_checker = Key_Checker::Get_Instance();

	// キー入力でページ送りをする
	void Page_Ejection();

	//TODO:マジックナンバー
	// マニュアルUIを格納する
	int manual_graph[3];
	
	// 現在閲覧中のページの番号
	int now_page_number;
};

