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

	// 半径を設定
	radius = player->Get_Height() / 2 + 18;
	// 中心座標を取得
	center_position = player->vector3d;
	// 銃口の座標を設定
	vector3d.Arrange(center_position.x, center_position.y + radius, center_position.z);

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
	Check_Enable_Bullet();

	// 子にも回す
	Actor::Update();
}

// 描画
void Player_Weapon::Render() {
	for (auto bullet : bomb_bullets) {
		bullet->Render();
	}
}

// 弾を生成(発射)
void Player_Weapon::Fire() {
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		ebomb_type = eBomb_Type::Fullrange;
		//TODO:今は1種なので適当に撃った瞬間に関数を代入してる
		Set_Shot_Pattern();
		bomb_type();
		living_bomb = true;
	}
}

// 状態に応じたショットを設定する
void Player_Weapon::Set_Shot_Pattern() {
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
		vector3d.y = center_position.y + radius * sin(radian);
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT)) {
		degree -= define_value.ROTATION_VALUE;
		radian = degree * DX_PI_F / 180;

		vector3d.x = center_position.x + radius * cos(radian);
		vector3d.y = center_position.y + radius * sin(radian);
	}
}

// ボムの弾が有効かどうかを判断する
void Player_Weapon::Check_Enable_Bullet() {
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

// 全方位に弾を飛ばすボム
void Player_Weapon::Fullrange_Shot(std::list<Bullet*> magazine) {
	// 20発飛ばす
	auto deglee = 360 / 20;

	for (int i = 0; i < 20; ++i) {
		bullet = player->magazine.back();
		bomb_bullets.push_back(bullet);
		player->magazine.pop_back();
	}

	for (auto bullet : bomb_bullets) {
		// 弧度法に変換
		auto radian = deglee * DX_PI_F / 180;
	
		bullet->Set_X(vector3d.x);
		bullet->Set_Y(vector3d.y);
		bullet->Set_Speed(15);
		bullet->Set_Radian(radian);
		bullet->actor_state = eActor_State::Action;	
		
		deglee += 360 / 20;
		
		clear_count = 30;
	}
}
