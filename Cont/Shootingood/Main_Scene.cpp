#include"Main_Scene.h"
#include"Enemy_Manager.h"
#include"Scene_Manager.h"

// コンストラクタ
Main_Scene::Main_Scene() {
	// ゲームを構成するオブジェクトを生成する
	std::unique_ptr<Object_Creater>& object_creater = Object_Creater::Get_Instance();

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
}

// 初期化
void Main_Scene::Initialize() {
	// プレイヤーの初期化
	player->Initialize();
	player_action->Initialize();

	// アクターを構成するオブジェクトを生成する
	std::unique_ptr<Object_Creater>& object_creater = Object_Creater::Get_Instance();
	object_creater->Create_Enemy();
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
			player->Set_Power_Up(true);
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
	// UIの描画
	UI_class->Render();
	// オブジェクトの描画
	unique_ptr<Actor>& actor = Actor::Get_Instance();
	actor->Render();
	
	// インターバル中は背景のスクロール無し
	if (is_interval) {
		// アナウンスを表示
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
