#include "Scene_Base.h"

// ”wŒi‚Ì‰æ‘œ‚ğİ’è‚·‚é
void Scene_Base::Set_Background(char* path) {
	background_graph = LoadGraph(path);
}