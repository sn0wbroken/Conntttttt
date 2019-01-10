#pragma once

// どのコマンドを選んでいるか(タイトル画面で使用)
enum class eSelect_Command {
	Start,
	Manual,
	Exit
};

// 移動する方向(エネミーのAIに使用)
enum class eMove_Direction {
	Right,
	Left,
	Up,
	Down
};

// TODO:ボムの実装に合わせる
// プレイヤーのボムのタイプ
enum class eBomb_Type {
	None, // ボム未所持状態
	Fullrange, // 全方位に弾を飛ばす
	Rain // 攻撃を降らす
};

// プレイするステージ
enum class eStage {
	stage1,
	stage2,
	stage3
};

// アクターの状態。これを見て描画などの更新処理を行う
enum class eActor_State {
	Action,
	Break
};

// 現在撃っているボムのタイプ
enum class eEnable_Bomb_Type {
	None, // ボム攻撃を行っていない
	Fullrange, // 全方位に弾を飛ばすボム
	Rain // 弾を降らすボム
};