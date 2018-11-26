#pragma once

#include"DxLib.h"
#include"Define_Value.h"
#include"Unique_Component.h"

// �S�ẴL�[�̓��͏�Ԃ��`�F�b�N����
class Key_Checker : public Unique_Component<Key_Checker> {
public:
	// �R���X�g���N�^
	Key_Checker() {}
	// �f�X�g���N�^
	~Key_Checker() {}

	// �萔���܂Ƃ߂Ă����N���X
	Define_Value define_value;

	// �����Ɏ��g���w�肵�����̂����ɐ�������邷
	friend class Unique_Component<Key_Checker>;

	// �S�ẴL�[
	int key[256];

	int Update_Key() {
		// ���݂̃L�[�̓��͏�Ԃ��i�[����
		char tmpKey[256];
		// �S�ẴL�[�̓��͏�Ԃ𓾂�
		GetHitKeyStateAll(tmpKey);

		// �S�ẴL�[�̓��͏�Ԃ�
		for (int i = 0; i < define_value.KEY_NUMEBR; i++) {
			// ������Ă�����1��Ԃ�
			if (tmpKey[i] != 0) {
				++key[i];
			}
			else {
				key[i] = 0;
			}
		}
		return 0;
	}
};
