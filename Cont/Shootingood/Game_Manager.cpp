#include "Game_Manager.h"

// コンストラクタ
Game_Manager::Game_Manager() {
	// 最初はタイトルから
	scene_state = eScene_State::Title;
}

// stageを返す
eStage Game_Manager::Get_Stage() {
	return stage;
}

// 全体のループ
void Game_Manager::Update() {
	scene_base->Update();
}

// 描画
void Game_Manager::Render() {
	scene_base->Render();
}

// シーンを切り替える
void Game_Manager::Change_Scene(eScene_State check_scene_state) {
	// 古いものは破棄する
	if (scene_base != NULL) {
		delete scene_base;
	}

	// 切り替えと同時に背景の画像を変える
	switch (check_scene_state) {
	case eScene_State::Title:
		scene_base = new Title_Scene();
		scene_base->Set_Background("Picture/Background/Title.png");
		break;
	case eScene_State::Main:
		scene_base = new Main_Scene();
		scene_base->Set_Background("Picture/Background/Main.png");
		break;
	case eScene_State::Game_Over:
		scene_base = new Result_Game_Over();
		scene_base->Set_Background("Picture/Background/Game_Over.png");
		break;
	case eScene_State::Clear:
		scene_base = new Result_Clear();
		scene_base->Set_Background("Picture/Background/Game_Clear.png");
		break;
	}
}
// クリア、ゲームオーバー時に呼ばれる。プレイステージを1に戻す
void Game_Manager::Reset_Stage() {
	stage = eStage::stage1;
}

// ステージを進める ステージクリア時に呼ばれる
void Game_Manager::Next_Stage() {
	switch (stage) {
		case eStage::stage1:
			stage = eStage::stage2;
			break;
		case eStage::stage2:
			stage = eStage::stage3;
			break;
	}
}
