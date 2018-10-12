#include "Enemy.h"
#include"Game_Manager.h"

// コンストラクタ
Enemy::Enemy() {}

// コピーコンストラクタ
Enemy::Enemy(float set_x, float set_y) {
	vector3 = new Vector3D;

	// プレイするステージを取得
	std::unique_ptr<Game_Manager>& game_manager = Game_Manager::Get_Instance();

	// 配置
	vector3->Arrange(set_x, set_y, 0);

	initialize_position_x = set_x;
	initialize_position_y = set_y;

	// エネミーの幅
	width = define_value.ENEMY_WIDTH;
	// エネミーの高さ
	height = define_value.ENEMY_HEIGHT;

	// ステータスをセット
	enemy_status = std::make_shared<Enemy_Status>(game_manager->Get_Stage());

	// エネミーの画像をロード
	enemy_graph = LoadGraph("Picture/Enemy/Evil_Enemy.png");
	damage_enemy_graph = LoadGraph("Picture/Enemy/Damage_Evil_Enemy.png");
}

// デストラクタ
Enemy::~Enemy() {}

// 描画
void Enemy::Render() {	
	// 自分を描画
	if (!enemy_status->Is_Damage()) {
		DrawExtendGraph(vector3->x, vector3->y, vector3->x + width, 
						vector3->y + height, enemy_graph, FALSE);
		return;
	}
	if (enemy_status->Is_Damage()) {
		DrawExtendGraph(vector3->x, vector3->y, vector3->x + width, 
						vector3->y + height, damage_enemy_graph, FALSE);
	}
}

// エネミーの右端の座標を返す
int Enemy::Get_Right_Edge() {
	return vector3->x + width;
}

// エネミーの左端の座標を返す
int Enemy::Get_Left_Edge() {
	return vector3->x;
}

// エネミーの上端の座標を返す
int Enemy::Get_Top_Edge() {
	return vector3->y;
}

// エネミーの下端の座標を返す
int Enemy::Get_Bottom_Edge() {
	return vector3->y + height;
}

// 弾の発射する位置を返す
int Enemy::Get_Shot_Point() {
	return vector3->x + (width / 2);
}

// 初期x座標を返す
int Enemy::Get_Initialize_Position_X() {
	return initialize_position_x;
}

// 初期y座標を返す
int Enemy::Get_Initialize_Position_Y() {
	return initialize_position_y;
}
