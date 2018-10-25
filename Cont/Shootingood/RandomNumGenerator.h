#pragma once
#include <random>

namespace Utility
{
	class NumGenerator
	{
	public:
		NumGenerator()
		{
			//メルセンヌツイスタにランダムデバイスを挿入
			engine.seed(rnd());
		};
		//範囲の間でランダムな数を返す。
		int GenerateNum(int Min, int Max)
		{
			std::uniform_int_distribution<> random(Min, Max); //範囲決定
			return random(engine);//範囲の中からランダムに選び出す。
		};
	private:
		//ランダムデバイスを作成
		std::random_device rnd;
		//メルセンヌツイスターを使うため変数を作成
		std::mt19937 engine;
	};
}