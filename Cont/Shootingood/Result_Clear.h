#pragma once

#include"Scene_Base.h"
#include"Scene_Manager.h"

class Result_Clear : public Scene_Base {
public:
	// コンストラクタ
	Result_Clear() {};
	// デストラクタ
	~Result_Clear() {};

	// 毎フレーム入る
	void Update() override;
	// 描画
	void Render() override;

private:
	// 定数をまとめておくクラス
	Define_Value define_value;

	// キー入力をチェックするクラス
	std::unique_ptr<Key_Checker>& key_checker = Key_Checker::Get_Instance();
};
