#include "TEST_GOD.h"
#include <sstream>
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

	Create_Enemy(player_manager->player->vector3d);

	//TEST
<<<<<<< Updated upstream
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
=======
	//unique_ptr<Enemy_Manager>& enemy_manager = Enemy_Manager::Get_Instance();

	//Vector3D vec;
	//vec.x = 200.0f; vec.y = 0.0f; vec.z = -200.0f;
	//enemy_manager->Enemy_Arrange(vec, player_manager->player->vector3d);
	//enemy_manager->enemies.push_back(std::make_shared<Enemy>(vec, player_manager->player->vector3d));
	//actor->Add_Child("Enemy_1", enemy_manager->enemies.front());

	//vec.x = -200.0f; vec.y = 0.0f; vec.z = -200.0f;
	//enemy_manager->Enemy_Arrange(vec, player_manager->player->vector3d);
	//actor->Add_Child("Enemy_2", enemy_manager->enemies.back());

	//vec.x = -200.0f; vec.y = 0.0f; vec.z = 200.0f;
	//enemy_manager->Enemy_Arrange(vec, player_manager->player->vector3d);
	//actor->Add_Child("Enemy_3", enemy_manager->enemies.back());

	//	vec.x = 0.0f; vec.y = 0.0f; vec.z = -100.0f;
	//	enemy_manager->Enemy_Arrange(vec, 135);
	//	actor->Add_Child("Enemy_4" ,enemy_manager->enemies.back());
>>>>>>> Stashed changes
}

TEST_GOD::~TEST_GOD()
{
}

void TEST_GOD::Create_Enemy(Vector3D playerpos)
{
	//TEST
	unique_ptr<Actor>& actor = Actor::Get_Instance();
	unique_ptr<Enemy_Manager>& enemy_manager = Enemy_Manager::Get_Instance();
	// プレイするステージを取得
	/*std::unique_ptr<Scene_Manager>& scene_manager = Scene_Manager::Get_Instance();
	scene_manager->Get_Stage();*/
	Vector3D vec;
	vec.x = -200.0f; vec.y = 0.0f; vec.z = 0.0f;
	enemy_manager->enemies.push_back(std::make_shared<Enemy>(vec, playerpos));
	actor->Add_Child("Enemy_1", enemy_manager->enemies.back());
	vec.x = 200.0f; vec.y = 0.0f; vec.z = 0.0f;
	enemy_manager->enemies.push_back(std::make_shared<Enemy>(vec, playerpos));
	actor->Add_Child("Enemy_2", enemy_manager->enemies.back());
	for (int i = 0; i < 50; i++) {
		vec.x = 0; vec.y = 0.0f; vec.z = -1000;
		enemy_manager->enemies.push_back(std::make_shared<Enemy>(vec, playerpos));
		actor->Add_Child("Enemy" + i, enemy_manager->enemies.back());
	}
}
