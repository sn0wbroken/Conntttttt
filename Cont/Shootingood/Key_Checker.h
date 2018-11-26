#pragma once

#include"DxLib.h"
#include"Define_Value.h"
#include"Unique_Component.h"

// 全てのキーの入力状態をチェックする
class Key_Checker : public Unique_Component<Key_Checker> {
public:
	// コンストラクタ
	Key_Checker() {}
	// デストラクタ
	~Key_Checker() {}

	// 定数をまとめておくクラス
	Define_Value define_value;

	// 引数に自身を指定したものだけに生成をゆるす
	friend class Unique_Component<Key_Checker>;

	// 全てのキー
	int key[256];

	int Update_Key() {
		// 現在のキーの入力状態を格納する
		char tmpKey[256];
		// 全てのキーの入力状態を得る
		GetHitKeyStateAll(tmpKey);

		// 全てのキーの入力状態を
		for (int i = 0; i < define_value.KEY_NUMEBR; i++) {
			// 押されていたら1を返す
			if (tmpKey[i] != 0) {
				++key[i];
			}
			else {
				key[i] = 0;
			}
		}
		return 0;
	}
};
