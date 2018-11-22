#include"Result_Game_Over.h"
#include"Scene_Manager.h"

// 毎フレーム入る
void Result_Game_Over::Update() {
	std::unique_ptr<Scene_Manager> &game_manager = Scene_Manager::Get_Instance();

	// Enterキーでメインシーンへ
	if (key_checker->key[KEY_INPUT_RETURN] == 1) {
		game_manager->Change_Scene(Scene_Manager::Title);
	}
}

// 背景を描画
void Result_Game_Over::Render() {
	DrawExtendGraph(0, 0, define_value.WINDOW_X, define_value.WINDOW_Y, background_graph, TRUE);
}