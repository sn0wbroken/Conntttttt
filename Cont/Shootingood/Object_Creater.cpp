#include"Object_Creater.h"
#include "Random_Number_Generator.h"
#include<sstream>

Object_Creater::Object_Creater() {
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

	c_pshandle = 0;
	itr = 0;
}

Object_Creater::~Object_Creater() {
}

void Object_Creater::Create_Enemy() {
	Utility::Number_Generator NGen;
	unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	Vector3D playerpos = player_manager->player->vector3d;
	unique_ptr<Actor>& actor = Actor::Get_Instance();
	unique_ptr<Enemy_Manager>& enemy_manager = Enemy_Manager::Get_Instance();
	// プレイするステージを取得 ステージにあった敵の数作成する。
	std::unique_ptr<Scene_Manager>& scene_manager = Scene_Manager::Get_Instance();
	//敵生成部分
	Vector3D vec;
	//敵を生成する範囲
	auto EnemySppawnArea = [&]() {
		if (NGen.Generate_Number(0, 1) == 0) {
			return -NGen.Generate_Number(500.0f, 900.0f);
		}
		else {
			return NGen.Generate_Number(500.0f, 900.0f);
		}
	};
	//敵の生成数
	int SpawnEnemyNum;
	//ステージによって敵の生成を変える WARNING MAGICNUMBER
	switch (scene_manager->Get_Stage()) {
		case eStage::stage1:
			SpawnEnemyNum = 5;
			break;
		case eStage::stage2:
			SpawnEnemyNum = 10;
			break;
		case eStage::stage3:
			SpawnEnemyNum = 15;
			break;
		default:
			SpawnEnemyNum = 0;
	}
	enemy_manager->active_enemies.clear();
	enemy_manager->inactive_enemies.clear();
	//敵生成
	for (int i = 0; i < SpawnEnemyNum; i++) {
			vec.x = EnemySppawnArea(); vec.y = 0.0f; vec.z = EnemySppawnArea();
			while (vec.x < 0 && vec.z > 0)
			{
				vec.x = EnemySppawnArea(); vec.y = 0.0f; vec.z = EnemySppawnArea();
			}
			enemy_manager->active_enemies.push_back(std::make_shared<Enemy>(vec, playerpos));
			std::stringstream oss;
			oss << "Enemy" << itr;
			actor->Add_Child(oss.str(), enemy_manager->active_enemies.back());
			itr++;
	}
}

void Object_Creater::Play_Sound()
{
	std::unique_ptr<Scene_Manager>& scene_manager = Scene_Manager::Get_Instance();
	if (c_pshandle != 0)
	{
		StopSoundMem(c_pshandle);
	}
	//ステージによって流す曲を変える
	switch (scene_manager->Get_Stage()) {
	case eStage::stage1:
		c_pshandle = sounddata.m_sounds[11].SHandle;
		PlaySoundMem(c_pshandle,DX_PLAYTYPE_LOOP);
		break;
	case eStage::stage2:
		c_pshandle = sounddata.m_sounds[12].SHandle;
		PlaySoundMem(c_pshandle, DX_PLAYTYPE_LOOP);
		break;
	case eStage::stage3:
		c_pshandle = sounddata.m_sounds[13].SHandle;
		PlaySoundMem(c_pshandle,DX_PLAYTYPE_LOOP);
		break;
	default:
		c_pshandle = sounddata.m_sounds[14].SHandle;
		PlaySoundMem(c_pshandle, DX_PLAYTYPE_LOOP);
	}
}
