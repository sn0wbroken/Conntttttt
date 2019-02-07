#pragma once

#include"Enum.h"
#include"DxLib.h"
#include"Vector3D.h"
#include"Define_Value.h"
#include"Unique_Component.h"

#include<list>
#include<string>
#include<memory>
#include<unordered_map>

// アクターの基底クラス
class Actor : public Unique_Component<Actor> {
public:
	// コンストラクタ
	Actor();
	// デストラクタ
	~Actor();

	// アクターの状態を設定する
	eActor_State actor_state;

	// アクターオブジェクトを生成する
	virtual void Create_Actor(TCHAR* model_path);
	// 初期化を行う
	virtual void Initialize();
	// 毎フレーム入る更新処理
	virtual void Update();
	// アクティブなアクターを描画する
	virtual void Render();

	// 子を追加する。インスタンスが生成されたときに呼ばれる
	void Add_Child(std::string name, std::shared_ptr<Actor> const actor);

	// 座標を扱うクラス
	Vector3D vector3d;

	// 派生クラスを子として持っておく
	std::unordered_map<std::string, std::shared_ptr<Actor>> children;

protected:
	// 定数をまとめておくクラス
	Define_Value define_value;
};
