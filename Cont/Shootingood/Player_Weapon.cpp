#include"Bullet.h"
#include"Player_Weapon.h"
#include"Player_Manager.h"
#include"Random_Number_Generator.h"

// �R���X�g���N�^
Player_Weapon::Player_Weapon() : 
	degree(90), 
	enable_bomb(false),
	shot_button_flag(false),
	bomb_type(eBomb_Type::Fullrange),
	enable_bomb_type(eEnable_Bomb_Type::None), 
	timer(0) {

}

// �f�X�g���N�^
Player_Weapon::~Player_Weapon() {}

// �������֐�
void Player_Weapon::Initialize() {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	player = player_manager->player;

	// ���f���̑傫���ɍ��������a��ݒ�
	radius = player->size.height / 2 + 15;
	// �����z�u�̏e���̊p�x��ݒ�
	radian = degree * DX_PI_F / 180;
	// ���S���W���擾
	center_position = player->vector3d;
	// �e���̍��W��ݒ�
	vector3d.Set_Vector(center_position.x - 1.5f, center_position.y + 16.0f, center_position.z - radius);

	// �ʏ�U���̎˒���ݒ肷��
	distance_limit.x -= fire_range * cos(radian);
	distance_limit.z -= fire_range * sin(radian);

	// �e�ۂ��v�[�����O
	for (int i = 0; i < define_value.MAX_BULLET; ++i) {
		Bullet* pool_bullet = new Bullet();
		pool_bullet->actor_state = eActor_State::Break;
		player->magazine.push_back(pool_bullet);
	}

	// �����{����ݒ�
	shoot_bomb = [&]() {
		Fullrange_Shot();
	};
	bullet_erase = [&]() {
		Time_Limit_Erase_Bullet();
	};
}

// �X�V����
void Player_Weapon::Update() {
	// �U��
	Fire();
	// �L�[���͂ŏe������]������
	Rotation();

	if (enable_bomb) {
		// �e������
		bullet_erase();

		// �{����I������
		Chose_Bomb();
	}
}

// �`��
void Player_Weapon::Render() {
	// �����o�����{���̒e��`��
	for (auto bomb_bullet : bomb_bullets) {
		bomb_bullet->Render();
	}
}

// �U�����s��
void Player_Weapon::Fire() {
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		// �ʏ�U��
		if (shot_button_flag == false) {
		}
		shot_button_flag = true;
	}
	else {
		shot_button_flag = false;
	}

	if (!enable_bomb) {
		if (CheckHitKey(KEY_INPUT_Z)) {
			shoot_bomb();
			bullet_erase = [&]() {
				switch (bomb_type) {
				case eBomb_Type::Fullrange:
					Time_Limit_Erase_Bullet();
					break;
				case eBomb_Type::Rain:
					Reference_Coordinates_Erase_Bullet(bomb_bullets);
				default: break;
				}
			};
		}
	}
}

