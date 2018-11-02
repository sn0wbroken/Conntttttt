#pragma once

#define _USE_MATH_DEFINES

#include"DxLib.h"
#include"Enum.h"
#include"Player.h"
#include"Player_Move.h"
#include"Key_Checker.h"
#include"Player_Status.h"

#include<cmath>
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

	// プレイヤーのショットタイプ
	ePlayer_Shot_Type shot_type;

private:
	// 定数をまとめておく構造体
	Define_Value define_value;

	// プレイヤー本体のクラス
	std::shared_ptr<Player> player;
	// プレイヤーの移動を管理するクラス
	std::shared_ptr<Player_Move> player_move;
	// プレイヤーのステータス関係のクラス
	std::shared_ptr<Player_Status> player_status;

	// キー入力をチェックするクラス
	std::unique_ptr<Key_Checker>& key_checker = Key_Checker::Get_Instance();


	// 弾を発射
	void Fire();
	// 攻撃の種類を切り替える。毎フレーム受付ける
	void Change_Fire_Type();
	// 状態に応じたショットを設定する
	void Player_Action::Set_Shot_Pattern();

	// 打ち出した弾丸が画面外へ出ているかを判断する
	bool Player_Action::Check_Off_Screen(Bullet& player_Bullet);
	// 打ち出した弾丸が画面外に出ていたら消す
	void Player_Action::Bullet_Off_Screen_Erase();

	// 弾幕の種類 //TODO:変数名少しわかりづらいか
	std::function<void()> fire_type;

	// 角度
	float rad;
	// 弾が発射される位置
	double position_x;
	// sin波を作るために加算する値
	int counter;
	// 振れ幅
	double amplitude;
};
