#pragma once

#include"UI.h"
#include"Collision.h"
#include"Scene_Base.h"
#include"Key_Checker.h"
#include"Enemy_Manager.h"
#include"Player_Manager.h"

#include<memory>

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

	// �v���C���[�ƃG�l�~�[���Փ˂������ǂ���
	bool Is_Hit_Actor_Fellow();
	// �v���C���[���G�l�~�[�̍U�����󂯂����ǂ���
	bool Is_Enemy_Attack_Hit();
	// �G�l�~�[���S�ł������ǂ���
	bool Is_Enemy_All_Ded();

	// �v���C���[�̍U�����G�ɖ���������
	void Is_Player_Attack_Hit();

private:
	// �v���C���[�����S�����Ƃ��̏���
	void Player_Dead();

	// �萔���܂Ƃ߂Ă����\����
	Define_Value define_value;

	// �L�[���͂��`�F�b�N����N���X
	std::unique_ptr<Key_Checker>& key_checker = Key_Checker::Get_Instance();

	// UI�\���N���X
	std::shared_ptr<UI> UI_class;

	// �v���C���[�̃}�l�[�W���N���X
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	// �v���C���[�{�̂̃N���X
	std::shared_ptr<Player> player;
	// �v���C���[�̍s�����Ǘ�����N���X
	std::shared_ptr<Player_Action> player_action;

	// �����蔻����s���N���X
	std::shared_ptr<Collision> collision;

	// �G�l�~�[�̃}�l�[�W���N���X
	std::unique_ptr<Enemy_Manager>& enemy_manager = Enemy_Manager::Get_Instance();

	// �w�i�̍��W�𓮂���
	void Scroll();

	// �w�i1��y���W
	int y1;
	// �w�i2��y���W
	int y2;

	// �Q�[���J�n�܂ł̃C���^�[�o���B����s�\�B�G���^�[�L�[�̉����ŉ���(�Q�[���X�^�[�g)
	bool is_interval;
};