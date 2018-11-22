#include"Enemy.h"
#include"Scene_Manager.h"

// コンストラクタ
Enemy::Enemy() {}

// コピーコンストラクタ
Enemy::Enemy(float set_x, float set_y) {
	// プレイするステージを取得
	std::unique_ptr<Scene_Manager>& scene_manager = Scene_Manager::Get_Instance();

	// 配置
	vector3.Arrange(set_x, set_y, 0);

	initialize_position_x = set_x;
	initialize_position_y = set_y;

	// エネミーの幅
	width = define_value.ENEMY_WIDTH;
	// エネミーの高さ
	height = define_value.ENEMY_HEIGHT;

	// ステータスをセット
	enemy_status = std::make_shared<Enemy_Status>(scene_manager->Get_Stage());

	// TODO:画像の用意がまだなので
	Create_Actor("Resources/Enemy/Enemy.x");
	// エネミーの大きさを指定
	MV1SetScale(model_handle, VGet(40.0f, 40.0f, 35.0f));
	// エネミーの表示角度を調整
	//MV1SetRotationXYZ(model_handle, VGet(270 * (DX_PI_F / 180), 0.0f, 180 * (DX_PI_F / 180)));
}

// デストラクタ
Enemy::~Enemy() {}

// エネミーの右端の座標を返す
float Enemy::Get_Right_Edge() {
	return vector3.x + width;
}

// エネミーの左端の座標を返す
float Enemy::Get_Left_Edge() {
	return vector3.x;
}

// エネミーの上端の座標を返す
float Enemy::Get_Top_Edge() {
	return vector3.y;
}

// エネミーの下端の座標を返す
float Enemy::Get_Bottom_Edge() {
	return vector3.y + height;
}

// 弾の発射する位置を返す
float Enemy::Get_Shot_Point() {
	return vector3.x + (width / 2);
}

// 初期x座標を返す
float Enemy::Get_Initialize_Position_X() {
	return initialize_position_x;
}

// 初期y座標を返す
float Enemy::Get_Initialize_Position_Y() {
	return initialize_position_y;
}