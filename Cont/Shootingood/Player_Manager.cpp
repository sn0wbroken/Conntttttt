#include "Player_Manager.h"

// ���t���[���Ă΂��
void Player_Manager::Update() {
	for (auto&player_bullet : player->player_bullet) {
		player_bullet.Update();

		// �Q�[����ʂ���o�������
		if (player_bullet.Is_Over_Min_Y()) {
			player->player_bullet.erase(player->player_bullet.begin());
		}
	}
}
