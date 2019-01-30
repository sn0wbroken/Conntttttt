#include"Main_Scene.h"
#include"Enemy_Manager.h"
#include"Scene_Manager.h"

// コンストラクタ
Main_Scene::Main_Scene() {
	// ゲームを構成するオブジェクトを生成する
	Object_Creater::Get_Instance();

	// プレイヤーのマネージャクラス
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	player = player_manager->player;
	player_action = player_manager->player_action;
	player_status = player_manager->player_status;

	unique_ptr<Actor>& actor = Actor::Get_Instance();
	// 登場人物の初期化をすべて行う
	actor->Initialize();

	collision = std::make_shared<Collision>();

	Initialize();
	
	UI_class = std::make_shared<UI>();
	
	x1 = 0;
	x2 = -define_value.MIN_SCREEN_X;

	// メインに入った時はインターバルとする
	is_interval = true;



	//ground_handle = LoadGraph("Resources/BackGround/asphalt.png");//MV1LoadModel("Resources/BackGround/ground.x");
	//MV1SetPosition(ground_handle, VGet(0.0f,0.0f,0.0f));
	//MV1SetScale(ground_handle, VGet(10, 1, 10));
	// 背景モデル読み込み
	background_model = MV1LoadModel("Resources/BackGround/background.dome.x");
	MV1SetScale(background_model, VGet(10,10,10));
	//Xをカメラと同じ角度傾ける
	MV1SetRotationXYZ(background_model, VGet(45, 0, 0));

	SetUseLighting(false);

	// 背景モデルの座標を設定する
	Set_BackGround_Position();
}

// 初期化
void Main_Scene::Initialize() {
	// プレイヤーの初期化
	player->Initialize();
	player_action->Initialize();
	
	// アクターを構成するオブジェクトを生成する
	std::unique_ptr<Object_Creater>& object_creater = Object_Creater::Get_Instance();
	object_creater->Create_Enemy();
	object_creater->Play_Sound();
}

// 毎フレーム入る
void Main_Scene::Update() {
	std::unique_ptr<Key_Checker>& key_checker = Key_Checker::Get_Instance();
	std::unique_ptr<Scene_Manager> &scene_manager = Scene_Manager::Get_Instance();

	// エンターを押すまでゲームが進まない
	if (is_interval) {
		if (key_checker->key[KEY_INPUT_RETURN] == 1) {
			is_interval = false;
		}
		return;
	}

	player_action->Update();
	unique_ptr<Actor>& actor = Actor::Get_Instance();
	actor->Update();

	// エネミーのアップデート処理
	enemy_manager->Update();

	// エネミーの殲滅でクリア
	if (enemy_manager->Is_Enemy_All_Dead()) {
		// 最終ステージでなければ次のステージへ
		if (!(static_cast<int>(scene_manager->Get_Stage()) == define_value.FINAL_STAGE)) {
			scene_manager->Next_Stage();
			is_interval = true;
			Initialize();
			return;
		}
		// 最終ステージクリアでリザルト
		scene_manager->Reset_Stage();
		scene_manager->Change_Scene(Scene_Manager::Clear);
		return;
	}

	// プレイヤーが死んだらゲームオーバー
	if (player_status->Get_Is_Dead()) {
		player_status->Reset_Life();
		scene_manager->Reset_Stage();
		scene_manager->Change_Scene(Scene_Manager::Game_Over);
	}
}

// メインシーンに必要なものを描画
void Main_Scene::Render() {
	MV1SetWriteZBuffer(background_model, false);
	//背景のライティングを削るため力業　いい方法があれば変更してください。
	SetUseLighting(false);
	//MV1DrawModel(ground_handle);
	//DrawBillboard3D(VGet(0.0f,1.0f,0.0f), 0.0f, 0.0f, 10, 0.0f, ground_handle, false);
	MV1DrawModel(background_model);
	SetUseLighting(true);

	// UIの描画
	UI_class->Render();
	// オブジェクトの描画
	unique_ptr<Actor>& actor = Actor::Get_Instance();
	actor->Render();

	// インターバル中はアナウンスを表示
	if (is_interval) {
		DrawString(300, 200, "Ready?", GetColor(0, 0, 0));
		DrawString(285, 400, "Push Enter", GetColor(0, 0, 0));
		return;
	}
}

// プレイヤーが死亡したときの処理
void Main_Scene::Player_Dead() {
	is_interval = true;
	player->Initialize();
}

// 背景モデルの座標を設定する
void Main_Scene::Set_BackGround_Position() {
	VECTOR vector;
	vector.x = define_value.CAMERA_POSITION_X;
	vector.y = -50;
	vector.z = define_value.CAMERA_POSITION_Z;

	MV1SetPosition(background_model, vector);
}
