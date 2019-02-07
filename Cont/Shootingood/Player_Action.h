#pragma once

#include"DxLib.h"
#include"Enum.h"
#include"Key_Checker.h"

#include<memory>
#include<functional>

// �v���C���[�̍s�����Ǘ�����N���X
class Player_Action {
public:
	// �R���X�g���N�^
	Player_Action();
	
	// �f�X�g���N�^
	~Player_Action();

	// �v���C���[�̑�����܂Ƃ߂� ���t���[���Ăяo��
	void Player_Controll();

	// ���t���[���Ă΂��
	void Update();

	// ������
	void Initialize();

private:
	// �萔���܂Ƃ߂Ă����N���X
	Define_Value define_value;

	// �L�[���͂��`�F�b�N����N���X
	std::unique_ptr<Key_Checker>& key_checker = Key_Checker::Get_Instance();
};
