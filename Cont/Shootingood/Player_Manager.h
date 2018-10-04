#pragma once

#include"Player.h"
#include"Player_Status.h"
#include"Player_Action.h"
#include"Unique_Component.h"

#include"Define_Value.h"

#include<memory>

// �v���C���[�̃}�l�[�W���[�N���X
class Player_Manager : public Unique_Component<Player_Manager> {
public:
	// ���t���[���Ă΂��
	void Update();

	// �v���C���[�{�̂̃N���X
	std::shared_ptr<Player> player = std::make_shared<Player>();
	// �v���C���[�̃X�e�[�^�X�֌W�������N���X
	std::shared_ptr<Player_Status> player_status = std::make_shared<Player_Status>();
	// �v���C���[�̍s�����Ǘ�����N���X
	std::shared_ptr<Player_Action> player_action = std::make_shared<Player_Action>(player, player_status);

	// �f�X�g���N�^
	~Player_Manager() {};

private:
	// �R���X�g���N�^
	Player_Manager() {};

	// �萔���܂Ƃ߂Ă����\����
	Define_Value define_value;

	// �����Ɏ��g���w�肵�����̂����ɐ�������邷
	friend class Unique_Component<Player_Manager>;
};
