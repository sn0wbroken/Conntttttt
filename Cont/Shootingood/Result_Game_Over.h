#pragma once

#include"Scene_Base.h"
#include"Key_Checker.h"

// リザルトシーン
class Result_Game_Over : public Scene_Base {
public:
	// コンストラクタ
	Result_Game_Over() {};
	// デストラクタ
	~Result_Game_Over() {};

	// 毎フレーム入る
	void Update() override;
	// 描画
	void Render() override;

private:
	// 定数をまとめておく構造体
	Define_Value define_value;

	// キー入力をチェックするクラス
	std::unique_ptr<Key_Checker>& key_checker = Key_Checker::Get_Instance();
};
