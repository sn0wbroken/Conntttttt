#include "Player_Action.h"

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

// �v���C���[���ړ�������
void Player_Action::Move() {
	// ���������ł͓����Ȃ��悤��
	if (CheckHitKey(KEY_INPUT_RIGHT) && CheckHitKey(KEY_INPUT_LEFT)) {
		return;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		// ��ʒ[�ł�������ړ����Ȃ�
		if (Is_Over_Max_X()) {
			return;
		}

		int player_x = player->Get_X();
		player->Set_X(player_x += player_status->Get_Speed());
	}
	else if (CheckHitKey(KEY_INPUT_LEFT)) {
		// ��ʒ[�ł�������ړ����Ȃ�
		if (Is_Over_Min_X()) {
			return;
		}

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

// �U���̎�ނ�؂�ւ���B���t���[����t����
void Player_Action::Change_Fire_Type() {
	if (key_checker->key[KEY_INPUT_A] == 1) {
		shot_type = ePlayer_Shot_Type::Straight;

		// �����U���̂��̂�
		fire_type = [&]() {
			// �p���[�A�b�v��Ԃɉ����ċ���𕪂���
			if (player->Get_Power_Up()) {
				player->player_bullet.emplace_back(player->Get_Shoot_Point() - (player->Get_Width() / 2), player->Get_Y(), 0, -define_value.PLAYER_BULLET_SPEED);
				player->player_bullet.emplace_back(player->Get_Shoot_Point() + (player->Get_Width() / 2), player->Get_Y(), 0, -define_value.PLAYER_BULLET_SPEED);
			}
			else {
				player->player_bullet.emplace_back(player->Get_Shoot_Point(), player->Get_Y(), 0, -define_value.PLAYER_BULLET_SPEED);
			}
		};
	}

	// �ł��o��x���̈ʒu��ς���
	counter += 2;
	rad = static_cast<float>(counter * M_PI / 180.0f);
	position_x = std::sin(rad) * amplitude;
	if (key_checker->key[KEY_INPUT_S] == 1) {
		shot_type = ePlayer_Shot_Type::Wave;

		fire_type = [&]() {
			// �g��U���̂��̂�
			if (player->Get_Power_Up()) {
				player->player_bullet.emplace_back(player->Get_Shoot_Point(), player->Get_Y(), static_cast<int>(position_x), -define_value.PLAYER_BULLET_SPEED);
				player->player_bullet.emplace_back(player->Get_Shoot_Point(), player->Get_Y(), static_cast<int>(-position_x), -define_value.PLAYER_BULLET_SPEED);
			}
			else {
				player->player_bullet.emplace_back(player->Get_Shoot_Point(), player->Get_Y(), static_cast<int>(position_x), -define_value.PLAYER_BULLET_SPEED);
			}
		};
	}
}

// ��ʉE�[����o�悤�Ƃ��Ă��邩�ǂ����B�o�悤�Ƃ��Ă�����true
bool Player_Action::Is_Over_Max_X() {
	return player->Get_Right_Edge() >= define_value.MAX_SCREEN_X;
}

// ��ʍ��[����o�悤�Ƃ��Ă��邩�ǂ����B�o�悤�Ƃ��Ă�����true
bool Player_Action::Is_Over_Min_X() {
	return player->Get_Left_Edge() <= define_value.MIN_SCREEN_X;;
}
