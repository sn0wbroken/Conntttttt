#pragma once

#include"DxLib.h"
#include"Enum.h"
#include"Player.h"
#include"Player_Move.h"
#include"Key_Checker.h"
#include"Player_Status.h"

#include<memory>
#include<functional>

// プレイヤーの行動を管理するクラス
class Player_Action {
public:
	// コンストラクタ
	Player_Action(std::shared_ptr<Player> player,
				  std::shared_ptr<Player_Status> player_statsu);
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

	// プレイヤー本体のクラス
	std::shared_ptr<Player> player;
	// プレイヤーの移動を管理するクラス
	std::shared_ptr<Player_Move> player_move;
	// プレイヤーのステータス関係のクラス
	std::shared_ptr<Player_Status> player_status;

	// キー入力をチェックするクラス
	std::unique_ptr<Key_Checker>& key_checker = Key_Checker::Get_Instance();
};
