#include "TEST_GOD.h"

TEST_GOD::TEST_GOD() {
	unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	unique_ptr<Enemy_Manager>& enemy_manager  = Enemy_Manager::Get_Instance();

	actor = make_shared<Actor>();

	character = make_shared<Character>();
	actor->Add_Child(character);

	actor->Add_Child(player_manager->player);

	weapon = make_shared<Weapon>();
	actor->Add_Child(weapon);
	weapon->Add_Child(player_manager->player_weapon);

//	enemy_controller = make_shared<Enemy_Controller>();
//	actor->Add_Child(enemy_controller);
}

TEST_GOD::~TEST_GOD()
{
}
