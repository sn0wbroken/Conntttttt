#include"Enemy.h"
#include"Scene_Manager.h"

// コンストラクタ
Enemy::Enemy() {}

// コピーコンストラクタ
Enemy::Enemy(Vector3D position, Vector3D player_position) {
	// プレイするステージを取得
	std::unique_ptr<Scene_Manager>& scene_manager = Scene_Manager::Get_Instance();
	std::unique_ptr<Enemy_Manager>& enemy_manager = Enemy_Manager::Get_Instance();

	//座標を設定
	vector3d.Set_Vector(position.x, position.y, position.z);
	// 大きさを設定
	size.Set_Size(define_value.ENEMY_WIDTH, define_value.ENEMY_HEIGHT, define_value.ENEMY_DEPTH);
	// 角度をプレイヤーの方向に設定
	radian = Vector3D::AngleOfElevation(player_position, position);
	// ステータスをセット
	enemy_status = std::make_shared<Enemy_Status>(scene_manager->Get_Stage());

	// モデルを設定する
	if (enemy_manager->active_enemies.size() < 1) {
		//enemymanagerの配列に何も入っていなかった場合は作成する。
		Create_Actor("Resources/Enemy/Enemy.x");
	}
	else {
		//もう一度モデルを読み込むよりこちらの方が若干高速
		model_handle = MV1DuplicateModel(enemy_manager->active_enemies.front()->Get_Model_Handle());
	}

	MV1SetPosition(model_handle, vector3d);
	MV1SetScale(model_handle, VGet(0.6f, 0.6f, 0.6f));
	//radianに-を付けると普通に回転する。謎
	MV1SetRotationXYZ(model_handle, VGet(0, -radian, 0));
	//歩行モーションのハンドルを取得
	walk_animhandle = MV1AttachAnim(model_handle, 0);
	//アニメーションの初期フレームを修正
	Anim_CurrentFrame = 0;

	// 基準となる面(天井部)を生成
	rects["top_face"] = rect.Make_Top_Face(vector3d, size);
	// 当たり判定に使用する矩形を生成
	rects = rect.Make_3DBox(rects["top_face"], size, rects);
	// 当たり判定の中心の座標を設定する
	Set_Collision_Centor(rects);
	// 当たり判定用の箱をキャラクターの向きに合わせて回転させる
	rect.Rotation_Rectangle(rects, collision_centor, -radian);
}

// デストラクタ
Enemy::~Enemy() {}

// 当たり判定用の箱の中心座標を設定する
void Enemy::Set_Collision_Centor(std::unordered_map<std::string, Rect> set_rects) {
	auto z_coordinates = set_rects.find("front_face")->second.top_right.z - size.depth / 2;
	auto x_coordinates = set_rects.find("right_face")->second.top_right.x - size.width / 2;

	collision_centor = vector3d.Get_Vector(x_coordinates, 0, z_coordinates);
}

//// モデルのではなく、当たり判定用の箱の中心座標を返す
//Vector3D Enemy::Get_Collition_Center() {
//	return collision_centor;
//}

//ラジアンを設定
void Enemy::Set_Radian(Vector3D set_playerpos) {
	radian = Vector3D::AngleOfElevation(set_playerpos, vector3d);
	MV1SetRotationXYZ(model_handle, VGet(0, Vector3D::AngleOfElevation(set_playerpos, vector3d), 0));
	// 当たり判定用の箱をキャラクターの向きに合わせて回転させる
	rect.Rotation_Rectangle(rects, collision_centor, -radian);
}

// 角度を取得
float Enemy::Get_Degree() {
	return degree;
}
// ラジアンを取得
float Enemy::Get_Radian() {
	return radian;
}

void Enemy::Set_Vector3D(Vector3D t_vector)
{
	/*vector3d = t_vector;
	for (auto rect : rects)
	{
		rect.second.
	}*/
}

void Enemy::Animation_Controller()
{
	Add_WalkAnimIndex();
}

void Enemy::Add_WalkAnimIndex() {
	Anim_CurrentFrame++;
	if (Anim_CurrentFrame >= MV1GetAttachAnimTotalTime(model_handle, walk_animhandle)) {
		Anim_CurrentFrame = 0; //時間をリセットする。
	}
	//現在のアニメーションのタイムを設定する。
	MV1SetAttachAnimTime(model_handle, walk_animhandle, Anim_CurrentFrame);
}
