#include<memory>

#include"DxLib.h"
#include"Game_Manager.h"
#include"Scene_Base.h"
#include"Key_Checker.h"

// ���C��
int WINAPI WinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int /*nCmdShow*/) {
	// �萔���܂Ƃ߂Ă����\����
	Define_Value define_value;
	// �Q�[���̐i�s���Ǘ�����N���X
	std::unique_ptr<Game_Manager>& game_manager = Game_Manager::Get_Instance();
	// �L�[���͂��`�F�b�N����N���X
	std::unique_ptr<Key_Checker>& key_Checker = Key_Checker::Get_Instance();

	// �펞�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);
	// �E�B���h�E�̃T�C�Y�����߂�
	SetGraphMode(define_value.WINDOW_X, define_value.WINDOW_Y, 0);

	// ����������
	if (DxLib_Init() == -1) {
		// �G���[���N������I��
		return -1;
	}

	// �ŏ��̃V�[����
	game_manager->Change_Scene(game_manager->scene_state);

	// �Q�[�����[�v
	while (ProcessMessage() != -1) {
		// ����ʏ���
		ClearDrawScreen();
		// �`���𗠉�ʂ�
		SetDrawScreen(DX_SCREEN_BACK);

		key_Checker->Update_Key();
		game_manager->Update();
		game_manager->Render();

		// FPS��60�ŌŒ�
		int startTime = GetNowCount();
		int endTime = GetNowCount();
		WaitTimer(1000 / 60 - (endTime - startTime));

		// ����ʂ�\��ʂɃR�s�[
		ScreenFlip();
	}

	// �I������
	DxLib_End();

	return 0;
}