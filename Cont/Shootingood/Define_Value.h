#pragma once

// �萔���܂Ƃ߂�
class Define_Value {
public:
	// ��ʃT�C�Y ��
	static const int WINDOW_X = 800;
	// ��ʃT�C�Y ����
	static const int WINDOW_Y = 600;
	// UI�\���X�y�[�X
	static const int UI_SPACE = 180;

	// �Q�[����ʂ̍��[
	static const int MIN_SCREEN_X = 0;
	// �Q�[����ʂ̉E�[(WINDOW_X - UI_SPACE)
	static const int MAX_SCREEN_X = 620;
	// ��ʂ̏�[
	static const int MIN_WINDOW_Y = 0;
	// ��ʂ̉��[
	static const int MAX_WINDOW_Y = 600;

	// UI��\������Ƃ���X���W
	static const int UI_X = 640;
	// UI��\������Ƃ���Y���W�̊�l 
	static const int UI_BASE_Y = 50;
	// UI���m�̃X�y�[�X
	static const int FELLOW_UI_SPACE = 40;

	// �L�[�̐�
	static const int KEY_NUMEBR = 256;

	// �e�̔��a
	static const int BULLET_RADIUS = 2;

	// �ŏI�X�e�[�W enum�ɍ��킹��0����̃J�E���g
	static const int FINAL_STAGE = 2;

	// �����p�ϐ� UI�̕\���ʒu�Ɏg�p
	static const int  ADJUSTMENT_VALUE = 1;

#pragma region �v���C���[

	// �v���C���[�̍ő�̗�
	static const int PLAYER_MAX_LIFE = 3;
	// �v���C���[�̑傫��(��)
	static const int PLAYER_WIDTH  = 48;
	// �v���C���[�̑傫��(����)
	static const int PLAYER_HEIGHT = 48;
	// �v���C���[�̈ړ����x
	static const int PLAYER_SPEED = 6;
	// �v���C���[�̍U����
	static const int PLAYER_ATTACK = 1;
	// �v���C���[�̌��e�̑��x
	static const int PLAYER_BULLET_SPEED = 15;
	// �v���C���[�̏����c�@
	static const int PLAYER_INITIALIZE_LIFE = 3;

#pragma endregion

#pragma region �G�l�~�[

	// �G�̗̑͂̍ő�l
	static const int ENEMY_MAX_HP = 30;
	// �G�l�~�[�̑傫��(��)
	static const int ENEMY_WIDTH = 54;
	// �G�l�~�[�̑傫��(����)
	static const int ENEMY_HEIGHT = 36;
	// �o������G�l�~�[�̐�
	static const int ENEMY_NUMBER = 5;

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
