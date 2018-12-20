#include"DxLib.h"
#include"Scene_Manager.h"
#include"Scene_Base.h"
#include"Key_Checker.h"

#include<memory>

#include"TEST_GOD.h"

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
	VECTOR camera_position ;
	camera_position.x = 0.0f;
	camera_position.y = 300.0f;
	camera_position.z = -400.0f;

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
		
		//TODO:背景が邪魔で消したら見にくかったので置いた。
		DrawTriangle3D(
			VGet(1000.0f, 1000.0f,  -10.0f),
			VGet(-1000.0f, 1000.0f, -10.0f),
			VGet(500.0f, -3000.0f,  -10.0f), GetColor(255, 255, 255), TRUE);

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