#include "Player_Manager.h"

// コンストラクタ
Player_Manager::Player_Manager() {
	player = std::make_shared<Player>();

	player_status = std::make_shared<Player_Status>();

	player_action = std::make_shared<Player_Action>(player, player_status);

	player_weapon = std::make_shared<Player_Weapon>(player); 
}
