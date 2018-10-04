#pragma once

#include"Scene_Base.h"
#include"Key_Checker.h"

// ���U���g�V�[��
class Result_Game_Over : public Scene_Base {
public:
	// �R���X�g���N�^
	Result_Game_Over() {};
	// �f�X�g���N�^
	~Result_Game_Over() {};

	// ���t���[������
	void Update() override;
	// �`��
	void Render() override;

private:
	// �萔���܂Ƃ߂Ă����\����
	Define_Value define_value;

	// �L�[���͂��`�F�b�N����N���X
	std::unique_ptr<Key_Checker>& key_checker = Key_Checker::Get_Instance();
};
