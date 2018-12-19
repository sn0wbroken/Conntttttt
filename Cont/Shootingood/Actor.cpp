#include "Actor.h"

// コンストラクタ
Actor::Actor() {

}

// デストラクタ
Actor::~Actor() {
	
}

// アクターオブジェクトを生成する
void Actor::Create_Actor(TCHAR*model_path) {
	for (auto iterator = children.begin(); iterator != children.end(); ++iterator) {
		if (iterator->second->actor_state != eActor_State::Break) {
			++iterator;
			iterator->second->Create_Actor(model_path);
		}
	}
}

// 初期化を行う
void Actor::Initialize() {
	for (auto iterator = children.begin(); iterator != children.end(); ++iterator) {
		if (iterator->second->actor_state != eActor_State::Break) {
			iterator->second->Initialize();
		}
	}
}

// 毎フレーム入る更新処理
void Actor::Update() {
	for (auto iterator = children.begin(); iterator != children.end(); ++iterator) {
		if (iterator->second->actor_state != eActor_State::Break) {
			iterator->second->Update();
		}
	}
}

// アクティブなアクターを描画する
void Actor::Render() {
	for (auto iterator = children.begin(); iterator != children.end(); ++iterator) {
		if (iterator->second->actor_state != eActor_State::Break) {
			iterator->second->Render();
		}
	}
}

// 子を追加する
void Actor::Add_Child(std::string name, std::shared_ptr<Actor> const actor) {
	children[name] = actor;
}
