#include"Enum.h"
#include"Enemy_AI.h"
#include"Enemy_Manager.h"

//TODO::以下修正必要
const Vector3D FrontVector(-1,0,0); 
const Vector3D UpVector(0.0f, 1.0f, 0.0f); // 上向きベクトル

// コンストラクタ
//必要なもの
//エネミーのモデルID
//エネミーの座標アドレス
//プレイヤーの座標をどうにかする。
Enemy_AI::Enemy_AI()
{
	//m_enemy = std::make_shared<Enemy>();
}

// デストラクタ
Enemy_AI::~Enemy_AI() {}

// 毎フレーム入る
void Enemy_AI::Update() {
	
}

void Enemy_AI::MoveAI0()
{
	//Vector3D m_Forward;
	//float m_Rotation;
	////計算部
	//m_Forward = Vector3D::VectorLength(m_enemy->vector3d);//TODO::プレイヤー座標取得
	////// ベクトルから角度を計算
	//Vector3D cos = Vector3D::dot(FrontVector, m_Forward) / (Vector3D::VectorLength(FrontVector) * Vector3D::VectorLength(m_Forward));
	//m_Rotation = acosf(cos.x);
	////内積計算
	//Vector3D dot = Vector3D::dot(UpVector, Vector3D::cross(FrontVector, m_Forward));
	//if (dot.x < 0) {
	//	m_Rotation = -m_Rotation;
	//}
	////移動部
	//// 移動ベクトルに速度，経過時間を乗算して，移動量を求める
	//enemy += m_Forward * 2.0f; //TODO::MAGICNUMBER  deltatimeのようなものを掛ける
	//// 到着すべき位置に着いたら移動をやめる
	//Vector3D length = VMath::VectorLength(enemy); //TODO::プレイヤー座標取得
	//if (length.x <= (/*deltatime * */2.0f)) { //TODO::MagicNumber
	//return;
	//}
	
}
