#pragma once

#include"Rect.h"
#include"Bullet.h"
#include"Character.h"

#include<vector>

// プレイヤー本体のクラス
class Player : public Character {
public:
	// コンストラクタ
	Player();
	// デストラクタ
	~Player();

	// 初期化
	void Initialize();

	// パワーアップ状態であるかをセットする
	void Set_Power_Up(bool set_is_power_up);
	// パワーアップ状態であるかを返す
	bool Get_Power_Up();

	// 弾倉。ボムの時に使う
	std::list<Bullet*> magazine;

private:
	// 矩形クラス
	Rect<float> rectangle;

	// 死亡判定。死んでいたらtrue
	bool is_dead;
	// パワーアップ状態か
	bool is_power_up;
};
