#pragma once

#include"Scene_Base.h"
#include"Main_Scene.h"
#include"Title_Scene.h"
#include"Result_Clear.h"
#include"Result_Game_Over.h"
#include"Unique_Component.h"

// �Q�[���S�̂̐i�s���Ǘ�����
class Scene_Manager : public Unique_Component<Scene_Manager> {
public:
	// �ǂ̃V�[����(�Q�[���̏��)
	enum eScene_State {
		Title,
		Main,
		Game_Over,
		Clear
	};

	// �����Ɏ��g���w�肵�����̂����ɐ�������邷
	friend class Unique_Component<Scene_Manager>;

	// ���݂̏��
	eScene_State scene_state;
	// stage��Ԃ�
	eStage Get_Stage();

	// �S�̂̃��[�v
	void Update();
	// �`��
	void Render();

	// �V�[����؂�ւ���
	void Change_Scene(eScene_State scene_state);
	// �N���A�A�Q�[���I�[�o�[���ɌĂ΂��B�v���C�X�e�[�W��1�ɖ߂�
	void Reset_Stage();
	// �X�e�[�W��i�߂� �X�e�[�W�N���A���ɌĂ΂��
	void Next_Stage();

	// �f�X�g���N�^
	~Scene_Manager() {};

private:
	// �R���X�g���N�^
	Scene_Manager();

	// �v���C����X�e�[�W
	eStage stage;

	// �V�[���̊��N���X
	Scene_Base* scene_base;
};