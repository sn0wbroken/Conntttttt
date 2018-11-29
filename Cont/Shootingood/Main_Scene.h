#pragma once

#include"TEST_GOD.h"

#include"UI.h"
#include"Actor.h"
#include"Collision.h"
#include"Scene_Base.h"
#include"Key_Checker.h"
#include"Enemy_Manager.h"

// メインシーン 
class Main_Scene : public Scene_Base {
public:
	// コンストラクタ
	Main_Scene();

	// 毎フレーム入る
	void Update() override;
	// 描画
	void Render() override;

	// 初期化
	void Initialize();

private:
	// プレイヤーが死亡したときの処理
	void Player_Dead();
	
	// 定数をまとめておくクラス
	Define_Value define_value;

	// UI表示クラス
	std::shared_ptr<UI> UI_class;

	// アクターの基底クラス
	std::shared_ptr<Actor> actor;

	// プレイヤー本体のクラス
	std::shared_ptr<Player> player;
	// プレイヤーの行動を管理するクラス
	std::shared_ptr<Player_Action> player_action;
	// プレイヤーのステータス関係のクラス
	std::shared_ptr<Player_Status> player_status;

	// 当たり判定を行うクラス
	std::shared_ptr<Collision> collision;

	// エネミーのマネージャクラス
	std::unique_ptr<Enemy_Manager>& enemy_manager = Enemy_Manager::Get_Instance();

	// 背景の座標を動かす
	void Scroll();

	// 背景1のy座標
	int y1;
	// 背景2のy座標
	int y2;

	// ゲーム開始までのインターバル。操作不能。エンターキーの押下で解除(ゲームスタート)
	bool is_interval;
};