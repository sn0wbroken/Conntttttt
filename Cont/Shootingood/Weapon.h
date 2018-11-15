#pragma once

// 武器(攻撃)種類の基底クラス TODO:基底クラスのActorが固まったら継承
class Weapon {
public:
	// コンストラクタ
	Weapon();
	// デストラクタ
	~Weapon();

	// 攻撃を行う
	void Attack();
};