// �I�𒆂̃{���̒e����ݒ肷��
void Player_Weapon::Set_Bomb() {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	player = player_manager->player;

	shoot_bomb = [&]() {
		switch (bomb_type) {
			case eBomb_Type::Fullrange:
				Fullrange_Shot();
				break;
			case eBomb_Type::Rain:
				Rain();
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

// ��ʊO�ɏo���e���v�[���ւ��ǂ�
void Player_Weapon::Return_Bullet_Pooling() {
	// �d�����I�����e���v�[���ɖ߂�
	for (auto bomb_bullet : bomb_bullets) {
		player->magazine.push_back(bomb_bullet);
	}
}

// �{����I������
void Player_Weapon::Chose_Bomb() {
	//TODO: �{���̌��Ă���������߂� �Ƃ肠����2��ޑłĂ�悤�ɂ��Ă���
	if (CheckHitKey(KEY_INPUT_A)) {
		bomb_type = eBomb_Type::Fullrange;
		Set_Bomb();
	}
	else if (CheckHitKey(KEY_INPUT_S)) {
		bomb_type = eBomb_Type::Rain;
		Set_Bomb();
	}
}

// �S���ʂɒe���΂��{��
void Player_Weapon::Fullrange_Shot() {
	// 20����360���͈̔͂ŋϓ��ɂȂ�悤��
	auto fire_angle_degree = 360 / 20;

	for (int i = 0; i < 20; ++i) {
		bullet = player->magazine.back();
		bomb_bullets.push_back(bullet);
		player->magazine.pop_back();
	}

	for (auto bomb_bullet : bomb_bullets) {
		// �����o���ʒu(�p�x)�����W�A���ɕϊ�
		auto fire_angle_radian = fire_angle_degree * DX_PI_F / 180;
	
		bomb_bullet->Set_X(vector3d.x);
		bomb_bullet->Set_Z(vector3d.z);
		bomb_bullet->Set_Speed(15,0,15);
		bomb_bullet->Set_Radian(fire_angle_radian);
		bomb_bullet->actor_state = eActor_State::Action;
		
		fire_angle_degree += 360 / 20;
		
		clear_count = 30;
	}
	// �{���U�����t���O���I��
	enable_bomb = true;
	// �s���Ă���U����ݒ�
	enable_bomb_type = eEnable_Bomb_Type::Fullrange;
}

// �U�����~�炷
void Player_Weapon::Rain() {
	// �����_�}�C�U�[
	Utility::Number_Generator *random_number;
	random_number = new Utility::Number_Generator;

	for (int i = 0; i < 30; ++i) {
		bullet = player->magazine.back();
		bomb_bullets.push_back(bullet);
		player->magazine.pop_back();
	}

	for (auto bomb_bullet : bomb_bullets) {
		// �ʓx�@�ɕϊ�
		auto fire_angle = 180 * DX_PI_F / 180;

		//TOOD:�ЂƂ܂�����������v����
		bomb_bullet->Set_X(random_number->Generate_Number(-300.0f, 300.0f));
		bomb_bullet->Set_Y(random_number->Generate_Number(400.0f, 800.0f));
		bomb_bullet->Set_Z(random_number->Generate_Number(-300.0f, 300.0f));
		bomb_bullet->Set_Speed(0, -10, 0);
		bomb_bullet->Set_Radian(fire_angle);
		bomb_bullet->actor_state = eActor_State::Action;
	}
	// �{���U�����t���O���I��
	enable_bomb = true;
	// �s���Ă���U����ݒ�
	enable_bomb_type = eEnable_Bomb_Type::Rain;
}

// ���Ԍo�߂Œe������
void Player_Weapon::Time_Limit_Erase_Bullet() {
	if (timer == clear_count) {
		Return_Bullet_Pooling();
		bomb_bullets.clear();
		timer = 0;

		enable_bomb = false;
		enable_bomb_type = eEnable_Bomb_Type::None;
	}
	++timer;
}

// ���W���݂Ēe������
void Player_Weapon::Reference_Coordinates_Erase_Bullet(std::list<Bullet*>& bullets) {	
	for (auto iterator = bullets.begin(); iterator != bullets.end();) {
		// �n�ʂɓ��B���Ă�����̂�����΃v�[���֖߂�
		if ((*iterator)->Get_Y() <= 0) {
			player->magazine.push_back(*iterator);
			iterator = bullets.erase(iterator);
		}
		else {
			++iterator;
		}

		// �S�Ă̒e����������U���I��
		if (bullets.size() == 0) {
			enable_bomb = false;
			enable_bomb_type = eEnable_Bomb_Type::None;
		}
	}
}

// �ʏ�U���̎˒����E�_��Ԃ�
Vector3D Player_Weapon::Get_Limit_Range() {
	Vector3D result = vector3d;

	// �ʏ�U���̔򋗗������������W�����߂�
	result.Move(fire_range * cos(radian), 0, fire_range * sin(radian));

	return result;
}
