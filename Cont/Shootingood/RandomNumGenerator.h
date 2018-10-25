#pragma once
#include <random>

namespace Utility
{
	class NumGenerator
	{
	public:
		NumGenerator()
		{
			//�����Z���k�c�C�X�^�Ƀ����_���f�o�C�X��}��
			engine.seed(rnd());
		};
		//�͈͂̊ԂŃ����_���Ȑ���Ԃ��B
		int GenerateNum(int Min, int Max)
		{
			std::uniform_int_distribution<> random(Min, Max); //�͈͌���
			return random(engine);//�͈͂̒����烉���_���ɑI�яo���B
		};
	private:
		//�����_���f�o�C�X���쐬
		std::random_device rnd;
		//�����Z���k�c�C�X�^�[���g�����ߕϐ����쐬
		std::mt19937 engine;
	};
}