#include "Random_Number_Generator.h"

int Utility::Number_Generator::Generate_Number(int Min, int Max)
{
	//�����Z���k�c�C�X�^�[���g�����ߕϐ����쐬
	std::uniform_int_distribution<> random(Min, Max); //�͈͌���
	return random(m_engine);//�͈͂̒����烉���_���ɑI�яo���B
};