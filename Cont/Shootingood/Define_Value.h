#pragma once

// 定数をまとめる
class Define_Value {
public:
	// 画面サイズ 幅
	static const int WINDOW_X = 800;
	// 画面サイズ 高さ
	static const int WINDOW_Y = 600;
	// UI表示スペース
	static const int UI_SPACE = 180;

	// ゲーム画面の左端
	static const int MIN_SCREEN_X = 0;
	// ゲーム画面の右端(WINDOW_X - UI_SPACE)
	static const int MAX_SCREEN_X = 620;
	// 画面の上端
	static const int MIN_WINDOW_Y = 0;
	// 画面の下端
	static const int MAX_WINDOW_Y = 600;

	// UIを表示するときのX座標
	static const int UI_X = 640;
	// UIを表示するときのY座標の基準値 
	static const int UI_BASE_Y = 50;
	// UI同士のスペース
	static const int FELLOW_UI_SPACE = 40;

	// キーの数
	static const int KEY_NUMEBR = 256;

	// 弾の半径
	static const int BULLET_RADIUS = 2;

	// 最終ステージ enumに合わせて0からのカウント
	static const int FINAL_STAGE = 2;

	// 調整用変数 UIの表示位置に使用
	static const int  ADJUSTMENT_VALUE = 1;

#pragma region プレイヤー

	// プレイヤーの最大体力
	static const int PLAYER_MAX_LIFE = 3;
	// プレイヤーの大きさ(幅)
	static const int PLAYER_WIDTH  = 48;
	// プレイヤーの大きさ(高さ)
	static const int PLAYER_HEIGHT = 48;
	// プレイヤーの移動速度
	static const int PLAYER_SPEED = 6;
	// プレイヤーの攻撃力
	static const int PLAYER_ATTACK = 1;
	// プレイヤーの撃つ弾の速度
	static const int PLAYER_BULLET_SPEED = 15;
	// プレイヤーの初期残機
	static const int PLAYER_INITIALIZE_LIFE = 3;

#pragma endregion

#pragma region エネミー

	// 敵の体力の最大値
	static const int ENEMY_MAX_HP = 30;
	// エネミーの大きさ(幅)
	static const int ENEMY_WIDTH = 54;
	// エネミーの大きさ(高さ)
	static const int ENEMY_HEIGHT = 36;
	// 出現するエネミーの数
	static const int ENEMY_NUMBER = 5;

#pragma endregion

#pragma region 選択アイコン (タイトルにあるどれを選んでいるかの三角形のこと)

	// 選択アイコンの幅
	static const int DECIDE_ICON_WIDTH = 33;
	// 選択アイコンの高さ
	static const int DECIDE_ICON_HEIGHT = 30;
	// 選択アイコンの初期x座標
	static const int INITIALIZE_POSITION_X = 550;
	// 選択アイコンの初期y座標
	static const int INITIALIZE_POSITION_Y = 317;
	// 選択アイコンの移動量
	static const int ICON_MOVE_VALUE = 70;

#pragma endregion

#pragma region マニュアル

	// マニュアルの最大ページ数。配列のサイズに合わせてある
	static const int MAX_PAGE_NUBER = 2;

#pragma endregion

};
