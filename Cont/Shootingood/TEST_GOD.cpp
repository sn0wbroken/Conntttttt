#include "TEST_GOD.h"

TEST_GOD::TEST_GOD() {
	unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	unique_ptr<Actor>& actor = Actor::Get_Instance();

	character = make_shared<Character>();
	actor->Add_Child("Character", character);

	actor->Add_Child("Player", player_manager->player);

	weapon = make_shared<Weapon>();
	actor->Add_Child("Weapon", weapon);
	weapon->Add_Child("Player_Weapon", player_manager->player_weapon);

	collision = make_shared<Collision>();
	actor->Add_Child("Collision", collision);

	////TEST
	//unique_ptr<Enemy_Manager>& enemy_manager  = Enemy_Manager::Get_Instance();
	//
	//Vector3D vec;
	//vec.x = 50.0f; vec.y = 0.0f; vec.z = 50.0f;
	//enemy_manager->Enemy_Arrange(vec, player_manager->player->vector3d);
	//actor->Add_Child("Enemy_1" , enemy_manager->enemies.front());
	//
	//vec.x = -200.0f; vec.y = 0.0f; vec.z = 200.0f;
	//enemy_manager->Enemy_Arrange(vec, player_manager->player->vector3d);
	//actor->Add_Child("Enemy_2" , enemy_manager->enemies.back());

	//vec.x = -200.0f; vec.y = 0.0f; vec.z = 200.0f;
	//enemy_manager->Enemy_Arrange(vec, player_manager->player->vector3d);
	//actor->Add_Child("Enemy_3", enemy_manager->enemies.back());
}

TEST_GOD::~TEST_GOD() {
}

void TEST_GOD::Create_Enemy() {
	unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	Vector3D playerpos = player_manager->player->vector3d;
	//TEST
	unique_ptr<Actor>& actor = Actor::Get_Instance();
	unique_ptr<Enemy_Manager>& enemy_manager = Enemy_Manager::Get_Instance();
	// プレイするステージを取得 ステージにあった敵の数作成する。
	//std::unique_ptr<Scene_Manager>& scene_manager = Scene_Manager::Get_Instance();
	//敵生成部分
	Vector3D vec;

	for (int i = 0; i < 50; i++) {
		vec.x = -1000.0f + i * 30.0f; vec.y = 0.0f; vec.z = 1000.0f - i * 30.0f;
		enemy_manager->active_enemies.push_back(std::make_shared<Enemy>(vec, playerpos));
		actor->Add_Child("Enemy" + i, enemy_manager->active_enemies.back());
	}
	/*switch (scene_manager->Get_Stage()) {
	case eStage::stage1: {
		if (!enemy_manager->inactive_enemies.empty())
		{
			for (auto itr = enemy_manager->inactive_enemies.begin(); itr != enemy_manager->inactive_enemies.end();)
			{
				if ((*itr)->enemy_status->Is_Dead())
				{
					(*itr)->enemy_status->Initialize_HitPoint();
					(*itr)->actor_state = eActor_State::Action;
					enemy_manager->active_enemies.push_back((*itr));
					itr = enemy_manager->inactive_enemies.erase(itr);
				}
				else
				{
					itr++;
				}
			}
		}

		for (int i = 0; i < 50; i++) {
			vec.x = -1000 + i * 30; vec.y = 0.0f; vec.z = 1000 - i * 30;
			enemy_manager->active_enemies.push_back(std::make_shared<Enemy>(vec, playerpos));
			actor->Add_Child("Enemy" + i, enemy_manager->active_enemies.back());
			break;
		}
	case eStage::stage2: {
		for (int i = 0; i < 50; i++) {
			vec.x = -1000 + i * 30; vec.y = 0.0f; vec.z = 1000 - i * 30;
			enemy_manager->active_enemies.push_back(std::make_shared<Enemy>(vec, playerpos));
			actor->Add_Child("Enemy" + i, enemy_manager->active_enemies.back());
			break;
		}
	case eStage::stage3: {
		for (int i = 0; i < 50; i++) {
			vec.x = -1000 + i * 30; vec.y = 0.0f; vec.z = 1000 - i * 30;
			enemy_manager->active_enemies.push_back(std::make_shared<Enemy>(vec, playerpos));
			actor->Add_Child("Enemy" + i, enemy_manager->active_enemies.back());
			break;
		}
	}
	}
	}
	}*/
}