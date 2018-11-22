#include"Player_Weapon.h"
#include"Player_Manager.h"

// �R���X�g���N�^
Player_Weapon::Player_Weapon() {}

// �R�s�[�R���X�g���N�^
Player_Weapon::Player_Weapon(std::shared_ptr<Player> set_player) {
	player = set_player;

	// �������֐����Ăяo��
	Initialize();
}

// �f�X�g���N�^
Player_Weapon::~Player_Weapon() {}

// �X�V����
void Player_Weapon::Update() {
	// �U��
	Fire();
	// �V���b�g�^�C�v�̐؂�ւ�
	Change_Fire_Type();
	// �ł��o�����e�ۂ���ʊO�ɏo�Ă��������
	Bullet_Off_Screen_Erase();

	Actor::Update();
}

// �������֐�
void Player_Weapon::Initialize() {
	// ���W��ݒ�
	vector3.Arrange(player->Get_X(), player->Get_Y() + player->Get_Height() / 2, player->Get_Z());

	// �V���b�g�p�^�[����ݒ肷��
	fire_type = [&]() {
		//player->player_bullet.emplace_back(player->Get_Shoot_Point(), player->Get_Y(), 0, -define_value.PLAYER_BULLET_SPEED);

		std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(300.0f, 300.0f, 0.0f, 0.0f, 15.0f, 0.0f);
		Actor::Add_Child(bullet);
	};

	// �p�^�[���ɏ�Ԃ����킹��
	shot_type = ePlayer_Shot_Type::Straight;
}

// �e�𔭎�
void Player_Weapon::Fire() {
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		fire_type();
	}
}

// ��Ԃɉ������V���b�g��ݒ肷��
void Player_Weapon::Set_Shot_Pattern() {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	player = player_manager->player;

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
				
				std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(300.0f,300.0f,15.0f);
				Actor::Add_Child(bullet);
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
void Player_Weapon::Change_Fire_Type() {
	if (key_checker->key[KEY_INPUT_A] == 1) {
		shot_type = ePlayer_Shot_Type::Straight;
		// �����U���̂��̂�
		Set_Shot_Pattern();
	}

	// �ł��o��x���̈ʒu��ς���
	counter += 2;
	radian = static_cast<float>(counter * DX_PI_F / 180.0f);
	position_x = std::sin(radian) * amplitude;
	if (key_checker->key[KEY_INPUT_S] == 1) {
		shot_type = ePlayer_Shot_Type::Wave;
		fire_type = [&]() {
			// �g��U���̂��̂�
			Set_Shot_Pattern();
		};
	}
}

// �ł��o�����e�ۂ���ʊO�ɏo�Ă��邩���f����
bool Player_Weapon::Check_Off_Screen(Bullet& player_bullet) {
	return player_bullet.Is_Over_Max_X() || player_bullet.Is_Over_Min_X() ||
		player_bullet.Is_Over_Max_Y() || player_bullet.Is_Over_Min_Y();
}

// �ł��o�����e�ۂ��͈͊O�ɏo�Ă��������
void Player_Weapon::Bullet_Off_Screen_Erase() {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	for (auto& player_bullet : player_manager->player->player_bullet) {
		if (Check_Off_Screen(player_bullet)) {
			player_manager->player->player_bullet.erase(player_manager->player->player_bullet.begin());
		}
	}
}
