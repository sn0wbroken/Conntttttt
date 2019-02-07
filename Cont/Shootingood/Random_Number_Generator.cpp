#include "Random_Number_Generator.h"

int Utility::Number_Generator::Generate_Number(int Min, int Max)
{
	//�����Z���k�c�C�X�^�[���g�����ߕϐ����쐬
	std::uniform_int_distribution<> random(Min, Max); //�͈͌���
	return random(m_engine);//�͈͂̒����烉���_���ɑI�яo���B
}
float Utility::Number_Generator::Generate_Number(float Min, float Max) {
	//�����Z���k�c�C�X�^�[���g�����ߕϐ����쐬
	std::uniform_real_distribution<> random(Min, Max); //�͈͌���
	return static_cast<float>(random(m_engine));//�͈͂̒����烉���_���ɑI�яo���B
};
