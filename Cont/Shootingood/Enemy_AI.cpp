#include"Enum.h"
#include"Enemy_AI.h"
#include"Enemy_Manager.h"

// �R���X�g���N�^
Enemy_AI::Enemy_AI() {
	// �U�����s���܂ł�false;
	is_counter_reset = false;
	// �O���琔����
	attack_counter = 0;
}

// �f�X�g���N�^
Enemy_AI::~Enemy_AI() {}

// ���t���[������
void Enemy_AI::Update() {
	// �ړ�
	Move();
	// �U��
	Fire();

	++attack_counter;

	// �������e����ʉ�������o�Ă��������
	Bullet_Over_Max_Y_Erase();
}

// �ړ�
void Enemy_AI::Move() {
	// �G�l�~�[�̃}�l�[�W���N���X
	std::unique_ptr<Enemy_Manager>& enemy_manager = Enemy_Manager::Get_Instance();
	
	for (auto& enemy : enemy_manager->enemies) {
		auto enemy_x = enemy.Get_X();
		auto enemy_y = enemy.Get_Y();
		auto enemy_status = enemy.enemy_status;

		// �ړ�
		enemy.Set_X(enemy_x += enemy_status->Get_Speed());
		
		// �i�s�����ɂ���ď�����ς���
		switch (enemy_status->move_direction) {
		// �E�ɐi��ł���Ƃ�
		case eMove_Direction::Right:
			// ��ʉE�[����o�悤�Ƃ��Ă��Ȃ���
			if (Is_Over_Max_X(enemy.Get_Right_Edge())) {
				// 1�i������
				enemy.Set_Y(enemy_y + enemy.Get_Width());
				// ��ʂ���o�Ȃ��悤��
				enemy.Set_X(define_value.MAX_SCREEN_X - enemy.Get_Width());
				// �i�s�����𐳔��΂�
				enemy_status->U_Turn();
				enemy_status->move_direction = eMove_Direction::Left;
			}
			break;
		// ��ʍ��[����o�悤�Ƃ��Ă��Ȃ���
		case eMove_Direction::Left:
			if (Is_Over_MIn_X(enemy.Get_Left_Edge())) {
				// 1�i������
				enemy.Set_Y(enemy_y + enemy.Get_Width());
				// ��ʂ���o�Ȃ��悤��
				enemy.Set_X(define_value.MIN_SCREEN_X);
				// �i�s�����𐳔��΂�
				enemy_status->U_Turn();
				enemy_status->move_direction = eMove_Direction::Right;
			}
			break;
		}
	}
}

// �U��
void Enemy_AI::Fire() {
	std::unique_ptr<Enemy_Manager>& enemy_manager = Enemy_Manager::Get_Instance();

	for(auto& enemy : enemy_manager->enemies) {
	if (attack_counter == enemy.enemy_status->Get_Attack_Span()) {
			enemy_manager->enemy_bullet.emplace_back(enemy.Get_Shot_Point(), enemy.Get_Bottom_Edge(), 0, enemy.enemy_status->Get_Bullet_Speed());
			// �U���������̂Ń��Z�b�g
			is_counter_reset = true;
		}
	}

	// �U��������J�E���g��������
	if (is_counter_reset) {
		attack_counter = 0;
		is_counter_reset = false;
	}
}

// �E�[����o�悤�Ƃ��ĂȂ���
bool Enemy_AI::Is_Over_Max_X(int coordinate_x) {
	return coordinate_x > define_value.MAX_SCREEN_X;
}

// ���[����o�悤�Ƃ��ĂȂ���
bool Enemy_AI::Is_Over_MIn_X(int coordinate_x) {
	return coordinate_x < define_value.MIN_SCREEN_X;
}

// �G�l�~�[�̌������e����ʉ��[����o�������
void Enemy_AI::Bullet_Over_Max_Y_Erase() {
	std::unique_ptr<Enemy_Manager>& enemy_manager = Enemy_Manager::Get_Instance();
	for (int i = 0; i < enemy_manager->enemies.size(); ++i) {
		for (auto& enemy_bullet : enemy_manager->enemy_bullet) {
			if (enemy_bullet.Is_Over_Max_Y()) {
				enemy_manager->enemy_bullet.erase(enemy_manager->enemy_bullet.begin());
			}
		}
	}
}
