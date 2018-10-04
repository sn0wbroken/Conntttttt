#pragma once

#include"DxLib.h"
#include"Define_Value.h"
#include"Enemy_Manager.h"
#include"Player_Manager.h"

#include<sstream>

// UI表示クラス
class UI {
public:
	// コンストラクタ
	UI();
	// デストラクタ
	~UI() {};

	// 描画
	void Render();

private:
	std::unique_ptr<Enemy_Manager>& enemy_manager   = Enemy_Manager::Get_Instance();
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();

	// エネミーの数を表示
	void Enemy_Number();
	// プレイヤーの攻撃タイプを表示
	void Player_Shot_Type();
	// 現在プレイ中のステージを表示
	void Now_Stage();
	// プレイヤーの残機を表示
	void Player_Life();
	
	// 定数をまとめておく構造体s
	Define_Value define_value;

	// UI表示域の背景
	int UI_background_graph;
};