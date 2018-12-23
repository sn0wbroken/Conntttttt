#include"Enemy_Manager.h"
#include<sstream>

// コンストラクタ
Enemy_Manager::Enemy_Manager() {
	//enemies = std::make_shared<std::vector<Enemy>>();
	enemy_controller = std::make_shared<Enemy_Controller>();
	//Enemy_Arrange();
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
		//配列の中で誰も死んでいなかった場合は、新しく追加する。
		if (i == (signed int)enemies.size() - 1)
		{
			enemies.push_back(std::make_shared<Enemy>(set_vector3d, set_degree));
			return;
		}
		//死んでいる敵がいれば再利用する。
		if (enemy->enemy_status->Is_Dead())
		{
			enemy->Set_Vector3D(set_vector3d);
			enemy->set_degree(set_degree);
			enemy->enemy_status->Initialize_HitPoint();
			return;
		}
		i++;
	}

	//そもそも配列の中が空の場合こちらで追加する。
	if (enemies.empty())
	{
		enemies.push_back(std::make_shared<Enemy>(set_vector3d, set_degree));
	}
}
//void Enemy_Manager::Enemy_Arrange(Vector3D set_vector3d, float set_degree) {
//	//TEST
//	position.x = set_vector3d.x;
//	position.y = set_vector3d.y;
//	position.z = set_vector3d.z;
//	enemies.push_back(std::make_shared<Enemy>(position, set_degree));
//}

// 敵が全滅しているかを返す。全滅でtrue
bool Enemy_Manager::Is_Enemy_All_Ded() {
	return false;
}
