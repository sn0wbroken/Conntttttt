#include"Player_Action.h"

// �R���X�g���N�^
Player_Action::Player_Action(std::shared_ptr<Player> set_player,
	std::shared_ptr<Player_Status> set_player_statsu) {
	player = set_player;
	player_status = set_player_statsu;

	player_move = std::make_shared<Player_Move>(player, player_status);
}

// �f�X�g���N�^
Player_Action::~Player_Action() {
}

// ���t���[���Ă΂��
void Player_Action::Update() {
	// �v���C���[�̑�����󂯕t���� ���t���[���Ăяo��
	Player_Controll();
}

// �v���C���[�̑�����󂯕t���� ���t���[���Ăяo��
void Player_Action::Player_Controll() {
	// �ړ�
	player_move->Rotation();
}

// ������
void Player_Action::Initialize() {

}
