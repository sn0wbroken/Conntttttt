#include "Player_Action.h"
#include"Player_Manager.h"

// �R���X�g���N�^
Player_Action::Player_Action(std::shared_ptr<Player> set_player,
							 std::shared_ptr<Player_Status> set_player_statsu) {
	player = set_player;
	player_status = set_player_statsu;

	counter = 0;
	amplitude = 15;

	// �ŏ��͒����̂���
	shot_type = ePlayer_Shot_Type::Straight;
}

// �f�X�g���N�^
Player_Action::~Player_Action() {
}

// ���t���[���Ă΂��
void Player_Action::Update() {
	// �v���C���[�̑�����󂯕t���� ���t���[���Ăяo��
	Player_Controll();
	// �ł��o�����e�ۂ���ʊO�ɏo�Ă��������
	Bullet_Off_Screen_Erase();
}

// �v���C���[�̑�����󂯕t���� ���t���[���Ăяo��
void Player_Action::Player_Controll() {
	// �ړ�
	Move();
	// �U��
	Fire();
	// �V���b�g�^�C�v�̐؂�ւ�
	Change_Fire_Type();
}

// ������
void Player_Action::Initialize() {
	// ������Ԃ͒����ɔ�΂�����
	Set_Shot_Pattern();
}

// �v���C���[���ړ�������
void Player_Action::Move() {
	// ���������ł͓����Ȃ��悤��
	if (CheckHitKey(KEY_INPUT_RIGHT) && CheckHitKey(KEY_INPUT_LEFT)) {
		return;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		int player_x = player->Get_X();
		player->Set_X(player_x += player_status->Get_Speed());
	}
	else if (CheckHitKey(KEY_INPUT_LEFT)) {
		int player_x = player->Get_X();
		player->Set_X(player_x -= player_status->Get_Speed());
	}
}

// �e�𔭎�
void Player_Action::Fire() {
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		fire_type();
	}
}

// ��Ԃɉ������V���b�g��ݒ肷��
void Player_Action::Set_Shot_Pattern() {
	fire_type = [&]() {
		switch (shot_type) {
		case ePlayer_Shot_Type::Straight:
			// �p���[�A�b�v��Ԃɉ����ċ���𕪂���
			if (player->Get_Power_Up()) {
				player->player_bullet.emplace_back(player->Get_Shoot_Point() - (player->Get_Width() / 2), player->Get_Y(), 0, -define_value.PLAYER_BULLET_SPEED);
				player->player_bullet.emplace_back(player->Get_Shoot_Point() + (player->Get_Width() / 2), player->Get_Y(), 0, -define_value.PLAYER_BULLET_SPEED);
			}
			else {
				player->player_bullet.emplace_back(player->Get_Shoot_Point(), player->Get_Y(), 0, -define_value.PLAYER_BULLET_SPEED);
			}
			break;
		case ePlayer_Shot_Type::Wave:
			// �g��U���̂��̂�
			if (player->Get_Power_Up()) {
				player->player_bullet.emplace_back(player->Get_Shoot_Point(), player->Get_Y(), static_cast<int>(position_x), -define_value.PLAYER_BULLET_SPEED);
				player->player_bullet.emplace_back(player->Get_Shoot_Point(), player->Get_Y(), static_cast<int>(-position_x), -define_value.PLAYER_BULLET_SPEED);
			}
			else {
				player->player_bullet.emplace_back(player->Get_Shoot_Point(), player->Get_Y(), static_cast<int>(position_x), -define_value.PLAYER_BULLET_SPEED);
			}
		}
	};
}

// �U���̎�ނ�؂�ւ���B���t���[����t����
void Player_Action::Change_Fire_Type() {
	if (key_checker->key[KEY_INPUT_A] == 1) {
		shot_type = ePlayer_Shot_Type::Straight;
		// �����U���̂��̂�
		Set_Shot_Pattern();
	}

	// �ł��o��x���̈ʒu��ς���
	counter += 2;
	rad = static_cast<float>(counter * M_PI / 180.0f);
	position_x = std::sin(rad) * amplitude;
	if (key_checker->key[KEY_INPUT_S] == 1) {
		shot_type = ePlayer_Shot_Type::Wave;
		fire_type = [&]() {
			// �g��U���̂��̂�
			Set_Shot_Pattern();
		};
	}
}

// �ł��o�����e�ۂ���ʊO�ɏo�Ă��邩���f����
bool Player_Action::Check_Off_Screen(Bullet& player_bullet) {
	return player_bullet.Is_Over_Max_X() || player_bullet.Is_Over_Min_X() ||
		   player_bullet.Is_Over_Max_Y() || player_bullet.Is_Over_Min_Y();
}

// �ł��o�����e�ۂ��͈͊O�ɏo�Ă��������
void Player_Action::Bullet_Off_Screen_Erase() {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	for (auto& player_bullet : player_manager->player->player_bullet) {
		if (Check_Off_Screen(player_bullet)) {
			player_manager->player->player_bullet.erase(player_manager->player->player_bullet.begin());
		}
	}
}
