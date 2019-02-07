#pragma once

#include"Scene_Base.h"
#include"Scene_Manager.h"

class Result_Clear : public Scene_Base {
public:
	// �R���X�g���N�^
	Result_Clear() {};
	// �f�X�g���N�^
	~Result_Clear() {};

	// ���t���[������
	void Update() override;
	// �`��
	void Render() override;

private:
	// �萔���܂Ƃ߂Ă����N���X
	Define_Value define_value;

	// �L�[���͂��`�F�b�N����N���X
	std::unique_ptr<Key_Checker>& key_checker = Key_Checker::Get_Instance();
};
