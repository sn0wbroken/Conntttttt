#include"Bullet.h"
#include"Player_Weapon.h"
#include"Player_Manager.h"
#include "Random_Number_Generator.h"

// �R���X�g���N�^
Player_Weapon::Player_Weapon() : 
	degree(90), 
	living_bomb(false), 
	timer(0) {

}

// �f�X�g���N�^
Player_Weapon::~Player_Weapon() {}

// �������֐�
void Player_Weapon::Initialize() {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	player = player_manager->player;

	// ���f���̑傫���ɍ��������a��ݒ�
	radius = player->Get_Height() / 2 + 15;
	// �����z�u�̏e���̊p�x��ݒ�
	radian = degree * DX_PI_F / 180;
	// ���S���W���擾
	center_position = player->vector3d;
	// �e���̍��W��ݒ�
	vector3d.Set_Vector(center_position.x - 1.5, center_position.y + 16, center_position.z - radius);

	// �ʏ�U���̎˒���ݒ肷��
	distance_limit.x -= fire_range * cos(radian);
	distance_limit.z -= fire_range * sin(radian);

	// �e�ۂ��v�[�����O
	for (int i = 0; i < define_value.MAX_BULLET; ++i) {
		Bullet* bullet = new Bullet();
		bullet->actor_state = eActor_State::Break;
		player->magazine.push_back(bullet);
	}

	// �����{����ݒ�
	bomb_type = [&]() {
		Fullrange_Shot(player->magazine);
	};
}

// �X�V����
void Player_Weapon::Update() {
	// �U��
	Fire();
	// �L�[���͂ŏe������]������
	Rotation();
	// �{����I������
	Chose_Bomb();
	// �{���̒e���L�����ǂ����𔻒f����
	Check_Enable_Bomb();

	// �q�ɂ���
	Actor::Update();
}

// �`��
void Player_Weapon::Render() {
	// �����o�����{���̒e��`��
	for (auto bullet : bomb_bullets) {
		bullet->Render();
	}
}

// �U�����s��
void Player_Weapon::Fire() {
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		// �ʏ�U��
	}

	if (CheckHitKey(KEY_INPUT_RETURN)) {
		bomb_type();
		living_bomb = true;
	}
}

// ��Ԃɉ������{����ݒ肷��
void Player_Weapon::Set_Bomb() {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	player = player_manager->player;

	bomb_type = [&]() {
		switch (ebomb_type) {
			case eBomb_Type::Fullrange:
				Fullrange_Shot(player->magazine);
				break;
			case eBomb_Type::Rain:
				Rain(player->magazine);
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
		vector3d.z = center_position.z + radius * sin(radian);
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT)) {
		degree -= define_value.ROTATION_VALUE;
		radian = degree * DX_PI_F / 180;

		vector3d.x = center_position.x + radius * cos(radian);
		vector3d.z = center_position.z + radius * sin(radian);
	}
}

// �{���̒e���L�����ǂ����𔻒f����
void Player_Weapon::Check_Enable_Bomb() {
	if (living_bomb) {
		if (timer == clear_count) {
 			Return_Bullet_Pooling();
			bomb_bullets.clear();
			living_bomb = false;
			timer = 0;
		}
		++timer;
	}
}

// ��ʊO�ɏo���e���v�[���ւ��ǂ�
void Player_Weapon::Return_Bullet_Pooling() {
	// �d�����I�����e���v�[���ɖ߂�
	for (auto bullet : bomb_bullets) {
		player->magazine.push_back(bullet);
	}
}

// �{����I������
void Player_Weapon::Chose_Bomb() {
	//TODO: �{���̌��Ă���������߂� �Ƃ肠����2��ޑłĂ�悤�ɂ��Ă���
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		ebomb_type = eBomb_Type::Fullrange;
	}
	else if (CheckHitKey(KEY_INPUT_LEFT)) {
		ebomb_type = eBomb_Type::Rain;
	}
	Set_Bomb();
}

// �S���ʂɒe���΂��{��
void Player_Weapon::Fullrange_Shot(std::list<Bullet*> magazine) {
	// 20����΂�
	auto degree = 360 / 20;

	for (int i = 0; i < 20; ++i) {
		bullet = player->magazine.back();
		bomb_bullets.push_back(bullet);
		player->magazine.pop_back();
	}

	for (auto bullet : bomb_bullets) {
		// �ʓx�@�ɕϊ�
		auto radian = degree * DX_PI_F / 180;
	
		bullet->Set_X(vector3d.x);
		bullet->Set_Z(vector3d.z);
		bullet->Set_Speed(15,0,15);
		bullet->Set_Radian(radian);
		bullet->actor_state = eActor_State::Action;
		
		degree += 360 / 20;
		
		clear_count = 30;
	}
}

// �U�����~�炷
void Player_Weapon::Rain(std::list<Bullet*> magazine) {
	// �����_�}�C�U�[
	Utility::Number_Generator *random_number;
	random_number = new Utility::Number_Generator;

	for (int i = 0; i < 30; ++i) {
		bullet = player->magazine.back();
		bomb_bullets.push_back(bullet);
		player->magazine.pop_back();
	}

	for (auto bullet : bomb_bullets) {
		// �ʓx�@�ɕϊ�
		auto radian = 180 * DX_PI_F / 180;

		bullet->Set_X(random_number->Generate_Number(-300, 300));
		bullet->Set_Y(random_number->Generate_Number(400, 800));
		bullet->Set_Z(random_number->Generate_Number(-300, 300));
		bullet->Set_Speed(0, -10, 0);
		bullet->Set_Radian(radian);
		bullet->actor_state = eActor_State::Action;	

		clear_count = 100;
	}
}
