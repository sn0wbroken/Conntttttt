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

	// エネミーの幅
	width = define_value.ENEMY_WIDTH;
	// エネミーの高さ
	height = define_value.ENEMY_HEIGHT;

	// ステータスをセット
	enemy_status = std::make_shared<Enemy_Status>(scene_manager->Get_Stage());

	// TODO:画像の用意がまだなので
	Create_Actor("Resources/Enemy/Enemy.x");
	MV1SetPosition(model_handle, VGet(vector3d.x, vector3d.y, vector3d.z));

	//TEST
	degree = set_degree;
	radian = degree * (DX_PI_F / 180);
	MV1SetRotationXYZ(model_handle, VGet(0, radian, 0)); // エネミーの表示角度を調整
	// 当たり判定に使用する矩形を生成
	Set_Rects();
}

// デストラクタ
Enemy::~Enemy() {}

// 当たり判定に使用する矩形を生成する
void Enemy::Set_Rects() {
	Rect rect;
	rects["front_face"] = rect.Make_3DBox(shared_from_this());

	モデルが来るだろうから作る
}

//TEST
void Enemy::RENDER() {
	DrawSphere3D(vector3d.GetVECTOR(), 2, 5, GetColor(255, 0, 255), GetColor(0, 0, 0), TRUE);
	
	//DrawTriangle3D(
	//	VGet(vector3d.x - (10 + cos(radian)), vector3d.y + (80 + sin(radian)), vector3d.z),
	//	VGet(vector3d.x - (10 + cos(radian)), vector3d.y                     , vector3d.z - (20 + sin(radian))),
	//	VGet(vector3d.x - (10 + cos(radian)), vector3d.y                     , vector3d.z + (20 + sin(radian))),
	//	GetColor(0, 0, 0), FALSE);

	//DrawTriangle3D(
	//	VGet(vector3d.x                     , vector3d.y + (80 + sin(radian)), vector3d.z),
	//	VGet(vector3d.x - (15 + cos(radian)), vector3d.y                     , vector3d.z - (10 + sin(radian))),
	//	VGet(vector3d.x + (15 + cos(radian)), vector3d.y                     , vector3d.z - (10 + sin(radian))),
	//	GetColor(0, 0, 0), FALSE);
}
