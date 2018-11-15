#pragma once
#include <random>

namespace Utility
{
	class NumGenerator
	{
	public:
		NumGenerator()
		{
			engine.seed(rnd());
		};
		//範囲の間でランダムな数を返す。
		int GenerateNum(int Min, int Max);
	private:
		//ランダムデバイスを作成
		std::random_device rnd;
		std::mt19937 engine;
	};
}