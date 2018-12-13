#pragma once
#include <random>

namespace Utility
{
	class Number_Generator
	{
	public:
		Number_Generator()
		{
			m_engine.seed(m_rnd());
		};
		//�͈͂̊ԂŃ����_���Ȑ���Ԃ��B
		int Generate_Number(int Min, int Max);
	private:
		//�����_���f�o�C�X���쐬
		std::random_device m_rnd;
		std::mt19937 m_engine;
	};
}