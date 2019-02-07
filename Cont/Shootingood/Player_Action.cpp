#include"Player_Action.h"
#include"Player_Manager.h"

// コンストラクタ
Player_Action::Player_Action() {
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
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	auto player_move = player_manager->player_move;
	
	// 移動
	player_move->Rotation();
}

// 初期化
void Player_Action::Initialize() {

}
