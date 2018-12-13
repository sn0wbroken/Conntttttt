#pragma once
#include <random>

namespace Utility
{
	class Number_Generator
	{
	public:
		Number_Generator()
		{
			engine.seed(rnd());
		};
		//範囲の間でランダムな数を返す。
		int Generate_Number(int Min, int Max);
	private:
		//ランダムデバイスを作成
		std::random_device rnd;
		std::mt19937 engine;
	};
}