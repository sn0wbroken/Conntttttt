#include"Player_Action.h"
#include"Player_Manager.h"

// �R���X�g���N�^
Player_Action::Player_Action() {
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
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	auto player_move = player_manager->player_move;
	
	// �ړ�
	player_move->Rotation();
}

// ������
void Player_Action::Initialize() {

}
