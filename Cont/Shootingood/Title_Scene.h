#pragma once

#include"Enum.h"
#include"Scene_Base.h"
#include"Key_Checker.h"
#include"Manual.h"
#include"CSVData.h"

#include<memory>

// タイトルシーン
class Title_Scene : public Scene_Base {
public:
	// コンストラクタ
	Title_Scene();
	// デストラクタ
	~Title_Scene() {};

	// 毎フレーム呼ばれる処理
	void Update() override;
	// 描画
	void Render() override;

private:
	// マニュアルを管理するクラス
	std::shared_ptr<Manual> manual;

	// 選択アイコンを動かす
	void Icon_Move();

	// 操作に応じて選択しているものを変える
	void Change_Decide(eSelect_Command now_decide, int which_key);

	// 定数をまとめておくクラス
	Define_Value define_value;

	// 何を選択しているか
	eSelect_Command select_command;

	// キー入力をチェックするクラス
	std::unique_ptr<Key_Checker>& key_checker = Key_Checker::Get_Instance();

	// 選択アイコンのx座標
	int icon_position_x;
	// 選択アイコンのy座標
	int icon_position_y;
	// 選択アイコンの幅
	int icon_width;
	// 選択アイコンの高さ
	int icon_height;

	// マニュアルを見ているか。選択されたらtrueに
	bool is_watch_manual;
};
