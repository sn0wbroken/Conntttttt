#include"Result_Game_Over.h"
#include"Scene_Manager.h"

// ���t���[������
void Result_Game_Over::Update() {
	std::unique_ptr<Scene_Manager> &game_manager = Scene_Manager::Get_Instance();

	// Enter�L�[�Ń��C���V�[����
	if (key_checker->key[KEY_INPUT_RETURN] == 1) {
		game_manager->Change_Scene(Scene_Manager::Title);
	}
}

// �w�i��`��
void Result_Game_Over::Render() {
	DrawExtendGraph(0, 0, define_value.WINDOW_X, define_value.WINDOW_Y, background_graph, TRUE);
}