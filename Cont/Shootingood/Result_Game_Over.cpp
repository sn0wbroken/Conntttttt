#include"Result_Game_Over.h"
#include"Game_Manager.h"

// ���t���[������
void Result_Game_Over::Update() {
	std::unique_ptr<Game_Manager> &game_manager = Game_Manager::Get_Instance();

	// Enter�L�[�Ń��C���V�[����
	if (key_checker->key[KEY_INPUT_RETURN] == 1) {
		game_manager->Change_Scene(Game_Manager::Title);
	}
}

// �w�i��`��
void Result_Game_Over::Render() {
	DrawExtendGraph(0, 0, define_value.WINDOW_X, define_value.WINDOW_Y, background_graph, TRUE);
}
