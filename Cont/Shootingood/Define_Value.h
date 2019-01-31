#pragma once

#include"DxLib.h"

// �萔���܂Ƃ߂�
class Define_Value {
public:
	// ��ʃT�C�Y ��
	static const int WINDOW_X = 800;
	// ��ʃT�C�Y ����
	static const int WINDOW_Y = 600;
	// UI�\���X�y�[�X
	static constexpr float UI_SPACE = 180.0f;

	// �Q�[����ʂ̍��[
	int MIN_SCREEN_X = 0;
	// �Q�[����ʂ̉E�[(WINDOW_X - UI_SPACE)
	static constexpr float MAX_SCREEN_X = 620.0f;
	// ��ʂ̏�[
	static const int MIN_WINDOW_Y = 0;
	// ��ʂ̉��[
	static const int MAX_WINDOW_Y = 600;

	// �J������X���W(�Œ�)
	static constexpr float CAMERA_POSITION_X = 0.0f;
	// �J������Y���W(�Œ�)
	static constexpr float CAMERA_POSITION_Y = 300.0f;
	// �J������Z���W(�Œ�)
	static constexpr float CAMERA_POSITION_Z = -400.0f;

	// UI��\������Ƃ���X���W
	static constexpr float UI_X = 640.0f;
	// UI��\������Ƃ���Y���W�̊�l
	static constexpr float UI_BASE_Y = 50.0f;
	// UI���m�̃X�y�[�X
	static constexpr float FELLOW_UI_SPACE = 40.0f;

	// �L�[�̐�
	static const int KEY_NUMEBR = 256;

	// �e�̔��a
	static constexpr float BULLET_RADIUS = 2.0f;

	// �ŏI�X�e�[�W enum�ɍ��킹��0����̃J�E���g
	static const int FINAL_STAGE = 2;

#pragma region �v���C���[

	// �v���C���[�̍ő�̗�
	static const int PLAYER_MAX_LIFE = 3;
	// �v���C���[�̑傫��(��)
	static constexpr float PLAYER_WIDTH = 48.0f;
	// �v���C���[�̑傫��(����)
	static constexpr float PLAYER_HEIGHT = 48.0f;
	// �v���C���[�̑傫��(���s)
	static constexpr float PLAYER_DEPTH = 48.0f;
	// �v���C���[�̍U����
	static const int PLAYER_ATTACK = 1;
	// �v���C���[�̌��e�̑��x
	static constexpr float PLAYER_BULLET_SPEED = 15.0f;
	// �v���C���[�̏����c�@
	static const int PLAYER_INITIALIZE_LIFE = 3;
	// �v���C���[�̉�]���x
	static constexpr float PLAYER_ROTATE_SPEED = 6.0f;
	// �v���C���[�̉�]�p�x(�����1�t���[����6�x��]����)
	static constexpr float ROTATION_VALUE = 3.0f;
	// �v���C���[����΂��e�̍ő�ێ���(�{���̎��Ɏg��) 
	//TODO:���삪�܂��B���ŃG���[�f���̂ő傫�߂�
	static const int MAX_BULLET = 500;

#pragma endregion

#pragma region �G�l�~�[

	// �G�l�~�[�̑傫��(��)
	static constexpr float ENEMY_WIDTH = 40.0f;
	// �G�l�~�[�̑傫��(����)
	static constexpr float ENEMY_HEIGHT = 50.0f;
	// �G�l�~�[�̑傫��(���s)
	static constexpr float ENEMY_DEPTH = 15.0f;
	// �G�l�~�[�̈ړ����x
	static constexpr float ENEMY_SPEED = 1.0f;


#pragma endregion

#pragma region �I���A�C�R�� (�^�C�g���ɂ���ǂ��I��ł��邩�̎O�p�`�̂���)

	// �I���A�C�R���̕�
	static const int DECIDE_ICON_WIDTH = 33;
	// �I���A�C�R���̍���
	static const int DECIDE_ICON_HEIGHT = 30;
	// �I���A�C�R���̏���x���W
	static const int INITIALIZE_POSITION_X = 550;
	// �I���A�C�R���̏���y���W
	static const int INITIALIZE_POSITION_Y = 317;
	// �I���A�C�R���̈ړ���
	static const int ICON_MOVE_VALUE = 70;

#pragma endregion

#pragma region �}�j���A��

	// �}�j���A���̍ő�y�[�W���B�z��̃T�C�Y�ɍ��킹�Ă���
	static const int MAX_PAGE_NUBER = 2;

#pragma endregion

};