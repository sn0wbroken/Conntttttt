#include"Enemy_Manager.h"

// コンストラクタ
Enemy_Manager::Enemy_Manager() {
	enemy_controller = std::make_shared<Enemy_Controller>();
}

// 毎フレーム呼ばれる
void Enemy_Manager::Update() {
	//TODO::敵がいないことはあり得ないとは思うので要らないかもしれない
	if (enemies.empty())
	{
		return;
	}
	enemy_controller->Update();
}

// 敵を配置
void Enemy_Manager::Enemy_Arrange(Vector3D set_vector3d, Vector3D set_playerpos) {
	int i = 0; //itr
	for (auto enemy : enemies) {
		// 配列の中で誰も死んでいなかった場合は、新しく追加する。
		//if (i == (signed int)enemies.size() - 1)
		//{
		//	enemies.push_back(std::make_shared<Enemy>(set_vector3d, set_playerpos));
		//	break;
		//}
		// 死んでいる敵がいれば再利用する。
		if (enemy->enemy_status->Is_Dead()) {
			enemy->Set_Vector3D(set_vector3d);
			enemy->Set_Radian(set_playerpos);
			enemy->enemy_status->Initialize_HitPoint();
			break;
		}
		i++;
	}

	//そもそも配列の中が空の場合こちらで追加する。
	if (enemies.empty()) {
		enemies.push_back(std::make_shared<Enemy>(set_vector3d, set_playerpos));
	}
	//追加する　しないとモデルが描画されない
	std::unique_ptr<Actor>& actor = Actor::Get_Instance();
	actor->Add_Child("Enemy" + enemies.size(), enemies.back());
}


// 敵が全滅しているかを返す。全滅でtrue
bool Enemy_Manager::Is_Enemy_All_Ded() {
	return false;
}
