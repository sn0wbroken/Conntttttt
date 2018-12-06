#include"Player_Weapon.h"
#include"Player_Manager.h"
#include"Bullet.h"

// コンストラクタ
Player_Weapon::Player_Weapon() : degree(90) {

}

// デストラクタ
Player_Weapon::~Player_Weapon() {	}

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

	for (auto bullet : player->magazine) {
		bullet->Update();
	}

	// 子にも回す
	Actor::Update();
}

// 描画
void Player_Weapon::Render() {
	for (auto bullet : player->magazine) {
		bullet->Render();
	}
}

// 弾を生成(発射)
void Player_Weapon::Fire() {
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		ebom_type = eBom_Type::Fullrange;
		Set_Shot_Pattern();
		bom_type();
	}
}

// 状態に応じたショットを設定する
void Player_Weapon::Set_Shot_Pattern() {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	player = player_manager->player;

	bom_type = [&]() {
		switch (ebom_type) {
			case eBom_Type::Fullrange:
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

// 全方位に弾を飛ばすボム
void Player_Weapon::Fullrange_Shot(std::list<Bullet*> magazine) {
	// 20発飛ばす
	auto deglee = 360 / 20;

	for (auto bullet : magazine) {
		// 弧度法に変換
		auto radian = deglee * DX_PI_F / 180;
	
		bullet->Set_X(vector3d.x);
		bullet->Set_Y(vector3d.y);
		bullet->Set_Speed(15);
		bullet->Set_Radian(radian);
		bullet->actor_state = eActor_State::Action;
	
		deglee += 360 / 20;
	}
}
