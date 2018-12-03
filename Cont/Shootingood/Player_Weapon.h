#pragma once

#include"Enum.h"
#include"Bullet.h"
#include"Weapon.h"
#include"Player.h"
#include"Vector3D.h"
#include"Key_Checker.h"

#include<memory>
#include<functional>

// プレイヤーが扱う武器(攻撃)のクラス
class Player_Weapon : public Weapon {
public:
	// コンストラクタ
	Player_Weapon();
	// デストラクタ
	~Player_Weapon();

	// 更新処理
	void Update() override;
	// 描画
	void Render() override;

	// プレイヤーのショットタイプ
	eBom_Type ebom_type;

private:
	std::shared_ptr<Player> player;
	std::unique_ptr<Key_Checker>& key_checker = Key_Checker::Get_Instance();

	// 初期化関数
	void Initialize() override;

	// キーの入力で弾を発射
	void Fire();
	// 状態に応じたショットを設定する
	void Set_Shot_Pattern();
	// 銃口の位置を変える
	void Rotation();

	// 弾幕の種類
	std::function<void()> bom_type;
	// オイラー角
	float degree = 0;
	// ラジアン角
	float radian = 0;
	// sin波を作るために加算する値
	int counter = 0;
};
