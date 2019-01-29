#include"DxLib.h"
#include"Scene_Manager.h"
#include"Scene_Base.h"
#include"Key_Checker.h"

#include<memory>

//GPUを使用するためのコード
extern "C"
{
	__declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
	__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
}

// メイン
int WINAPI WinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int /*nCmdShow*/) {
	// 定数をまとめておくクラス
	Define_Value define_value;
	// ゲームの進行を管理するクラス
	std::unique_ptr<Scene_Manager>& scene_manager = Scene_Manager::Get_Instance();
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

	// カメラの座標を設定
	VECTOR camera_position;
	camera_position.x = define_value.CAMERA_POSITION_X;
	camera_position.y = define_value.CAMERA_POSITION_Y;
	camera_position.z = define_value.CAMERA_POSITION_Z;

	// 最初のシーンへ
	scene_manager->Change_Scene(scene_manager->scene_state);
	// ゲームループ
	while (ProcessMessage() != -1) {
		// 画面をクリア
		ClearDrawScreen();
		// 描画先を裏画面に
		SetDrawScreen(DX_SCREEN_BACK);
		// カメラの座標と注視点
		SetCameraPositionAndTarget_UpVecY(camera_position, VGet(0,0,0));

		key_Checker->Update_Key();
		scene_manager->Update();
		scene_manager->Render();

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