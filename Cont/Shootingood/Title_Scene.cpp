#include"Title_Scene.h"
#include"Scene_Manager.h"

// コンストラクタ
Title_Scene::Title_Scene() {
	manual = std::make_shared<Manual>();

	// 座標には初期位置を代入
	icon_position_x = Define_Value::INITIALIZE_POSITION_X;
	icon_position_y = Define_Value::INITIALIZE_POSITION_Y;

	icon_width = Define_Value::DECIDE_ICON_WIDTH;
	icon_height = Define_Value::DECIDE_ICON_HEIGHT;

	// 選択するまでは見ない
	is_watch_manual = false;

	const CSVData & Data(CSVData::getInstance());
	CSVData::M_SoundFiles Sound = Data.sounds.at(114514);
	DxLib::PlaySoundMem(Sound.SHandle,1);

	// 初期位置はStartから
	select_command = eSelect_Command::Start;
}

// 毎フレーム入る
void Title_Scene::Update() {
	// ゲームの進行を管理するクラス
	std::unique_ptr<Scene_Manager> &game_manager = Scene_Manager::Get_Instance();

	// エスケープキーでマニュアルの閲覧を終了
	if (key_checker->key[KEY_INPUT_ESCAPE] == 1) {
		is_watch_manual = false;
		// 閉じるのでページを0に戻す
		manual->Set_Initialize_Page_Number(0);
	}

	if (!is_watch_manual) {
		// 選択アイコンの操作
		Icon_Move();

		if (key_checker->key[KEY_INPUT_RETURN] == 1) {
			switch (select_command) {
			case eSelect_Command::Start:
				game_manager->Change_Scene(Scene_Manager::Main);
				break;
			case eSelect_Command::Manual:
				// 操作説明UI表示
				is_watch_manual = true;
				break;
			case eSelect_Command::Exit:
				// ゲーム終了
				DxLib_End();
				break;
			}
		}
		return;
	}
	// マニュアル閲覧中なら、マニュアルの操作を受付
	else{
		manual->Update();
}
}


// 描画
void Title_Scene::Render() {
	DrawExtendGraph(0, 0, define_value.WINDOW_X, define_value.WINDOW_Y, background_graph, TRUE);
	DrawTriangle(icon_position_x, icon_position_y,
		icon_position_x, icon_position_y + icon_height,
	icon_position_x + icon_width, icon_position_y + (icon_height / 2),
		GetColor(0, 0, 0), TRUE);

	// マニュアル閲覧中なら、マニュアルを表示
	if (is_watch_manual) {
		manual->Render();
	}
}

// 選択アイコンを動かす
void Title_Scene::Icon_Move() {
	// スタート以上はないので返す
	if (key_checker->key[KEY_INPUT_UP] == 1) {
		if (select_command == eSelect_Command::Start) {
			return;
		}

		// 押されたキーを取得する
		auto input_key = KEY_INPUT_UP;
		icon_position_y -= Define_Value::ICON_MOVE_VALUE;
		// 選択しているものを変える
		Change_Decide(select_command, input_key);
	}
	// エグジット以下はないので返す
	if (key_checker->key[KEY_INPUT_DOWN] == 1) {
		if (select_command == eSelect_Command::Exit) {
			return;
		}

		// 押されたキーを取得する
		auto input_key = KEY_INPUT_DOWN;
		icon_position_y += Define_Value::ICON_MOVE_VALUE;
		// 選択しているものを変える
		Change_Decide(select_command, input_key);
	}
}

// 操作に応じて選択しているものを変える
void Title_Scene::Change_Decide(eSelect_Command now_select, int which_key) {
	// 押されたキーによって処理を変える
	switch (which_key) {
		// 上キーが押されていた場合
	case KEY_INPUT_UP:
		switch (now_select) {
		case eSelect_Command::Manual:
			select_command = eSelect_Command::Start;
			break;
		case eSelect_Command::Exit:
			select_command = eSelect_Command::Manual;
			break;
		}
		break;
		// 下キーが押されていた場合
	case KEY_INPUT_DOWN:
		switch (now_select) {
		case eSelect_Command::Start:
			select_command = eSelect_Command::Manual;
			break;
		case eSelect_Command::Manual:
			select_command = eSelect_Command::Exit;
			break;
		}
		break;
	}
}