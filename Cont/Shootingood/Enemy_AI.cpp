#include"Enum.h"
#include"Enemy_AI.h"
#include"Enemy_Manager.h"

// コンストラクタ
Enemy_AI::Enemy_AI() {
	// 攻撃を行うまではfalse;
	is_counter_reset = false;
	// ０から数える
	attack_counter = 0;
}

// デストラクタ
Enemy_AI::~Enemy_AI() {}

// 毎フレーム入る
void Enemy_AI::Update() {
	// 移動
	Move();
	// 攻撃
	Fire();

	++attack_counter;

	// 撃った弾が画面下部から出ていたら消す
	Bullet_Over_Max_Y_Erase();
}

// 移動
void Enemy_AI::Move() {
	// エネミーのマネージャクラス
	std::unique_ptr<Enemy_Manager>& enemy_manager = Enemy_Manager::Get_Instance();
	
	for (auto& enemy : enemy_manager->enemies) {
		auto enemy_x = enemy.Get_X();
		auto enemy_y = enemy.Get_Y();
		auto enemy_status = enemy.enemy_status;

		// 移動
		enemy.Set_X(enemy_x += enemy_status->Get_Speed());
		
		// 進行方向によって処理を変える
		switch (enemy_status->move_direction) {
		// 右に進んでいるとき
		case eMove_Direction::Right:
			// 画面右端から出ようとしていないか
			if (Is_Over_Max_X(enemy.Get_Right_Edge())) {
				// 1段下げる
				enemy.Set_Y(enemy_y + enemy.Get_Width());
				// 画面から出ないように
				enemy.Set_X(define_value.MAX_SCREEN_X - enemy.Get_Width());
				// 進行方向を正反対に
				enemy_status->U_Turn();
				enemy_status->move_direction = eMove_Direction::Left;
			}
			break;
		// 画面左端から出ようとしていないか
		case eMove_Direction::Left:
			if (Is_Over_MIn_X(enemy.Get_Left_Edge())) {
				// 1段下げる
				enemy.Set_Y(enemy_y + enemy.Get_Width());
				// 画面から出ないように
				enemy.Set_X(define_value.MIN_SCREEN_X);
				// 進行方向を正反対に
				enemy_status->U_Turn();
				enemy_status->move_direction = eMove_Direction::Right;
			}
			break;
		}
	}
}

// 攻撃
void Enemy_AI::Fire() {
	std::unique_ptr<Enemy_Manager>& enemy_manager = Enemy_Manager::Get_Instance();

	for(auto& enemy : enemy_manager->enemies) {
	if (attack_counter == enemy.enemy_status->Get_Attack_Span()) {
			enemy_manager->enemy_bullet.emplace_back(enemy.Get_Shot_Point(), enemy.Get_Bottom_Edge(), 0, enemy.enemy_status->Get_Bullet_Speed());
			// 攻撃をしたのでリセット
			is_counter_reset = true;
		}
	}

	// 攻撃したらカウントを初期化
	if (is_counter_reset) {
		attack_counter = 0;
		is_counter_reset = false;
	}
}

// 右端から出ようとしてないか
bool Enemy_AI::Is_Over_Max_X(int coordinate_x) {
	return coordinate_x > define_value.MAX_SCREEN_X;
}

// 左端から出ようとしてないか
bool Enemy_AI::Is_Over_MIn_X(int coordinate_x) {
	return coordinate_x < define_value.MIN_SCREEN_X;
}

// エネミーの撃った弾が画面下端から出たら消す
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
