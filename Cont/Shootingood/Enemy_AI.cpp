#include"Enum.h"
#include"Enemy_AI.h"
#include"Enemy_Manager.h"

#include<cmath>

// �R���X�g���N�^
Enemy_AI::Enemy_AI() {
}

// �f�X�g���N�^
Enemy_AI::~Enemy_AI() {}

// ���t���[������
void Enemy_AI::Update() {
	Move_Enemy();
}

// �G�𓮂���
void Enemy_AI::Move_Enemy() {
	std::unique_ptr<Enemy_Manager>& enemy_manager = Enemy_Manager::Get_Instance();
	auto enemies = enemy_manager->active_enemies;
	auto speed = define_value.ENEMY_SPEED;

	for (auto enemy : enemies) {
		enemy->vector3d.Move(speed * std::cosf(enemy->Get_Radian()), 0.0f, speed * std::sinf(enemy->Get_Radian()));
		enemy->Add_WalkAnimIndex();

		// �����蔻����ꏏ�ɓ�����
		for (auto iterator = begin(enemy->rects); iterator != end(enemy->rects); ++iterator) {
			iterator->second.Move(speed, enemy->Get_Radian());

			// ����Ɏg���̂őO�ʂ����͈ꏏ�ɓ�����
			if (iterator == enemy->rects.find("front_face")) {
				iterator->second.center_position.Move(speed * cosf(enemy->Get_Radian()), 0.0f, speed * sinf(enemy->Get_Radian()));
			}
		}
	}
}
