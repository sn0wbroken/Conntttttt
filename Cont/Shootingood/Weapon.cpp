#include"Weapon.h"
#include"Player_Weapon.h"
#include"Player_Manager.h"

// コンストラクタ
Weapon::Weapon() {

}

// デストラクタ
Weapon::~Weapon() {

}

// 初期化
void Weapon::Initialize() {
	// 子も回す
	Actor::Initialize();
}