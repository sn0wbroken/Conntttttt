#include "RandomNumGenerator.h"

int Utility::NumGenerator::GenerateNum(int Min, int Max)
{
	//�����Z���k�c�C�X�^�[���g�����ߕϐ����쐬
	std::uniform_int_distribution<> random(Min, Max); //�͈͌���
	return random(engine);//�͈͂̒����烉���_���ɑI�яo���B
};