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
	Left
};

// TODO:�{���̎����ɍ��킹��
// �v���C���[�̃{���̃^�C�v
enum class eBom_Type {
	None, // �{�����������
	Fullrange, // �S���ʂɒe���΂�
	Fuga
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
