#include "Player_Action.h"

// コンストラクタ
Player_Action::Player_Action(std::shared_ptr<Player> set_player,
							 std::shared_ptr<Player_Status> set_player_statsu) {
	player = set_player;
	player_status = set_player_statsu;

	counter = 0;
	amplitude = 15;

	// 最初は直線のもの
	shot_type = ePlayer_Shot_Type::Straight;
}

// デストラクタ
Player_Action::~Player_Action() {

}

// プレイヤーの操作を受け付ける 毎フレーム呼び出し
void Player_Action::Player_Controll() {
	// 移動
	Move();
	// 攻撃
	Fire();
	// ショットタイプの切り替え
	Change_Fire_Type();
}

// 初期化
void Player_Action::Initialize() {
	// 初期状態は直線に飛ばすもの
	fire_type = [&]() {
		switch (shot_type) {
			case ePlayer_Shot_Type::Straight:
				// パワーアップ状態に応じて強弱を分ける
				if (player->Get_Power_Up()) {
					player->player_bullet.emplace_back(player->Get_Shoot_Point() - (player->Get_Width() / 2), player->Get_Y(), 0, -define_value.PLAYER_BULLET_SPEED);
					player->player_bullet.emplace_back(player->Get_Shoot_Point() + (player->Get_Width() / 2), player->Get_Y(), 0, -define_value.PLAYER_BULLET_SPEED);
				}
				else {
					player->player_bullet.emplace_back(player->Get_Shoot_Point(), player->Get_Y(), 0, -define_value.PLAYER_BULLET_SPEED);
				}
			break;
			case ePlayer_Shot_Type::Wave:
				// 波状攻撃のものに
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

// プレイヤーを移動させる
void Player_Action::Move() {
	// 同時押しでは動かないように
	if (CheckHitKey(KEY_INPUT_RIGHT) && CheckHitKey(KEY_INPUT_LEFT)) {
		return;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		// 画面端であったら移動しない
		if (Is_Over_Max_X()) {
			return;
		}

		int player_x = player->Get_X();
		player->Set_X(player_x += player_status->Get_Speed());
	}
	else if (CheckHitKey(KEY_INPUT_LEFT)) {
		// 画面端であったら移動しない
		if (Is_Over_Min_X()) {
			return;
		}

		int player_x = player->Get_X();
		player->Set_X(player_x -= player_status->Get_Speed());
	}
}

// 弾を発射
void Player_Action::Fire() {
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		fire_type();
	}
}

// 攻撃の種類を切り替える。毎フレーム受付ける
void Player_Action::Change_Fire_Type() {
	if (key_checker->key[KEY_INPUT_A] == 1) {
		shot_type = ePlayer_Shot_Type::Straight;

		// 直線攻撃のものに
		fire_type = [&]() {
			// パワーアップ状態に応じて強弱を分ける
			if (player->Get_Power_Up()) {
				player->player_bullet.emplace_back(player->Get_Shoot_Point() - (player->Get_Width() / 2), player->Get_Y(), 0, -define_value.PLAYER_BULLET_SPEED);
				player->player_bullet.emplace_back(player->Get_Shoot_Point() + (player->Get_Width() / 2), player->Get_Y(), 0, -define_value.PLAYER_BULLET_SPEED);
			}
			else {
				player->player_bullet.emplace_back(player->Get_Shoot_Point(), player->Get_Y(), 0, -define_value.PLAYER_BULLET_SPEED);
			}
		};
	}

	// 打ち出すx軸の位置を変える
	counter += 2;
	rad = static_cast<float>(counter * M_PI / 180.0f);
	position_x = std::sin(rad) * amplitude;
	if (key_checker->key[KEY_INPUT_S] == 1) {
		shot_type = ePlayer_Shot_Type::Wave;

		fire_type = [&]() {
			// 波状攻撃のものに
			if (player->Get_Power_Up()) {
				player->player_bullet.emplace_back(player->Get_Shoot_Point(), player->Get_Y(), static_cast<int>(position_x), -define_value.PLAYER_BULLET_SPEED);
				player->player_bullet.emplace_back(player->Get_Shoot_Point(), player->Get_Y(), static_cast<int>(-position_x), -define_value.PLAYER_BULLET_SPEED);
			}
			else {
				player->player_bullet.emplace_back(player->Get_Shoot_Point(), player->Get_Y(), static_cast<int>(position_x), -define_value.PLAYER_BULLET_SPEED);
			}
		};
	}
}

// 画面右端から出ようとしているかどうか。出ようとしていたらtrue
bool Player_Action::Is_Over_Max_X() {
	return player->Get_Right_Edge() >= define_value.MAX_SCREEN_X;
}

// 画面左端から出ようとしているかどうか。出ようとしていたらtrue
bool Player_Action::Is_Over_Min_X() {
	return player->Get_Left_Edge() <= define_value.MIN_SCREEN_X;;
}
