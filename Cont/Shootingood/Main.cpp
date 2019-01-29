#include"DxLib.h"
#include"Scene_Manager.h"
#include"Scene_Base.h"
#include"Key_Checker.h"

#include<memory>

//GPU���g�p���邽�߂̃R�[�h
extern "C"
{
	__declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
	__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
}

// ���C��
int WINAPI WinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int /*nCmdShow*/) {
	// �萔���܂Ƃ߂Ă����N���X
	Define_Value define_value;
	// �Q�[���̐i�s���Ǘ�����N���X
	std::unique_ptr<Scene_Manager>& scene_manager = Scene_Manager::Get_Instance();
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

	// �J�����̍��W��ݒ�
	VECTOR camera_position;
	camera_position.x = define_value.CAMERA_POSITION_X;
	camera_position.y = define_value.CAMERA_POSITION_Y;
	camera_position.z = define_value.CAMERA_POSITION_Z;

	// �ŏ��̃V�[����
	scene_manager->Change_Scene(scene_manager->scene_state);
	// �Q�[�����[�v
	while (ProcessMessage() != -1) {
		// ��ʂ��N���A
		ClearDrawScreen();
		// �`���𗠉�ʂ�
		SetDrawScreen(DX_SCREEN_BACK);
		// �J�����̍��W�ƒ����_
		SetCameraPositionAndTarget_UpVecY(camera_position, VGet(0,0,0));

		key_Checker->Update_Key();
		scene_manager->Update();
		scene_manager->Render();

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