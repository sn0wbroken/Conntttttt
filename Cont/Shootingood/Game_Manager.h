#pragma once

#include"Scene_Base.h"
#include"Unique_Component.h"

#include"Title_Scene.h"
#include"Main_Scene.h"
#include"Result_Game_Over.h"
#include"Result_Clear.h"

// ゲーム全体の進行を管理する
class Game_Manager : public Unique_Component<Game_Manager> {
public:
	// どのシーンか(ゲームの状態)
	enum eScene_State {
		Title,
		Main,
		Game_Over,
		Clear
	};

	// 引数に自身を指定したものだけに生成をゆるす
	friend class Unique_Component<Game_Manager>;

	// 現在の状態
	eScene_State scene_state;	
	// stageを返す
	eStage Get_Stage();

	// 全体のループ
	void Update();
	// 描画
	void Render();

	// シーンを切り替える
	void Change_Scene(eScene_State scene_state);

	template<class T>
	void Change_Scene_();

	// クリア、ゲームオーバー時に呼ばれる。プレイステージを1に戻す
	void Reset_Stage();
	// ステージを進める ステージクリア時に呼ばれる
	void Next_Stage();

	// デストラクタ
	~Game_Manager() {};

private:
	// コンストラクタ
	Game_Manager();
	
	// プレイするステージ
	eStage stage;

	// シーンの基底クラス
	Scene_Base* scene_base;

};
