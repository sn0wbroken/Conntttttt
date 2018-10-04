#include "Enemy_Manager.h"

#include<iterator>

// コンストラクタ
Enemy_Manager::Enemy_Manager() {}

// 初期化
void Enemy_Manager::Initialize() {
	enemy_bullet.clear();

	// 配列の初期化
	enemies.clear();
	// 配置
	Enemy_Arrange();
}

// 毎フレーム呼ばれる
void Enemy_Manager::Update() {
	// ダメージ受けていたらダメージ判定を元に戻す
	for (auto& enemy : enemies) {
		auto& enemy_status_ = enemy.enemy_status;
		if (enemy_status_->Is_Damage()) {
			enemy_status_->Initialize_Is_Damage();
		}
	}
	
	enemy_AI->Update();

	// 撃った弾だけ更新
	for(auto& enemy_bullet_ : enemy_bullet){
		enemy_bullet_.Update();
	}
}

// 描画
void Enemy_Manager::Render() {
	for (auto& enemy : enemies) {
		enemy.Render();
	}

	// 撃った弾だけ描画
	for (int i = 0; i < enemies.size(); ++i) {
		for (auto& enemy_bullet_ : enemy_bullet) {
			enemy_bullet_.Render();
		}
	}
}

// 敵を配置
void Enemy_Manager::Enemy_Arrange() {
	for (int i = 0; i < define_value.ENEMY_NUMBER; ++i) {
		Arrange(((i % define_value.ENEMY_NUMBER) * define_value.ENEMY_WIDTH), ((define_value.ENEMY_HEIGHT / 2) + ((i % define_value.ENEMY_NUMBER) * define_value.ENEMY_HEIGHT)));
		enemies.emplace_back(Enemy(x, y));
	}

	std::reverse(enemies.begin(), enemies.end());
}

// エネミーを元の位置に配置しなおす
void Enemy_Manager::Reset_Enemy() {
	for (auto& enemy : enemies) {
		enemy.Set_X(enemy.Get_Initialize_Position_X());
		enemy.Set_Y(enemy.Get_Initialize_Position_Y());
		enemy_bullet.clear();
	}
}

// 出現する敵を配置
void Enemy_Manager::Arrange(int set_x, int set_y) {
	x = set_x;
	y = set_y;
}
