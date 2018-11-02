#pragma once
#include <random>

namespace Utility
{
	class NumGenerator
	{
	public:
		NumGenerator(){};
		//範囲の間でランダムな数を返す。
		int GenerateNum(int Min, int Max);
	private:
		//ランダムデバイスを作成
		std::random_device rnd;
	};
}