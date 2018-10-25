#include<memory>

#include"DxLib.h"
#include"Game_Manager.h"
#include"Scene_Base.h"
#include"Key_Checker.h"

// メイン
int WINAPI WinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int /*nCmdShow*/) {
	// 定数をまとめておく構造体
	Define_Value define_value;
	// ゲームの進行を管理するクラス
	std::unique_ptr<Game_Manager>& game_manager = Game_Manager::Get_Instance();
	// キー入力をチェックするクラス
	std::unique_ptr<Key_Checker>& key_Checker = Key_Checker::Get_Instance();

	// 常時ウィンドウモードで起動
	ChangeWindowMode(TRUE);
	// ウィンドウのサイズを決める
	SetGraphMode(define_value.WINDOW_X, define_value.WINDOW_Y, 0);

	// 初期化処理
	if (DxLib_Init() == -1) {
		// エラーが起きたら終了
		return -1;
	}

	// 最初のシーンへ
	game_manager->Change_Scene(game_manager->scene_state);

	// ゲームループ
	while (ProcessMessage() != -1) {
		// 裏画面消す
		ClearDrawScreen();
		// 描画先を裏画面に
		SetDrawScreen(DX_SCREEN_BACK);

		key_Checker->Update_Key();
		game_manager->Update();
		game_manager->Render();

		// FPSを60で固定
		int startTime = GetNowCount();
		int endTime = GetNowCount();
		WaitTimer(1000 / 60 - (endTime - startTime));

		// 裏画面を表画面にコピー
		ScreenFlip();
	}

	// 終了処理
	DxLib_End();

	return 0;
}