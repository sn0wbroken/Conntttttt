#include "RandomNumGenerator.h"

int Utility::NumGenerator::GenerateNum(int Min, int Max)
{
	//�����Z���k�c�C�X�^�[���g�����ߕϐ����쐬
	//�����Z���k�c�C�X�^�Ƀ����_���f�o�C�X��}��
	std::mt19937 engine(rnd());
	std::uniform_int_distribution<> random(Min, Max); //�͈͌���
	int temp = random(engine);//�͈͂̒����烉���_���ɑI�яo���B
	return temp;
};