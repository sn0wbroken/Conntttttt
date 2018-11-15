#include "Player_Manager.h"

// 毎フレーム呼ばれる
void Player_Manager::Update() {
	for (auto&player_bullet : player->player_bullet) {
		player_bullet.Update();

		// ゲーム画面から出たら消す
		if (player_bullet.Is_Over_Min_Y()) {
			player->player_bullet.erase(player->player_bullet.begin());
		}
	}
}

Player_Manager::Player_Manager()
{
	player = std::make_shared<Player>();

	player_status = std::make_shared<Player_Status>();

	player_action = std::make_shared<Player_Action>(player, player_status);

	player_weapon = std::make_shared<Player_Weapon>();
}
