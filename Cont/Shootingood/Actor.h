#pragma once

#include"Enum.h"
#include"DxLib.h"
#include"Vector3D.h"
#include"Define_Value.h"
#include"Unique_Component.h"

#include<list>
#include<string>
#include<memory>

// アクターの基底クラス
class Actor : public Unique_Component<Actor> {
public:
	// コンストラクタ
	Actor();
	// デストラクタ
	~Actor();

	// アクターの状態を設定する
	eActor_Status actor_status;

	// アクターオブジェクトを生成する
	virtual void Create_Actor(TCHAR* model_path);
	// 初期化を行う
	virtual void Initialize();
	// アクティブなアクターを描画する
	virtual void Render();
	// 毎フレーム入る更新処理
	virtual void Update();

	// 子を追加する。インスタンスが生成されたときに呼ばれる
	void Add_Child(std::shared_ptr<Actor> const actor);

	// 座標を扱うクラス
	Vector3D vector3d;

protected:
	// 定数をまとめておくクラス
	Define_Value define_value;

	// 派生クラスを子として持っておく
	std::list<std::shared_ptr<Actor>> children;
};

