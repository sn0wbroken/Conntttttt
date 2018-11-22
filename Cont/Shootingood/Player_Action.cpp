#include"Player_Action.h"

// コンストラクタ
Player_Action::Player_Action(std::shared_ptr<Player> set_player,
	std::shared_ptr<Player_Status> set_player_statsu) {
	player = set_player;
	player_status = set_player_statsu;

	player_move = std::make_shared<Player_Move>(player, player_status);
}

// デストラクタ
Player_Action::~Player_Action() {
}

// 毎フレーム呼ばれる
void Player_Action::Update() {
	// プレイヤーの操作を受け付ける 毎フレーム呼び出し
	Player_Controll();
}

// プレイヤーの操作を受け付ける 毎フレーム呼び出し
void Player_Action::Player_Controll() {
	// 移動
	player_move->Rotation();
}

// 初期化
void Player_Action::Initialize() {

}
