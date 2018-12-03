#include"Player_Weapon.h"
#include"Player_Manager.h"
#include"Bullet.h"

// �R���X�g���N�^
Player_Weapon::Player_Weapon() {

}

// �f�X�g���N�^
Player_Weapon::~Player_Weapon() {	}

// �������֐�
void Player_Weapon::Initialize() {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	player = player_manager->player;
	// ���W��ݒ�
	vector3.Arrange(player->Get_X() - 1, player->Get_Y() + player->Get_Height() / 2, player->Get_Z());

	//TEST
	for (int i = 0; i < define_value.MAX_BULLET; ++i) {
		Bullet* bullet = new Bullet();
		bullet->actor_state = eActor_State::Break;
		player->magazine.push_back(bullet);
	}
}

// �X�V����
void Player_Weapon::Update() {
	// �U��
	Fire();
	// �L�[���͂ŏe������]������
	Rotation();

	// �q�ɂ���
	Actor::Update();
}

// �`��
void Player_Weapon::Render() {
	for (auto bullet : player->magazine) {
		bullet->Render();
	}
}

// �e�𐶐�(����)
void Player_Weapon::Fire() {
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		for (auto bullet : player->magazine) {
			bullet->actor_state = eActor_State::Action;
			bullet->vector3d.x += vector3.x;
			bullet->vector3d.y += vector3.y;
			bullet->speed = 15;

		}
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

// �e���̈ʒu��ς���(��])
void Player_Weapon::Rotation() {
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		degree += define_value.ROTATION_VALUE;
		radian = degree * DX_PI_F / 180;
		
		//vector3.x += cos(radian) * 15;
		//vector3.y += sin(radian) * 15;

		//MATRIX matrix;
		//matrix = MGetRotZ(DX_PI_F / 64.0f);
		//vector3 = VTransform(vector3.GetVECTOR(), matrix);
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT)) {
		degree += define_value.ROTATION_VALUE;
		radian = degree * DX_PI_F / 180;

		//vector3.x = cos(radian) * 15;
		//vector3.y = sin(radian) * 15;

		//MATRIX matrix;
		//matrix = MGetRotZ(-DX_PI_F / 64.0f);
		//vector3 = VTransform(vector3.GetVECTOR(), matrix);
	}
}

