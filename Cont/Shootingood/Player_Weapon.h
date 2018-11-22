#pragma once

#include"Enum.h"
#include"Bullet.h"
#include"Weapon.h"
#include"Player.h"
#include"Vector3D.h"
#include"Key_Checker.h"

#include<memory>
#include<functional>

// プレイヤーが扱う武器(攻撃)のクラス TODO:プレイヤーの仕様が固まってないのでひとまず抽象的な名前で
class Player_Weapon : public Weapon {
public:
	// コンストラクタ
	Player_Weapon();
	// コピーコンストラクタ
	Player_Weapon(std::shared_ptr<Player> set_player);
	// デストラクタ
	~Player_Weapon();

	// 更新処理
	void Update() override;

	// プレイヤーのショットタイプ
	ePlayer_Shot_Type shot_type;

private:
	std::shared_ptr<Player> player;
	std::unique_ptr<Key_Checker>& key_checker = Key_Checker::Get_Instance();

	// 初期化関数
	void Initialize();

	// キーの入力で弾を発射
	void Fire();
	// キーの入力で攻撃の種類を切り替える。毎フレーム受付ける
	void Change_Fire_Type();
	// 状態に応じたショットを設定する
	void Set_Shot_Pattern();

	// 打ち出した弾丸が画面外へ出ているかを判断する
	bool Check_Off_Screen(Bullet& player_Bullet);
	// 打ち出した弾丸が画面外に出ていたら消す
	void Bullet_Off_Screen_Erase();

	// 弾幕の種類
	std::function<void()> fire_type;
	// 角度
	float radian;
	// 弾が発射される位置
	double position_x;
	// sin波を作るために加算する値
	int counter;
	// 振れ幅
	double amplitude;
};
