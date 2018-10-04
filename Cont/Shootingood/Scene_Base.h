#pragma once

#include"DxLib.h"
#include"Unique_Component.h"

// シーンの基底クラス
class Scene_Base {
public:
	// コンストラクタ
	Scene_Base() {};

	// デストラクタ
	virtual ~Scene_Base() {};

	// 毎フレーム入る処理を書く
	virtual void Update() = 0;
	// 描画を行う
	virtual void Render() = 0;

	// 背景の画像をセットする
	virtual void Set_Background(char* path);

protected:
	// 背景の画像データ
	int background_graph;
};
