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
	Left
};

// プレイヤーのショットタイプ
enum class ePlayer_Shot_Type {
	Straight,
	Wave
};

// プレイするステージ
enum class eStage {
	stage1,
	stage2,
	stage3
};

// アクターの状態。これを見て描画などの更新処理を行う
enum class eActor_Status {
	Action,
	Break
};
