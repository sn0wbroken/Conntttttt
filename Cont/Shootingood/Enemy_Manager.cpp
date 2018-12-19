#include"Enemy_Manager.h"
#include<sstream>

// コンストラクタ
Enemy_Manager::Enemy_Manager() {
	m_enemy = std::make_shared<std::vector<Enemy>>();
	enemy_controller = std::make_shared<Enemy_Controller>();
	Enemy_Arrange();
}

// 毎フレーム呼ばれる
void Enemy_Manager::Update() {
	//TODO::敵がいないことはあり得ないとは思うので要らないかもしれない
	if (m_enemy->empty())
	{
		return;
	}
	for (auto enemy = m_enemy->begin();enemy != m_enemy->end();enemy++)
	{
		int handle = enemy->Get_Model_Handle();
		std::stringstream oss;
		oss << handle << std::endl;
		OutputDebugString(oss.str().c_str());
	}
	OutputDebugString("called");
	enemy_controller->Update();
}

// 敵を配置
void Enemy_Manager::Enemy_Arrange() {
	for (auto enemyitr = m_enemy->begin();; enemyitr++)
	{
		if(enemyitr == m_enemy->end())
		{
			//TODO::まだ値を決めていないため、0を挿入する
			m_enemy->emplace_back(Vector3D(-60.0f,0.0f,0.0f));
			break;
		}
		//使っていない敵がいれば再利用する。
		if (enemyitr->enemy_status->Is_Dead())
		{
			//TODO::まだ値を決めていないため、空　後ほど変更
			enemyitr->Set_Vector3D(Vector3D(0.0f,0.0f,0.0f));
			enemyitr->enemy_status->Initialize_HitPoint();
		}
	}
}

// 敵が全滅しているかを返す。全滅でtrue
bool Enemy_Manager::Is_Enemy_All_Ded() {
	return false;
}
