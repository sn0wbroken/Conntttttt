#pragma once

#include"Object_Creater.h"

#include"UI.h"
#include"Actor.h"
#include"Collision.h"
#include"Scene_Base.h"
#include"Key_Checker.h"
#include"Enemy_Manager.h"

// ���C���V�[�� 
class Main_Scene : public Scene_Base {
public:
	// �R���X�g���N�^
	Main_Scene();

	// ���t���[������
	void Update() override;
	// �`��
	void Render() override;

	// ������
	void Initialize();

private:
	// �v���C���[�����S�����Ƃ��̏���
	void Player_Dead();
	
	// �萔���܂Ƃ߂Ă����N���X
	Define_Value define_value;

	// UI�\���N���X
	std::shared_ptr<UI> UI_class;

	// �v���C���[�{�̂̃N���X
	std::shared_ptr<Player> player;
	// �v���C���[�̍s�����Ǘ�����N���X
	std::shared_ptr<Player_Action> player_action;
	// �v���C���[�̃X�e�[�^�X�֌W�̃N���X
	std::shared_ptr<Player_Status> player_status;

	// �����蔻����s���N���X
	std::shared_ptr<Collision> collision;

	// �G�l�~�[�̃}�l�[�W���N���X
	std::unique_ptr<Enemy_Manager>& enemy_manager = Enemy_Manager::Get_Instance();

	// �w�i1��x���W
	int x1;
	// �w�i2��x���W
	int x2;

	// �Q�[���J�n�܂ł̃C���^�[�o���B����s�\�B�G���^�[�L�[�̉����ŉ���(�Q�[���X�^�[�g)
	bool is_interval;

	//�n�ʃf�[�^
	int ground_handle;

	// �w�i���f���̃f�[�^
	int background_model;

	// �w�i���f���̍��W��ݒ�
	void Set_BackGround_Position();
};