#include "Random_Number_Generator.h"

int Utility::Number_Generator::Generate_Number(int Min, int Max)
{
	//メルセンヌツイスターを使うため変数を作成
	std::uniform_int_distribution<> random(Min, Max); //範囲決定
	return random(m_engine);//範囲の中からランダムに選び出す。
}
float Utility::Number_Generator::Generate_Number(float Min, float Max) {
	//メルセンヌツイスターを使うため変数を作成
	std::uniform_real_distribution<> random(Min, Max); //範囲決定
	return static_cast<float>(random(m_engine));//範囲の中からランダムに選び出す。
};
