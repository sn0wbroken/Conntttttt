#include"Enum.h"
#include"Enemy_AI.h"
#include"Enemy_Manager.h"

#include<cmath>

// コンストラクタ
Enemy_AI::Enemy_AI() {
}

// デストラクタ
Enemy_AI::~Enemy_AI() {}

// 毎フレーム入る
void Enemy_AI::Update() {
	Move_Enemy();
}

// 敵を動かす
void Enemy_AI::Move_Enemy() {
	std::unique_ptr<Enemy_Manager>& enemy_manager = Enemy_Manager::Get_Instance();
	auto enemies = enemy_manager->active_enemies;
	auto speed = define_value.ENEMY_SPEED;

	for (auto enemy : enemies) {
		enemy->vector3d.Move(speed * std::cosf(enemy->Get_Radian()), 0.0f, speed * std::sinf(enemy->Get_Radian()));
		enemy->Add_WalkAnimIndex();

		// 当たり判定も一緒に動かす
		for (auto iterator = begin(enemy->rects); iterator != end(enemy->rects); ++iterator) {
			iterator->second.Move(speed, enemy->Get_Radian());

			// 判定に使うので前面だけは一緒に動かす
			if (iterator == enemy->rects.find("front_face")) {
				iterator->second.center_position.Move(speed * cosf(enemy->Get_Radian()), 0.0f, speed * sinf(enemy->Get_Radian()));
			}
		}
	}
}
