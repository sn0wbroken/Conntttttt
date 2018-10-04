#pragma once

#include"UI.h"
#include"Collision.h"
#include"Scene_Base.h"
#include"Key_Checker.h"
#include"Enemy_Manager.h"
#include"Player_Manager.h"

#include<memory>

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

	// プレイヤーとエネミーが衝突したかどうか
	bool Is_Hit_Actor_Fellow();
	// プレイヤーがエネミーの攻撃を受けたかどうか
	bool Is_Enemy_Attack_Hit();
	// エネミーが全滅したかどうか
	bool Is_Enemy_All_Ded();

	// プレイヤーの攻撃が敵に命中したか
	void Is_Player_Attack_Hit();

private:
	// プレイヤーが死亡したときの処理
	void Player_Dead();

	// 定数をまとめておく構造体
	Define_Value define_value;

	// キー入力をチェックするクラス
	std::unique_ptr<Key_Checker>& key_checker = Key_Checker::Get_Instance();

	// UI表示クラス
	std::shared_ptr<UI> UI_class;

	// プレイヤーのマネージャクラス
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	// プレイヤー本体のクラス
	std::shared_ptr<Player> player;
	// プレイヤーの行動を管理するクラス
	std::shared_ptr<Player_Action> player_action;

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