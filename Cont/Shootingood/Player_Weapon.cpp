#include"Player_Weapon.h"
#include"Player_Manager.h"
#include"Bullet.h"

// コンストラクタ
Player_Weapon::Player_Weapon() : 
	degree(90), 
	living_bomb(false), 
	timer(0) {

}

// デストラクタ
Player_Weapon::~Player_Weapon() {}

// 初期化関数
void Player_Weapon::Initialize() {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	player = player_manager->player;

	// モデルの大きさに合った半径を設定
	radius = player->Get_Height() / 2 + 15;
	// 初期配置の銃口の角度を設定
	radian = degree * DX_PI_F / 180;
	// 中心座標を取得
	center_position = player->vector3d;
	// 銃口の座標を設定
	vector3d.Arrange(center_position.x - 1.5, center_position.y + 16, center_position.z - radius);

	// 飛距離限界は銃口の座標を基準点とする
	distance_limit = vector3d;
	// 初期位置での弾の飛距離限界点を求める
	Calculate_Distance_Limit();

	// 弾丸をプーリング
	for (int i = 0; i < define_value.MAX_BULLET; ++i) {
		Bullet* bullet = new Bullet();
		bullet->actor_state = eActor_State::Break;
		player->magazine.push_back(bullet);
	}
}

// 更新処理
void Player_Weapon::Update() {
	// 攻撃
	Fire();
	// キー入力で銃口を回転させる
	Rotation();

	// ボムの弾が有効かどうかを判断する
	Check_Enable_Bomb();

	// 子にも回す
	Actor::Update();
}

// 描画
void Player_Weapon::Render() {
	// 通常射撃の照準(弾の軌道)を線分で描画
	DrawLine3D(vector3d.GetVECTOR(), distance_limit.GetVECTOR(), GetColor(255, 0, 0));
	
	// 撃ち出したボムの弾を描画
	for (auto bullet : bomb_bullets) {
		bullet->Render();
	}
}

// 弾を生成(発射)
void Player_Weapon::Fire() {
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		ebomb_type = eBomb_Type::Fullrange;
		//TODO:今は1種なので適当に撃った瞬間に関数を代入してる
		Set_Bomb();
		bomb_type();
		living_bomb = true;
	}
}

// 状態に応じたボムを設定する
void Player_Weapon::Set_Bomb() {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	player = player_manager->player;

	bomb_type = [&]() {
		switch (ebomb_type) {
			case eBomb_Type::Fullrange:
				Fullrange_Shot(player->magazine);
				break;
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

	// 弾の飛距離限界点を求める
	Calculate_Distance_Limit();
}

// ボムの弾が有効かどうかを判断する
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

// 画面外に出た弾をプールへもどす
void Player_Weapon::Return_Bullet_Pooling() {
	// 仕事を終えた弾をプールに戻す
	for (auto bullet : bomb_bullets) {
		player->magazine.push_back(bullet);
	}
}

// 弾の飛距離限界点を求める
void Player_Weapon::Calculate_Distance_Limit() {
	// 基準座標を取得
	distance_limit = vector3d;

	// 向いている方向へ点を打っていき、画面端へ到達した座標を飛距離限界点とする
	//while (true) {
	//	if (distance_limit.x >= define_value.MAX_SCREEN_X || distance_limit.x <= define_value.MIN_SCREEN_X ||
	//		distance_limit.y >= define_value.WINDOW_Y     || distance_limit.y <= define_value.MIN_WINDOW_Y) {
	//		break;
	//	}

		distance_limit.x -= 300 * cos(radian);
		distance_limit.z -= 300 * sin(radian);
	//}
}

// 全方位に弾を飛ばすボム
void Player_Weapon::Fullrange_Shot(std::list<Bullet*> magazine) {
	// 20発飛ばす
	auto degree = 360 / 20;

	for (int i = 0; i < 20; ++i) {
		bullet = player->magazine.back();
		bomb_bullets.push_back(bullet);
		player->magazine.pop_back();
	}

	for (auto bullet : bomb_bullets) {
		// 弧度法に変換
		auto radian = degree * DX_PI_F / 180;
	
		bullet->Set_X(vector3d.x);
		bullet->Set_Z(vector3d.z);
		bullet->Set_Speed(15);
		bullet->Set_Radian(radian);
		bullet->actor_state = eActor_State::Action;	
		
		degree += 360 / 20;
		
		clear_count = 30;
	}
}
