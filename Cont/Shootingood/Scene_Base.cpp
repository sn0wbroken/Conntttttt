#include "Scene_Base.h"

// �w�i�̉摜��ݒ肷��
void Scene_Base::Set_Background(char* path) {
	background_graph = LoadGraph(path);
}