#include "Result_Clear.h"

// ���t���[������
void Result_Clear::Update() {
	std::unique_ptr<Game_Manager> &game_manager = Game_Manager::Get_Instance();

	// Enter�L�[�Ń��C���V�[����
	if (key_checker->key[KEY_INPUT_RETURN] == 1) {
		game_manager->Change_Scene(Game_Manager::Title);
	}
}

// �w�i��`��
void Result_Clear::Render() {
	DrawExtendGraph(0, 0, define_value.WINDOW_X, define_value.WINDOW_Y, background_graph, TRUE);
}