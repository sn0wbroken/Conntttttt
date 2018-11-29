#include"Player_Weapon.h"
#include"Player_Manager.h"

// �R���X�g���N�^
Player_Weapon::Player_Weapon() {

}

// �f�X�g���N�^
Player_Weapon::~Player_Weapon() {}

// �X�V����
void Player_Weapon::Update() {
	// �U��
	Fire();

	// �q�ɂ���
	Actor::Update();
}

// �������֐�
void Player_Weapon::Initialize() {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	player = player_manager->player;
	// ���W��ݒ�
	vector3.Arrange(player->Get_X(), player->Get_Y() + player->Get_Height() / 2, player->Get_Z());
}

// �e�𔭎�
void Player_Weapon::Fire() {
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(300.0f, 300.0f, 0.0f, 0.0f, 15.0f, 0.0f);
		Actor::Add_Child(bullet);
	}
}

// ��Ԃɉ������V���b�g��ݒ肷��
void Player_Weapon::Set_Shot_Pattern() {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	player = player_manager->player;

	bom_type = [&]() {
		switch (ebom_type) {
		default: break;
		}
	};
}

// �U���̎�ނ�؂�ւ���B���t���[����t����
void Player_Weapon::Change_Fire_Type() {
	if (key_checker->key[KEY_INPUT_A] == 1) {
		ebom_type = eBom_Type::Hoge;
		// �����U���̂��̂�
		Set_Shot_Pattern();
	}

	// �ł��o��x���̈ʒu��ς���
	counter += 2;
	radian = static_cast<float>(counter * DX_PI_F / 180.0f);
	position_x = std::sin(radian) * amplitude;
	if (key_checker->key[KEY_INPUT_S] == 1) {
		ebom_type = eBom_Type::Fuga;
		bom_type = [&]() {
			// �g��U���̂��̂�
			Set_Shot_Pattern();
		};
	}
}
