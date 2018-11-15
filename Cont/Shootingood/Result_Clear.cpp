#include "Result_Clear.h"

// 毎フレーム入る
void Result_Clear::Update() {
	std::unique_ptr<Game_Manager> &game_manager = Game_Manager::Get_Instance();

	// Enterキーでメインシーンへ
	if (key_checker->key[KEY_INPUT_RETURN] == 1) {
		game_manager->Change_Scene(Game_Manager::Title);
	}
}

// 背景を描画
void Result_Clear::Render() {
	DrawExtendGraph(0, 0, define_value.WINDOW_X, define_value.WINDOW_Y, background_graph, TRUE);
}