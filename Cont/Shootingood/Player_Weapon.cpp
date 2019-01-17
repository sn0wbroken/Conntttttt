#include"Bullet.h"
#include"Player_Weapon.h"
#include"Player_Manager.h"
#include"Random_Number_Generator.h"

// コンストラクタ
Player_Weapon::Player_Weapon() : 
	degree(90), 
	enable_bomb(false),
	shot_button_flag(false),
	bomb_type(eBomb_Type::Fullrange),
	enable_bomb_type(eEnable_Bomb_Type::None), 
	timer(0) {

}

// デストラクタ
Player_Weapon::~Player_Weapon() {}

// 初期化関数
void Player_Weapon::Initialize() {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	player = player_manager->player;

	// モデルの大きさに合った半径を設定
	radius = player->size.height / 2 + 15;
	// 初期配置の銃口の角度を設定
	radian = degree * DX_PI_F / 180;
	// 中心座標を取得
	center_position = player->vector3d;
	// 銃口の座標を設定
	vector3d.Set_Vector(center_position.x - 1.5f, center_position.y + 16.0f, center_position.z - radius);

	// 通常攻撃の射程を設定する
	distance_limit.x -= fire_range * cos(radian);
	distance_limit.z -= fire_range * sin(radian);

	// 弾丸をプーリング
	for (int i = 0; i < define_value.MAX_BULLET; ++i) {
		Bullet* pool_bullet = new Bullet();
		pool_bullet->actor_state = eActor_State::Break;
		player->magazine.push_back(pool_bullet);
	}

	// 初期ボムを設定
	shoot_bomb = [&]() {
		Fullrange_Shot();
	};
	bullet_erase = [&]() {
		Time_Limit_Erase_Bullet();
	};
}

// 更新処理
void Player_Weapon::Update() {
	// 攻撃
	Fire();
	// キー入力で銃口を回転させる
	Rotation();

	if (enable_bomb) {
		// 弾を消す
		bullet_erase();

		// ボムを選択する
		Chose_Bomb();
	}
}

// 描画
void Player_Weapon::Render() {
	// 撃ち出したボムの弾を描画
	for (auto bomb_bullet : bomb_bullets) {
		bomb_bullet->Render();
	}
}

// 攻撃を行う
void Player_Weapon::Fire() {
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		// 通常攻撃
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

// 選択中のボムの弾幕を設定する
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

// 銃口の位置を変える(回転)
void Player_Weapon::Rotation() {
	// 同時入力で動かないように
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

// 画面外に出た弾をプールへもどす
void Player_Weapon::Return_Bullet_Pooling() {
	// 仕事を終えた弾をプールに戻す
	for (auto bomb_bullet : bomb_bullets) {
		player->magazine.push_back(bomb_bullet);
	}
}

// ボムを選択する
void Player_Weapon::Chose_Bomb() {
	//TODO: ボムの撃てる条件を決める とりあえず2種類打てるようにしておく
	if (CheckHitKey(KEY_INPUT_A)) {
		bomb_type = eBomb_Type::Fullrange;
		Set_Bomb();
	}
	else if (CheckHitKey(KEY_INPUT_S)) {
		bomb_type = eBomb_Type::Rain;
		Set_Bomb();
	}
}

// 全方位に弾を飛ばすボム
void Player_Weapon::Fullrange_Shot() {
	// 20発を360°の範囲で均等になるように
	auto fire_angle_degree = 360 / 20;

	for (int i = 0; i < 20; ++i) {
		bullet = player->magazine.back();
		bomb_bullets.push_back(bullet);
		player->magazine.pop_back();
	}

	for (auto bomb_bullet : bomb_bullets) {
		// 撃ち出す位置(角度)をラジアンに変換
		auto fire_angle_radian = fire_angle_degree * DX_PI_F / 180;
	
		bomb_bullet->Set_X(vector3d.x);
		bomb_bullet->Set_Z(vector3d.z);
		bomb_bullet->Set_Speed(15,0,15);
		bomb_bullet->Set_Radian(fire_angle_radian);
		bomb_bullet->actor_state = eActor_State::Action;
		
		fire_angle_degree += 360 / 20;
		
		clear_count = 30;
	}
	// ボム攻撃中フラグをオン
	enable_bomb = true;
	// 行っている攻撃を設定
	enable_bomb_type = eEnable_Bomb_Type::Fullrange;
}

// 攻撃を降らす
void Player_Weapon::Rain() {
	// ランダマイザー
	Utility::Number_Generator *random_number;
	random_number = new Utility::Number_Generator;

	for (int i = 0; i < 30; ++i) {
		bullet = player->magazine.back();
		bomb_bullets.push_back(bullet);
		player->magazine.pop_back();
	}

	for (auto bomb_bullet : bomb_bullets) {
		// 弧度法に変換
		auto fire_angle = 180 * DX_PI_F / 180;

		//TOOD:ひとまず作っただけ要調整
		bomb_bullet->Set_X(random_number->Generate_Number(-300.0f, 300.0f));
		bomb_bullet->Set_Y(random_number->Generate_Number(400.0f, 800.0f));
		bomb_bullet->Set_Z(random_number->Generate_Number(-300.0f, 300.0f));
		bomb_bullet->Set_Speed(0, -10, 0);
		bomb_bullet->Set_Radian(fire_angle);
		bomb_bullet->actor_state = eActor_State::Action;
	}
	// ボム攻撃中フラグをオン
	enable_bomb = true;
	// 行っている攻撃を設定
	enable_bomb_type = eEnable_Bomb_Type::Rain;
}

// 時間経過で弾を消す
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

// 座標をみて弾を消す
void Player_Weapon::Reference_Coordinates_Erase_Bullet(std::list<Bullet*>& bullets) {	
	for (auto iterator = bullets.begin(); iterator != bullets.end();) {
		// 地面に到達しているものがあればプールへ戻す
		if ((*iterator)->Get_Y() <= 0) {
			player->magazine.push_back(*iterator);
			iterator = bullets.erase(iterator);
		}
		else {
			++iterator;
		}

		// 全ての弾が消えたら攻撃終了
		if (bullets.size() == 0) {
			enable_bomb = false;
			enable_bomb_type = eEnable_Bomb_Type::None;
		}
	}
}

// 通常攻撃の射程限界点を返す
Vector3D Player_Weapon::Get_Limit_Range() {
	Vector3D result = vector3d;

	// 通常攻撃の飛距離分動いた座標を求める
	result.Move(fire_range * cos(radian), 0, fire_range * sin(radian));

	return result;
}
