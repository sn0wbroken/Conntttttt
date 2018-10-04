#include"Main_Scene.h"
#include"Game_Manager.h"

// コンストラクタ
Main_Scene::Main_Scene() {
	UI_class = std::make_shared<UI>();

	player = player_manager->player;
	player_action = player_manager->player_action;

	collision = std::make_shared<Collision>();

	Initialize();

	y1 = 0;
	y2 = -define_value.MAX_WINDOW_Y;

	// メインに入った時はインターバルとする
	is_interval = true;
}

// 毎フレーム入る
void Main_Scene::Update() {
	// エンターを押すまでゲームが進まない
	if (is_interval) {
		if (key_checker->key[KEY_INPUT_RETURN] == 1) {
			is_interval = false;
		}
		return;
	}

	player_action->Player_Controll();
	player_manager->Update();
	std::unique_ptr<Game_Manager> &game_manager = Game_Manager::Get_Instance();

	// エネミーのアップデート処理
	enemy_manager->Update();

	// エネミーの殲滅でクリア
	if (Is_Enemy_All_Ded()) {
		// 最終ステージでなければ次のステージへ
		if (!(static_cast<int>(game_manager->Get_Stage()) == define_value.FINAL_STAGE)) {
			game_manager->Next_Stage();
			is_interval = true;
			Initialize();
			player->Set_Power_Up(true);
			return;
		}
		// 最終ステージクリアでリザルト
		game_manager->Reset_Stage();
		game_manager->Change_Scene(Game_Manager::Clear);
		return;
	}
	
	// 敵の弾に当たったら残機を減らす
	if (Is_Enemy_Attack_Hit()) {
		// 残機を減らす
		player_manager->player_status->Dead();
		
		// 残機消失でゲームオーバー
		if (!(player_manager->player_status->Get_Life() <= 0)) {
			Player_Dead();
		}
		else {
			player_manager->player_status->Reset_Life();
			game_manager->Reset_Stage();
			game_manager->Change_Scene(Game_Manager::Game_Over);
		}
		return;
	}

	// エネミーに当たったら残機を減らす
	if (Is_Hit_Actor_Fellow()) {
		// 残機を減らす
		player_manager->player_status->Dead();

		// 残機消失でゲームオーバー
		if (!(player_manager->player_status->Get_Life() <= 0)) {
			Player_Dead();
		}
		else {
			player_manager->player_status->Reset_Life();
			game_manager->Reset_Stage();
			game_manager->Change_Scene(Game_Manager::Game_Over);
		}
	}
	
	// プレイヤーの撃つ弾がエネミーに当たったらダメージを与える
	Is_Player_Attack_Hit();
}

// メインシーンに必要なものを描画
void Main_Scene::Render() {
	// 背景の描画
	DrawExtendGraph(0, y1,
					define_value.WINDOW_X - define_value.UI_SPACE, y1 + define_value.WINDOW_Y,
					background_graph, TRUE);
	DrawExtendGraph(0, y2,
		define_value.WINDOW_X - define_value.UI_SPACE, y2 + define_value.WINDOW_Y,
		background_graph, TRUE);

	// アクターの描画
	player->Render();
	enemy_manager->Render();

	// UIの描画
	UI_class->Render();

	// インターバル中は背景のスクロール無し
	if (is_interval) {
		// アナウンスを表示
		DrawString(300, 200, "Ready?", GetColor(0, 0, 0));
		DrawString(285, 400, "Push Enter", GetColor(0, 0, 0));
		return;
	}
	// 背景のスクロール
	Scroll();
}

// 初期化
void Main_Scene::Initialize() {
	// プレイヤーの初期化
	player->Initialize();
	player_action->Initialize();
	
	// エネミーの初期化
	enemy_manager->Initialize();
}

// 背景の画像を動かす
void Main_Scene::Scroll() {
	++y1;
	++y2;

	// 画面から完全に出切ったタイミングでもう1枚の背景の上に
	if (y1 >= define_value.MAX_WINDOW_Y) {
		y1 = -define_value.MAX_WINDOW_Y;
	}
	if (y2 >= define_value.MAX_WINDOW_Y) {
		y2 = -define_value.MAX_WINDOW_Y;
	}
}

// エネミーが全滅したかどうか 全滅したらtrue
bool Main_Scene::Is_Enemy_All_Ded() {
	return enemy_manager->enemies.size() == 0;
}

// プレイヤーとエネミーが衝突したかどうか 衝突したらtrue
bool Main_Scene::Is_Hit_Actor_Fellow() {
	for (auto& enemy : enemy_manager->enemies) {
		if (collision->Box_To_Box(player->Get_Right_Edge(), player->Get_Left_Edge(), player->Get_Top_Edge(),
			enemy.Get_Right_Edge(), enemy.Get_Left_Edge(), enemy.Get_Bottom_Edge())) {
			return true;
		}
	}
	return false;
}

// プレイヤーがエネミーの攻撃を受けたかどうか 攻撃を受けたらtrue
bool Main_Scene::Is_Enemy_Attack_Hit() {
	for (int i = 0; i < enemy_manager->enemies.size(); ++i) {
		for (auto& enemy_bullet : enemy_manager->enemy_bullet) {
			if (collision->Player_To_Enemy_Bullet(player->Get_Right_Edge(), player->Get_Left_Edge(), player->Get_Top_Edge(), player->Get_Bottom_Edge(),
				enemy_bullet.Get_X(), enemy_bullet.Get_Y(), enemy_bullet.Get_Radius()))
				return true;
		}
	}
	return false;
}

// プレイヤーの攻撃がエネミーに命中したか
void Main_Scene::Is_Player_Attack_Hit() {
	for (unsigned int i = 0; i < player->player_bullet.size(); ++i) {
		auto& player_bullet = player->player_bullet[i];

		for (unsigned int j = 0; j < enemy_manager->enemies.size(); ++j) {
			auto& enemy = enemy_manager->enemies[j];

			if (collision->Enemy_To_Player_Bullet(enemy.Get_Right_Edge(), enemy.Get_Left_Edge(), enemy.Get_Top_Edge(), enemy.Get_Bottom_Edge(),
				player_bullet.Get_X(), player_bullet.Get_Y(), player_bullet.Get_Radius())) {
				// ダメージを与える
				enemy.enemy_status->Damage();
				// 当たったら弾も消える
				player->player_bullet.erase(player->player_bullet.begin() + i);

				// 死んでいたら消す
				if (enemy.enemy_status->Is_Dead()) {
					enemy_manager->enemies.erase(enemy_manager->enemies.begin() + j);
				}
			}
		}
	}
}

// プレイヤーが死亡したときの処理
void Main_Scene::Player_Dead() {
	is_interval = true;
	enemy_manager->Reset_Enemy();
	player->Initialize();
}
