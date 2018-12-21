#include"Enemy.h"
#include"Scene_Manager.h"

// コンストラクタ
Enemy::Enemy() {}

// コピーコンストラクタ
Enemy::Enemy(Vector3D position, float set_degree) {
	// プレイするステージを取得
	std::unique_ptr<Scene_Manager>& scene_manager = Scene_Manager::Get_Instance();

	//座標を設定
	vector3d.Set_Vector(position.x, position.y, position.z);

	// 大きさを設定
	size.Set_Size(define_value.ENEMY_WIDTH, define_value.ENEMY_HEIGHT, define_value.ENEMY_DEPTH);

	// ステータスをセット
	enemy_status = std::make_shared<Enemy_Status>(scene_manager->Get_Stage());

	//TEST
	degree = set_degree;
	radian = degree * DX_PI_F / 180;

	// モデルを設定する
	Create_Actor("Resources/Enemy/Enemy.x");
	MV1SetPosition(model_handle, VGet(vector3d.x, vector3d.y, vector3d.z));
	MV1SetScale(model_handle, VGet(0.6f, 0.6f, 0.6f));
	MV1SetRotationXYZ(model_handle, VGet(0, radian, 0));

	// 基準となる面を生成。被せる箱の天井にあたるもの
	rect = rect.Make_Rectangle(vector3d, size); ///TODO:top_faceに入れちゃえばいいのでは？///
	// 当たり判定に使用する矩形を生成
	Set_Rects();
}

// デストラクタ
Enemy::~Enemy() {}

// 当たり判定に使用する矩形を生成する
void Enemy::Set_Rects() {
	rects = rect.Make_3DBox(rect, size, rects);
}

//TEST
void Enemy::RENDER() {
	//　あたり判定可視化(天井部のみ)
	DrawLine3D(rect.top_right  , rect.top_left    , GetColor(0, 0, 0));
	DrawLine3D(rect.top_right  , rect.bottom_right, GetColor(0, 0, 0));
	DrawLine3D(rect.top_left   , rect.bottom_left , GetColor(0, 0, 0));
	DrawLine3D(rect.bottom_left, rect.bottom_right, GetColor(0, 0, 0));
}
