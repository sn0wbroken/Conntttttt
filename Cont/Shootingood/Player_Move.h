#pragma once

#define _USE_MATH_DEFINES

#include"DxLib.h"
#include"Define_Value.h"
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

	// キー入力でプレイヤーを移動させる
	void Move();
	// キー入力でプレイヤーを回転させる
	void Rotation();

private:
	// 定数をまとめておくクラス
	Define_Value define_value;

	std::shared_ptr<Player> player;
	std::shared_ptr<Player_Status> player_status;
};

