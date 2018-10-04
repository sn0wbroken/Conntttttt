#pragma once

#include"DxLib.h"
#include"Unique_Component.h"

// �V�[���̊��N���X
class Scene_Base {
public:
	// �R���X�g���N�^
	Scene_Base() {};

	// �f�X�g���N�^
	virtual ~Scene_Base() {};

	// ���t���[�����鏈��������
	virtual void Update() = 0;
	// �`����s��
	virtual void Render() = 0;

	// �w�i�̉摜���Z�b�g����
	virtual void Set_Background(char* path);

protected:
	// �w�i�̉摜�f�[�^
	int background_graph;
};
