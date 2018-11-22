#pragma once

#include"Scene_Base.h"
#include"Main_Scene.h"
#include"Title_Scene.h"
#include"Result_Clear.h"
#include"Result_Game_Over.h"
#include"Unique_Component.h"

// ゲーム全体の進行を管理する
class Scene_Manager : public Unique_Component<Scene_Manager> {
public:
	// どのシーンか(ゲームの状態)
	enum eScene_State {
		Title,
		Main,
		Game_Over,
		Clear
	};

	// 引数に自身を指定したものだけに生成をゆるす
	friend class Unique_Component<Scene_Manager>;

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
	// クリア、ゲームオーバー時に呼ばれる。プレイステージを1に戻す
	void Reset_Stage();
	// ステージを進める ステージクリア時に呼ばれる
	void Next_Stage();

	// デストラクタ
	~Scene_Manager() {};

private:
	// コンストラクタ
	Scene_Manager();

	// プレイするステージ
	eStage stage;

	// シーンの基底クラス
	Scene_Base* scene_base;
};