#pragma once

#include"Actor.h"

// 武器(攻撃)種類の基底クラス
class Weapon : public Actor {
public:
	// コンストラクタ
	Weapon();
	// デストラクタ
	~Weapon();

	// 攻撃を行う
	void Attack();

	// 座標関係のクラス。銃口の座標として扱う
	Vector3D vector3;
};

