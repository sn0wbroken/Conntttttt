#pragma once
#include <random>

namespace Utility
{
	class NumGenerator
	{
	public:
		NumGenerator()
		{
			m_engine.seed(m_rnd());
		};
		//�͈͂̊ԂŃ����_���Ȑ���Ԃ��B
		int GenerateNum(int Min, int Max);
	private:
		//�����_���f�o�C�X���쐬
		std::random_device m_rnd;
		std::mt19937 m_engine;
	};
}