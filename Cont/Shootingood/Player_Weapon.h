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

	// 通常攻撃の射程を返す
	Vector3D Get_Limit_Range();

	// プレイヤーのショットタイプ
	eBomb_Type bomb_type;

	// プールから取り出したものを入れる入れ物
	Bullet* bullet;
	// プールから取得した撃ち出す弾をまとめる
	std::list<Bullet*> bomb_bullets;

private:
	std::shared_ptr<Player> player;
	std::unique_ptr<Key_Checker>& key_checker = Key_Checker::Get_Instance();

	// 初期化関数
	void Initialize() override;

	// キー入力で攻撃を行う
	void Fire();
	// 状態に応じたボムを設定する
	void Set_Bomb();
	// 銃口の位置を変える
	void Rotation();

	// 画面外に出た弾をプールへもどす
	void Return_Bullet_Pooling();

	// ボムを選択する
	void Chose_Bomb();
	// 全方位に弾を飛ばすボム
	void Fullrange_Shot();
	// 攻撃を降らす
	void Rain();
	
	// 時間経過で弾を消す
	void Time_Limit_Erase_Bullet();
	// 座標をみて弾を消す
	void Reference_Coordinates_Erase_Bullet(std::list<Bullet*>& bullets);

	// ボム
	std::function<void()> shoot_bomb;
	// 撃った弾を消す処理
	std::function<void()> bullet_erase;
	
	// 回転の中心(プレイヤーの中心に同じ)
	Vector3D center_position;
	// 弾が飛ぶ最大地点
	Vector3D distance_limit;

	// 現在行っているボムのタイプ
	eEnable_Bomb_Type enable_bomb_type;

	// 度数法
	float degree;
	// 弧度法
	float radian;
	// 半径(中心から銃口までの)
	float radius;

	// ボム攻撃の最中かどうか
	bool enable_bomb;
	// 連射にならないように押されているかを覚える
	bool shot_button_flag;
	// ボムの攻撃が継続しているかどうかのフラグ
	bool living_bomb;

	// 弾を撃った瞬間からカウント開始
	int timer;
	// timerがこの数値に達したら撃った弾を消す
	int clear_count;

	//TEST
	const float fire_range = 300;
};
