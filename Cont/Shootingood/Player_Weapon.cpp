#include"Player_Weapon.h"
#include"Player_Manager.h"
#include"Bullet.h"

// �R���X�g���N�^
Player_Weapon::Player_Weapon() : degree(90) {

}

// �f�X�g���N�^
Player_Weapon::~Player_Weapon() {	}

// �������֐�
void Player_Weapon::Initialize() {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	player = player_manager->player;

	// ���a��ݒ�
	radius = player->Get_Height() / 2 + 18;
	// ���S���W���擾
	center_position = player->vector3d;
	// �e���̍��W��ݒ�
	vector3d.Arrange(center_position.x, center_position.y + radius, center_position.z);

	// �e�ۂ��v�[�����O
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

	for (auto bullet : player->magazine) {
		bullet->Update();
	}

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
		ebom_type = eBom_Type::Fullrange;
		Set_Shot_Pattern();
		bom_type();
	}
}

// ��Ԃɉ������V���b�g��ݒ肷��
void Player_Weapon::Set_Shot_Pattern() {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	player = player_manager->player;

	bom_type = [&]() {
		switch (ebom_type) {
			case eBom_Type::Fullrange:
				Fullrange_Shot(player->magazine);
				break;
			default: break;
		}
	};
}

// �e���̈ʒu��ς���(��])
void Player_Weapon::Rotation() {
	// �������͂œ����Ȃ��悤��
	if (CheckHitKey(KEY_INPUT_LEFT) && CheckHitKey(KEY_INPUT_RIGHT)) {
		return;
	}

	if (CheckHitKey(KEY_INPUT_LEFT)) {
		degree += define_value.ROTATION_VALUE;
		radian = degree * DX_PI_F / 180;
		
		vector3d.x = center_position.x + radius * cos(radian);
		vector3d.y = center_position.y + radius * sin(radian);
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT)) {
		degree -= define_value.ROTATION_VALUE;
		radian = degree * DX_PI_F / 180;

		vector3d.x = center_position.x + radius * cos(radian);
		vector3d.y = center_position.y + radius * sin(radian);
	}
}

// �S���ʂɒe���΂��{��
void Player_Weapon::Fullrange_Shot(std::list<Bullet*> magazine) {
	// 20����΂�
	auto deglee = 360 / 20;

	for (auto bullet : magazine) {
		// �ʓx�@�ɕϊ�
		auto radian = deglee * DX_PI_F / 180;
	
		bullet->Set_X(vector3d.x);
		bullet->Set_Y(vector3d.y);
		bullet->Set_Speed(15);
		bullet->Set_Radian(radian);
		bullet->actor_state = eActor_State::Action;
	
		deglee += 360 / 20;
	}
}
