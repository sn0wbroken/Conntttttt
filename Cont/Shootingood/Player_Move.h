#pragma once

#define _USE_MATH_DEFINES

#include"DxLib.h"
#include"Player.h"
#include"Player_Status.h"

#include<cmath>
#include<memory>

// プレイヤーの移動を管理する
class Player_Move {
public:
	// コンストラクタ
	Player_Move();
	// コピーコンストラクタ
	Player_Move(std::shared_ptr<Player> set_player, std::shared_ptr<Player_Status> set_player_status);
	// デストラクタ
	~Player_Move();

	// プレイヤーを移動させる
	void Move();

private:
	std::shared_ptr<Player> player;
	std::shared_ptr<Player_Status> player_status;
};

