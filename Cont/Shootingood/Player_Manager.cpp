#include "Player_Manager.h"

#include"Actor.h"

// コンストラクタ
Player_Manager::Player_Manager() {
	player = std::make_shared<Player>();

	player_move = std::make_shared<Player_Move>();

	player_status = std::make_shared<Player_Status>();

	player_action = std::make_shared<Player_Action>();

	player_weapon = std::make_shared<Player_Weapon>(); 
}
