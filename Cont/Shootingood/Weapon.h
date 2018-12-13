#pragma once

#include"Actor.h"

// 武器(攻撃)種類の基底クラス
class Weapon : public Actor {
public:
	// コンストラクタ
	Weapon();
	// デストラクタ
	~Weapon();

	// 初期化
	void Initialize() override;

	// 攻撃を行う
	void Attack();
};
