#include"Player_Status.h"

// コンストラクタ
Player_Status::Player_Status() {
	attack = define_value.PLAYER_ATTACK;
	life = define_value.PLAYER_INITIALIZE_LIFE;
}

// デストラクタ
Player_Status::~Player_Status() {
}

// 敵に当たったら呼ばれる。ライフを1減らす
void Player_Status::Damage() {
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

// 死んでいるかを返す
bool Player_Status::Get_Is_Dead() {
	return life < 0;
}
