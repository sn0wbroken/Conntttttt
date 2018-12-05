#pragma once

#include"DxLib.h"

// 定数をまとめる
class Define_Value {
public:
	// 画面サイズ 幅
	static const int WINDOW_X = 800;
	// 画面サイズ 高さ
	static const int WINDOW_Y = 600;
	// UI表示スペース
	static constexpr float UI_SPACE = 180.0f;

	// ゲーム画面の左端
	int MIN_SCREEN_X = 0;
	// ゲーム画面の右端(WINDOW_X - UI_SPACE)
	static constexpr float MAX_SCREEN_X = 620.0f;
	// 画面の上端
	static const int MIN_WINDOW_Y = 0;
	// 画面の下端
	static const int MAX_WINDOW_Y = 600;

	// UIを表示するときのX座標
	static constexpr float UI_X = 640.0f;
	// UIを表示するときのY座標の基準値
	static constexpr float UI_BASE_Y = 50.0f;
	// UI同士のスペース
	static constexpr float FELLOW_UI_SPACE = 40.0f;

	// キーの数
	static const int KEY_NUMEBR = 256;

	// 弾の半径
	static constexpr float BULLET_RADIUS = 2.0f;

	// 最終ステージ enumに合わせて0からのカウント
	static const int FINAL_STAGE = 2;

	// 調整用変数 UIの表示位置に使用
	static constexpr float  ADJUSTMENT_VALUE = 1.0f;


#pragma region プレイヤー

	// プレイヤーの最大体力
	static const int PLAYER_MAX_LIFE = 3;
	// プレイヤーの大きさ(幅)
	static constexpr float PLAYER_WIDTH = 48.0f;
	// プレイヤーの大きさ(高さ)
	static constexpr float PLAYER_HEIGHT = 48.0f;
	// プレイヤーの回転速度(度数法6)
	static constexpr float PLAYER_SPEED = 6.0f;
	// プレイヤーの攻撃力
	static const int PLAYER_ATTACK = 1;
	// プレイヤーの撃つ弾の速度
	static constexpr float PLAYER_BULLET_SPEED = 15.0f;
	// プレイヤーの初期残機
	static const int PLAYER_INITIALIZE_LIFE = 3;
	// プレイヤーの回転速度
	static constexpr float PLAYER_ROTATE_SPEED = 6.0f;
	// プレイヤーが飛ばす弾の最大保持数(ボムの時に使う)
	static const int MAX_BULLET = 100;

#pragma endregion

#pragma region エネミー

	// 敵の体力の最大値
	static const int ENEMY_MAX_HP = 30;
	// エネミーの大きさ(幅)
	static constexpr float ENEMY_WIDTH = 54.0f;
	// エネミーの大きさ(高さ)
	static constexpr float ENEMY_HEIGHT = 36.0f;
	// 出現するエネミーの数
	static const int ENEMY_NUMBER = 5;

#pragma endregion

#pragma region 選択アイコン (タイトルにあるどれを選んでいるかの三角形のこと)

	// 選択アイコンの幅
	static constexpr float DECIDE_ICON_WIDTH = 33.0f;
	// 選択アイコンの高さ
	static constexpr float DECIDE_ICON_HEIGHT = 30.0f;
	// 選択アイコンの初期x座標
	static constexpr float INITIALIZE_POSITION_X = 550.0f;
	// 選択アイコンの初期y座標
	static constexpr float INITIALIZE_POSITION_Y = 317.0f;
	// 選択アイコンの移動量
	static constexpr float ICON_MOVE_VALUE = 70.0f;

#pragma endregion

#pragma region マニュアル

	// マニュアルの最大ページ数。配列のサイズに合わせてある
	static const int MAX_PAGE_NUBER = 2;

#pragma endregion

	//TEST
	static constexpr float ROTATION_VALUE = 6;
};