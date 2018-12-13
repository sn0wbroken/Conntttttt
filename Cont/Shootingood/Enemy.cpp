#include"Enemy.h"
#include"Scene_Manager.h"

// コンストラクタ
Enemy::Enemy() {}

// コピーコンストラクタ
Enemy::Enemy(float set_x, float set_y) {
	// プレイするステージを取得
	std::unique_ptr<Scene_Manager>& scene_manager = Scene_Manager::Get_Instance();

	// 配置
	vector3d.Arrange(set_x, set_y, 0);

	// エネミーの幅
	width = define_value.ENEMY_WIDTH;
	// エネミーの高さ
	height = define_value.ENEMY_HEIGHT;

	// ステータスをセット
	enemy_status = std::make_shared<Enemy_Status>(scene_manager->Get_Stage());

	// TODO:画像の用意がまだなので
	Create_Actor("Resources/Player/Bullet.x");
	MV1SetPosition(model_handle, VGet(vector3d.x, vector3d.y, vector3d.z));
	// エネミーの大きさを指定
	MV1SetScale(model_handle, VGet(40.0f, 40.0f, 35.0f));
	// エネミーの表示角度を調整
	//MV1SetRotationXYZ(model_handle, VGet(270 * (DX_PI_F / 180), 0.0f, 180 * (DX_PI_F / 180)));
}

// デストラクタ
Enemy::~Enemy() {}