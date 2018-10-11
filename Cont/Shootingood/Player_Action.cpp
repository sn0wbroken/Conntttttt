#include "Player_Action.h"
#include"Player_Manager.h"

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

// 毎フレーム呼ばれる
void Player_Action::Update() {
	// プレイヤーの操作を受け付ける 毎フレーム呼び出し
	Player_Controll();
	// 打ち出した弾丸が画面外に出ていたら消す
	Bullet_Off_Screen_Erase();
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
	Set_Shot_Pattern();
}

// プレイヤーを移動させる
void Player_Action::Move() {
	// 同時押しでは動かないように
	if (CheckHitKey(KEY_INPUT_RIGHT) && CheckHitKey(KEY_INPUT_LEFT)) {
		return;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		int player_x = player->Get_X();
		player->Set_X(player_x += player_status->Get_Speed());
	}
	else if (CheckHitKey(KEY_INPUT_LEFT)) {
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

// 状態に応じたショットを設定する
void Player_Action::Set_Shot_Pattern() {
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

// 攻撃の種類を切り替える。毎フレーム受付ける
void Player_Action::Change_Fire_Type() {
	if (key_checker->key[KEY_INPUT_A] == 1) {
		shot_type = ePlayer_Shot_Type::Straight;
		// 直線攻撃のものに
		Set_Shot_Pattern();
	}

	// 打ち出すx軸の位置を変える
	counter += 2;
	rad = static_cast<float>(counter * M_PI / 180.0f);
	position_x = std::sin(rad) * amplitude;
	if (key_checker->key[KEY_INPUT_S] == 1) {
		shot_type = ePlayer_Shot_Type::Wave;
		fire_type = [&]() {
			// 波状攻撃のものに
			Set_Shot_Pattern();
		};
	}
}

// 打ち出した弾丸が画面外に出ているか判断する
bool Player_Action::Check_Off_Screen(Bullet& player_bullet) {
	return player_bullet.Is_Over_Max_X() || player_bullet.Is_Over_Min_X() ||
		   player_bullet.Is_Over_Max_Y() || player_bullet.Is_Over_Min_Y();
}

// 打ち出した弾丸が範囲外に出ていたら消す
void Player_Action::Bullet_Off_Screen_Erase() {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	for (auto& player_bullet : player_manager->player->player_bullet) {
		if (Check_Off_Screen(player_bullet)) {
			player_manager->player->player_bullet.erase(player_manager->player->player_bullet.begin());
		}
	}
}
