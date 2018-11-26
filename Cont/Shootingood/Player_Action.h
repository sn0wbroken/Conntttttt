#pragma once

#include"DxLib.h"
#include"Enum.h"
#include"Key_Checker.h"

#include<memory>
#include<functional>

// プレイヤーの行動を管理するクラス
class Player_Action {
public:
	// コンストラクタ
	Player_Action();
	
	// デストラクタ
	~Player_Action();

	// プレイヤーの操作をまとめる 毎フレーム呼び出し
	void Player_Controll();

	// 毎フレーム呼ばれる
	void Update();

	// 初期化
	void Initialize();

private:
	// 定数をまとめておくクラス
	Define_Value define_value;

	// キー入力をチェックするクラス
	std::unique_ptr<Key_Checker>& key_checker = Key_Checker::Get_Instance();
};
