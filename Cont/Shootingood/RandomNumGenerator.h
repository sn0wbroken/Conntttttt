#pragma once
#include <random>

namespace Utility
{
	class NumGenerator
	{
	public:
		NumGenerator(){};
		//�͈͂̊ԂŃ����_���Ȑ���Ԃ��B
		int GenerateNum(int Min, int Max);
	private:
		//�����_���f�o�C�X���쐬
		std::random_device rnd;
	};
}