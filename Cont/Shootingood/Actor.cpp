#include "Actor.h"

// コンストラクタ
Actor::Actor() {

}

// デストラクタ
Actor::~Actor() {
	
}

// アクターオブジェクトを生成する
void Actor::Create_Actor(TCHAR*model_path) {
	std::list<std::shared_ptr<Actor>>::iterator iterator = children.begin();
	while (iterator != children.end()) {
		if ((*iterator)->actor_status != eActor_Status::Break) {
			++iterator;
			(*iterator)->Create_Actor(model_path);
		}
	}
}

// アクティブなアクターを描画する
void Actor::Render() {
	std::list<std::shared_ptr<Actor>>::iterator iterator = children.begin();
	while (iterator != children.end()) {
		if ((*iterator)->actor_status != eActor_Status::Break) {
			(*iterator)->Render();
			++iterator;
		}
	}
}

// 毎フレーム入る更新処理
void Actor::Update() {
	std::list<std::shared_ptr<Actor>>::iterator iterator = children.begin(); // Player_Weaponの代入で失敗
	while (iterator != children.end()) {
		if ((*iterator)->actor_status != eActor_Status::Break) {
 			(*iterator)->Update();
			++iterator;
		}
	}
}

// 子を追加する
void Actor::Add_Child(std::shared_ptr<Actor> const actor) {
	children.push_back(actor);
}
