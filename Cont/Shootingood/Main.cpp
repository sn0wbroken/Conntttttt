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


		// �W�����C�g���|�C���g���C�g�ɂ���
		ChangeLightTypePoint(VGet(define_value.WINDOW_X / 2, define_value.WINDOW_Y / 2, -100.0f), 2000.0f, 0.0f, 0.002f, 0.0f);
		SetLightPosition(VGet(400.0f, -30.0f, -100.0f));
		DrawSphere3D(VGet(320.0f, 200.0f, 0.0f), 80.0f, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);


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