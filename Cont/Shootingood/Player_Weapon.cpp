#include"Player_Weapon.h"
#include"Player_Manager.h"

// コンストラクタ
Player_Weapon::Player_Weapon() {

}

// デストラクタ
Player_Weapon::~Player_Weapon() {}

// 更新処理
void Player_Weapon::Update() {
	// 攻撃
	Fire();

	// 子にも回す
	Actor::Update();
}

// 初期化関数
void Player_Weapon::Initialize() {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	player = player_manager->player;
	// 座標を設定
	vector3.Arrange(player->Get_X(), player->Get_Y() + player->Get_Height() / 2, player->Get_Z());
}

// 弾を発射
void Player_Weapon::Fire() {
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(300.0f, 300.0f, 0.0f, 0.0f, 15.0f, 0.0f);
		Actor::Add_Child(bullet);
	}
}

// 状態に応じたショットを設定する
void Player_Weapon::Set_Shot_Pattern() {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	player = player_manager->player;

	bom_type = [&]() {
		switch (ebom_type) {
		default: break;
		}
	};
}

// 攻撃の種類を切り替える。毎フレーム受付ける
void Player_Weapon::Change_Fire_Type() {
	if (key_checker->key[KEY_INPUT_A] == 1) {
		ebom_type = eBom_Type::Hoge;
		// 直線攻撃のものに
		Set_Shot_Pattern();
	}

	// 打ち出すx軸の位置を変える
	counter += 2;
	radian = static_cast<float>(counter * DX_PI_F / 180.0f);
	position_x = std::sin(radian) * amplitude;
	if (key_checker->key[KEY_INPUT_S] == 1) {
		ebom_type = eBom_Type::Fuga;
		bom_type = [&]() {
			// 波状攻撃のものに
			Set_Shot_Pattern();
		};
	}
}
