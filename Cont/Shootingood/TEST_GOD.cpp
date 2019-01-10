#include "TEST_GOD.h"

TEST_GOD::TEST_GOD() {
	unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	unique_ptr<Actor>& actor = Actor::Get_Instance();

	character = make_shared<Character>();
	actor->Add_Child("Character", character);

	actor->Add_Child("Player", player_manager->player);
	
	weapon = make_shared<Weapon>();
	actor->Add_Child("Weapon" ,weapon);
	weapon->Add_Child("Player_Weapon" , player_manager->player_weapon);

	collision = make_shared<Collision>();
	actor->Add_Child("Collision" , collision);

	//TEST
	unique_ptr<Enemy_Manager>& enemy_manager  = Enemy_Manager::Get_Instance();
	
	Vector3D vec;
	vec.x = 50.0f; vec.y = 0.0f; vec.z = 50.0f;
	enemy_manager->Enemy_Arrange(vec, player_manager->player->vector3d);
	actor->Add_Child("Enemy_1" , enemy_manager->enemies.front());
	
	vec.x = -200.0f; vec.y = 0.0f; vec.z = 200.0f;
	enemy_manager->Enemy_Arrange(vec, player_manager->player->vector3d);
	actor->Add_Child("Enemy_2" , enemy_manager->enemies.back());

	vec.x = -200.0f; vec.y = 0.0f; vec.z = 200.0f;
	enemy_manager->Enemy_Arrange(vec, player_manager->player->vector3d);
	actor->Add_Child("Enemy_3", enemy_manager->enemies.back());
}

TEST_GOD::~TEST_GOD()
{
}
