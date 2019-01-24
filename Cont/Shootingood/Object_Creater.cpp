#include"Object_Creater.h"
#include "Random_Number_Generator.h"

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
}

Object_Creater::~Object_Creater() {
}

void Object_Creater::Create_Enemy() {
	Utility::Number_Generator NGen;
	unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	Vector3D playerpos = player_manager->player->vector3d;
	//TEST
	unique_ptr<Actor>& actor = Actor::Get_Instance();
	unique_ptr<Enemy_Manager>& enemy_manager = Enemy_Manager::Get_Instance();
	// �v���C����X�e�[�W���擾 �X�e�[�W�ɂ������G�̐��쐬����B
	std::unique_ptr<Scene_Manager>& scene_manager = Scene_Manager::Get_Instance();
	//�G��������
	Vector3D vec;
	//�G�𐶐�����͈�
	auto EnemySppawnArea = [&]() {
		if (NGen.Generate_Number(0, 1) == 0)
		{
			return -NGen.Generate_Number(500.0f, 900.0f);
		}
		else
		{
			return NGen.Generate_Number(500.0f, 900.0f);
		}
	};
	//�G�̐�����
	int SpawnEnemyNum = 0;
	//�X�e�[�W�ɂ���ēG�̐�����ς��� WARNING MAGICNUMBER
	switch (scene_manager->Get_Stage())
	{
	case eStage::stage1:SpawnEnemyNum = 25; break;
	case eStage::stage2:SpawnEnemyNum = 40; break;
	case eStage::stage3:SpawnEnemyNum = 50; break;
	default:SpawnEnemyNum = 50; break;
	}
	enemy_manager->active_enemies.clear();
	enemy_manager->inactive_enemies.clear();
	//�A�N�e�B�u�ȓG�����Ȃ����m�F
	if (!enemy_manager->active_enemies.empty())
	{
		for (auto enemy : enemy_manager->active_enemies)
		{
			vec.x = EnemySppawnArea(); vec.y = 0.0f; vec.z = EnemySppawnArea();
			enemy->vector3d = vec;
			enemy->Set_Radian(playerpos);
		}
	}
	//�G����
	for (int i = 0; i < SpawnEnemyNum; i++) {
		if (enemy_manager->inactive_enemies.empty()) {
			vec.x = EnemySppawnArea(); vec.y = 0.0f; vec.z = EnemySppawnArea();
			enemy_manager->active_enemies.push_back(std::make_shared<Enemy>(vec, playerpos));
			actor->Add_Child("Enemy" + i, enemy_manager->active_enemies.back());
		}
		else
		{
			auto enemy = enemy_manager->inactive_enemies.front();
			enemy->enemy_status->Initialize_IsDead();
			vec.x = EnemySppawnArea(); vec.y = 0.0f; vec.z = EnemySppawnArea();
			enemy->vector3d = vec;
			enemy->Set_Radian(playerpos);
			enemy_manager->active_enemies.push_back(enemy);
			enemy_manager->inactive_enemies.remove(enemy);
		}
	}

}