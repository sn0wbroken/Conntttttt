#include"Enemy_Manager.h"
#include<sstream>

// コンストラクタ
Enemy_Manager::Enemy_Manager() {
	//enemies = std::make_shared<std::vector<Enemy>>();
	enemy_controller = std::make_shared<Enemy_Controller>();
	Enemy_Arrange(Vector3D(0, 0, 0), 1.0f); //TODO::MagicNumber
}

// 毎フレーム呼ばれる
void Enemy_Manager::Update() {
	//TODO::敵がいないことはあり得ないとは思うので要らないかもしれない
	if (enemies.empty())
	{
		return;
	}
	for (auto enemy : enemies)
	{
		//int handle = enemy->Get_Right_Edge;
	}
	OutputDebugString("called");
	enemy_controller->Update();
}

// 敵を配置
void Enemy_Manager::Enemy_Arrange(Vector3D set_vector3d, float set_degree) {
	int i = 0; //itr
	for (auto enemy : enemies)
	{
		if (i == (signed int)enemies.size() - 1)
		{
			enemies.emplace_back(std::make_shared<Enemy>(set_vector3d, set_degree));
			break;
		}
		//使っていない敵がいれば再利用する。
		if (enemy->enemy_status->Is_Dead())
		{
			enemy->Set_Vector3D(set_vector3d);
			enemy->set_degree(set_degree);
			enemy->enemy_status->Initialize_HitPoint();
		}
		i++;
	}

	if (i == 0)
	{
		enemies.emplace_back(std::make_shared<Enemy>(set_vector3d, set_degree));
	}
}

// 敵が全滅しているかを返す。全滅でtrue
bool Enemy_Manager::Is_Enemy_All_Ded() {
	return false;
}
