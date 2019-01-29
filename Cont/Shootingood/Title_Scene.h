#pragma once

#include"Enum.h"
#include"Scene_Base.h"
#include"Key_Checker.h"
#include"Manual.h"
#include"CSVData.h"

#include<memory>

// �^�C�g���V�[��
class Title_Scene : public Scene_Base {
public:
	// �R���X�g���N�^
	Title_Scene();
	// �f�X�g���N�^
	~Title_Scene() {};

	// ���t���[���Ă΂�鏈��
	void Update() override;
	// �`��
	void Render() override;

private:
	// �}�j���A�����Ǘ�����N���X
	std::shared_ptr<Manual> manual;

	// �I���A�C�R���𓮂���
	void Icon_Move();

	// ����ɉ����đI�����Ă�����̂�ς���
	void Change_Decide(eSelect_Command now_decide, int which_key);

	// �萔���܂Ƃ߂Ă����N���X
	Define_Value define_value;

	// ����I�����Ă��邩
	eSelect_Command select_command;

	// �L�[���͂��`�F�b�N����N���X
	std::unique_ptr<Key_Checker>& key_checker = Key_Checker::Get_Instance();

	// �I���A�C�R����x���W
	int icon_position_x;
	// �I���A�C�R����y���W
	int icon_position_y;
	// �I���A�C�R���̕�
	int icon_width;
	// �I���A�C�R���̍���
	int icon_height;

	// �}�j���A�������Ă��邩�B�I�����ꂽ��true��
	bool is_watch_manual;
};
