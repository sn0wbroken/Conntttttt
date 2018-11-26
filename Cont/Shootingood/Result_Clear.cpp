#include "Result_Clear.h"

// ���t���[������
void Result_Clear::Update() {
	std::unique_ptr<Scene_Manager> &scene_manager = Scene_Manager::Get_Instance();

	// Enter�L�[�Ń��C���V�[����
	if (key_checker->key[KEY_INPUT_RETURN] == 1) {
		scene_manager->Change_Scene(Scene_Manager::Title);
	}
}

// �w�i��`��
void Result_Clear::Render() {
	DrawExtendGraph(0, 0, define_value.WINDOW_X, define_value.WINDOW_Y, background_graph, TRUE);
}