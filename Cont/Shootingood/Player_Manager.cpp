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
