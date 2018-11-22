#include"Player_Weapon.h"
#include"Player_Manager.h"

// コンストラクタ
Player_Weapon::Player_Weapon() {}

// コピーコンストラクタ
Player_Weapon::Player_Weapon(std::shared_ptr<Player> set_player) {
	player = set_player;

	// 初期化関数を呼び出す
	Initialize();
}

// デストラクタ
Player_Weapon::~Player_Weapon() {}

// 更新処理
void Player_Weapon::Update() {
	// 攻撃
	Fire();
	// ショットタイプの切り替え
	Change_Fire_Type();
	// 打ち出した弾丸が画面外に出ていたら消す
	Bullet_Off_Screen_Erase();

	Actor::Update();
}

// 初期化関数
void Player_Weapon::Initialize() {
	// 座標を設定
	vector3.Arrange(player->Get_X(), player->Get_Y() + player->Get_Height() / 2, player->Get_Z());

	// ショットパターンを設定する
	fire_type = [&]() {
		//player->player_bullet.emplace_back(player->Get_Shoot_Point(), player->Get_Y(), 0, -define_value.PLAYER_BULLET_SPEED);

		std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(300.0f, 300.0f, 0.0f, 0.0f, 15.0f, 0.0f);
		Actor::Add_Child(bullet);
	};

	// パターンに状態を合わせる
	shot_type = ePlayer_Shot_Type::Straight;
}

// 弾を発射
void Player_Weapon::Fire() {
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		fire_type();
	}
}

// 状態に応じたショットを設定する
void Player_Weapon::Set_Shot_Pattern() {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	player = player_manager->player;

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
				
				std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(300.0f,300.0f,15.0f);
				Actor::Add_Child(bullet);
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
void Player_Weapon::Change_Fire_Type() {
	if (key_checker->key[KEY_INPUT_A] == 1) {
		shot_type = ePlayer_Shot_Type::Straight;
		// 直線攻撃のものに
		Set_Shot_Pattern();
	}

	// 打ち出すx軸の位置を変える
	counter += 2;
	radian = static_cast<float>(counter * DX_PI_F / 180.0f);
	position_x = std::sin(radian) * amplitude;
	if (key_checker->key[KEY_INPUT_S] == 1) {
		shot_type = ePlayer_Shot_Type::Wave;
		fire_type = [&]() {
			// 波状攻撃のものに
			Set_Shot_Pattern();
		};
	}
}

// 打ち出した弾丸が画面外に出ているか判断する
bool Player_Weapon::Check_Off_Screen(Bullet& player_bullet) {
	return player_bullet.Is_Over_Max_X() || player_bullet.Is_Over_Min_X() ||
		player_bullet.Is_Over_Max_Y() || player_bullet.Is_Over_Min_Y();
}

// 打ち出した弾丸が範囲外に出ていたら消す
void Player_Weapon::Bullet_Off_Screen_Erase() {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	for (auto& player_bullet : player_manager->player->player_bullet) {
		if (Check_Off_Screen(player_bullet)) {
			player_manager->player->player_bullet.erase(player_manager->player->player_bullet.begin());
		}
	}
}
