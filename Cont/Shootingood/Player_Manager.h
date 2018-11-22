#pragma once

#include"Player.h"
#include"Define_Value.h"
#include"Player_Status.h"
#include"Player_Action.h"
#include"Player_Weapon.h"
#include"Unique_Component.h"

#include<memory>

// プレイヤーのマネージャークラス
class Player_Manager : public Unique_Component<Player_Manager> {
public:
	// プレイヤー本体のクラス
	std::shared_ptr<Player> player;
	// プレイヤーのステータス関係を扱うクラス
	std::shared_ptr<Player_Status> player_status;
	// プレイヤーの行動を管理するクラス
	std::shared_ptr<Player_Action> player_action;
	// プレイヤーの持つ武器のクラス
	std::shared_ptr<Player_Weapon> player_weapon;

	// デストラクタ
	~Player_Manager() {};

private:
	// コンストラクタ
	Player_Manager();

	// 定数をまとめておく構造体
	Define_Value define_value;

	// 引数に自身を指定したものだけに生成をゆるす
	friend class Unique_Component<Player_Manager>;
};
