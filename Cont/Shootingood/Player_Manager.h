#pragma once

#include"Player.h"
#include"Player_Status.h"
#include"Player_Action.h"
#include"Unique_Component.h"

#include"Define_Value.h"

#include<memory>

// プレイヤーのマネージャークラス
class Player_Manager : public Unique_Component<Player_Manager> {
public:
	// 毎フレーム呼ばれる
	void Update();

	// プレイヤー本体のクラス
	std::shared_ptr<Player> player = std::make_shared<Player>();
	// プレイヤーのステータス関係を扱うクラス
	std::shared_ptr<Player_Status> player_status = std::make_shared<Player_Status>();
	// プレイヤーの行動を管理するクラス
	std::shared_ptr<Player_Action> player_action = std::make_shared<Player_Action>(player, player_status);

	// デストラクタ
	~Player_Manager() {};

private:
	// コンストラクタ
	Player_Manager() {};

	// 定数をまとめておく構造体
	Define_Value define_value;

	// 引数に自身を指定したものだけに生成をゆるす
	friend class Unique_Component<Player_Manager>;
};
