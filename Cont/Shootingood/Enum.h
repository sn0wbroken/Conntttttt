#pragma once

// �ǂ̃R�}���h��I��ł��邩(�^�C�g����ʂŎg�p)
enum class eSelect_Command {
	Start,
	Manual,
	Exit
};

// �ړ��������(�G�l�~�[��AI�Ɏg�p)
enum class eMove_Direction {
	Right,
	Left,
	Up,
	Down
};

// TODO:�{���̎����ɍ��킹��
// �v���C���[�̃{���̃^�C�v
enum class eBomb_Type {
	None, // �{�����������
	Fullrange, // �S���ʂɒe���΂�
	Rain // �U�����~�炷
};

// �v���C����X�e�[�W
enum class eStage {
	stage1,
	stage2,
	stage3
};

// �A�N�^�[�̏�ԁB��������ĕ`��Ȃǂ̍X�V�������s��
enum class eActor_State {
	Action,
	Break
};

// ���݌����Ă���{���̃^�C�v
enum class eEnable_Bomb_Type {
	None, // �{���U�����s���Ă��Ȃ�
	Fullrange, // �S���ʂɒe���΂��{��
	Rain // �e���~�炷�{��
};