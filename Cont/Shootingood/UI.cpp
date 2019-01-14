#include"UI.h"
#include"Scene_Manager.h"

std::unique_ptr<Scene_Manager>& scene_manager = Scene_Manager::Get_Instance();

// コンストラクタ
UI::UI() {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	player_weapon = player_manager->player_weapon;
	
	UI_background_graph = LoadGraph("Picture/UI/UI_Background.png");
}

// 描画
void UI::Render() {
	DrawExtendGraph((int)define_value.MAX_SCREEN_X, (int)define_value.MIN_WINDOW_Y,
		define_value.WINDOW_X, define_value.MAX_WINDOW_Y, UI_background_graph, TRUE);
	Now_Stage();
	Enemy_Number();
	Player_Life();
}

// 現在プレイしているステージを表示
void UI::Now_Stage() {
	std::ostringstream now_stage;
	// enumの値に揃えて＋1
	now_stage << "Stage " << static_cast<int>(scene_manager->Get_Stage()) + 1;
	//DrawString(define_value.UI_X + (define_value.ADJUSTMENT_VALUE * 30), define_value.UI_BASE_Y, now_stage.str().c_str(), GetColor(0, 0, 0));
}

// エネミーの数を表示
void UI::Enemy_Number() {
	std::ostringstream enemy_number;
	enemy_number << "残りエネミー : " << enemies.size();
	//DrawString(define_value.UI_X, define_value.UI_BASE_Y + define_value.FELLOW_UI_SPACE, enemy_number.str().c_str(), GetColor(0, 0, 0));
}

// プレイヤーの残機を表示
void UI::Player_Life() {
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();

	//DrawString(define_value.UI_X, define_value.UI_BASE_Y + (define_value.FELLOW_UI_SPACE * 4), "Life", GetColor(0, 0, 0));

	switch (player_manager->player_status->Get_Life()) {
	case 2:
		// TODO: プレイヤーの残機表示用のモデルを描画
		break;
	case 3:
		break;
	}
}