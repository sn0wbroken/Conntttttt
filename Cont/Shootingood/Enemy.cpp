#include"Enemy.h"
#include"Scene_Manager.h"
#include <sstream>
// コンストラクタ
Enemy::Enemy() {}

// コピーコンストラクタ
Enemy::Enemy(Vector3D position, Vector3D set_playerpos) {
	// プレイするステージを取得
	std::unique_ptr<Scene_Manager>& scene_manager = Scene_Manager::Get_Instance();

	//座標を設定
	vector3d.Set_Vector(position.x, position.y, position.z);
	OutputDebugString("AAA\n");
	// 大きさを設定
	size.Set_Size(define_value.ENEMY_WIDTH, define_value.ENEMY_HEIGHT, define_value.ENEMY_DEPTH);

	// ステータスをセット
	enemy_status = std::make_shared<Enemy_Status>(scene_manager->Get_Stage());

	//TEST
	//ラジアン計算
	radian = Vector3D::MoveOnAngleOfElevation(set_playerpos,position);
	degree = radian * 180 * 3.14f;

	// モデルを設定する
	Create_Actor("Resources/Enemy/Enemy.x");
	MV1SetPosition(model_handle, VGet(vector3d.x, vector3d.y, vector3d.z));
	MV1SetScale(model_handle, VGet(0.6f, 0.6f, 0.6f));
	MV1SetRotationXYZ(model_handle, VGet(0, Vector3D::RotateOnAngleOfElevation(set_playerpos, position), 0));

	// 基準となる面(天井部)を生成
	rects["top_face"] = rect.Make_Top_Face(vector3d, size);
	// 当たり判定に使用する矩形を生成
	Set_Rects();
}

// デストラクタ
Enemy::~Enemy() {}

// 当たり判定に使用する矩形を生成する
void Enemy::Set_Rects() {
	rects = rect.Make_3DBox(rects["top_face"], size, rects);
}

//TEST
void Enemy::RENDER() {
	//　あたり判定可視化(天井部のみ)
	DrawLine3D(rects["top_face"].top_right  , rects["top_face"].top_left    , GetColor(0, 0, 0));
	DrawLine3D(rects["top_face"].top_right  , rects["top_face"].bottom_right, GetColor(0, 0, 0));
	DrawLine3D(rects["top_face"].top_left   , rects["top_face"].bottom_left , GetColor(0, 0, 0));
	DrawLine3D(rects["top_face"].bottom_left, rects["top_face"].bottom_right, GetColor(0, 0, 0));
}
