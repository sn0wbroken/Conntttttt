#pragma once

#include"Character.h"

// エネミーの動きを制御する
class Enemy_Controller : public Character {
public:
	// コンストラクタ
	Enemy_Controller();
	// デストラクタ
	virtual ~Enemy_Controller();
};
