#include "Game_Manager.h"

// �R���X�g���N�^
Game_Manager::Game_Manager() {
	// �ŏ��̓^�C�g������
	scene_state = eScene_State::Title;
}

// stage��Ԃ�
eStage Game_Manager::Get_Stage() {
	return stage;
}

// �S�̂̃��[�v
void Game_Manager::Update() {
	scene_base->Update();
}

// �`��
void Game_Manager::Render() {
	scene_base->Render();
}

// �V�[����؂�ւ���
void Game_Manager::Change_Scene(eScene_State check_scene_state) {
	// �Â����͔̂j������
	if (scene_base != NULL) {
		delete scene_base;
	}

	// �؂�ւ��Ɠ����ɔw�i�̉摜��ς���
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
// �N���A�A�Q�[���I�[�o�[���ɌĂ΂��B�v���C�X�e�[�W��1�ɖ߂�
void Game_Manager::Reset_Stage() {
	stage = eStage::stage1;
}

// �X�e�[�W��i�߂� �X�e�[�W�N���A���ɌĂ΂��
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
