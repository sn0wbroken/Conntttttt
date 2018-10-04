#pragma once

#include"DxLib.h"
#include"Define_Value.h"
#include"Key_Checker.h"

// ����UI���Ǘ�����N���X
class Manual {
public:
	// �R���X�g���N�^
	Manual();
	// �f�X�g���N�^
	~Manual();

	// ���t���[���Ă΂��
	void Update();
	// �`��
	void Render();

	// �}�j���A��������Ƃ��Ƀy�[�W���ŏ��ɖ߂�
	void Set_Initialize_Page_Number(int intialize_page);

private:
	// �萔���܂Ƃ߂Ă����N���X
	Define_Value define_value;

	// �L�[���͂��`�F�b�N����N���X
	std::unique_ptr<Key_Checker>& key_checker = Key_Checker::Get_Instance();

	// �L�[���͂Ńy�[�W���������
	void Page_Ejection();

	//TODO:�}�W�b�N�i���o�[
	// �}�j���A��UI���i�[����
	int manual_graph[3];
	
	// ���݉{�����̃y�[�W�̔ԍ�
	int now_page_number;
};

