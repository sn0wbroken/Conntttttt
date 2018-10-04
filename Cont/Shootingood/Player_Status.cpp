#include"Player_Status.h"

#include"Game_Manager.h"

// コンストラクタ
Player_Status::Player_Status() {
	player = std::make_shared<Player>();

	speed = define_value.PLAYER_SPEED;
	attack = define_value.PLAYER_ATTACK;
	life = define_value.PLAYER_INITIALIZE_LIFE;
}

// デストラクタ
Player_Status::~Player_Status() {

}

// 死んだら呼ばれる。残機を1減らす
void Player_Status::Dead() {
	--life;
}

// 残機をリセットする
void Player_Status::Reset_Life() {
	life = define_value.PLAYER_INITIALIZE_LIFE;
}

// 残機を返す
int Player_Status::Get_Life() {
	return life;
}

// speedを返す
int Player_Status::Get_Speed() {
	return speed;
}
