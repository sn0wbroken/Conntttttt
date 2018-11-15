#include "RandomNumGenerator.h"

int Utility::NumGenerator::GenerateNum(int Min, int Max)
{
	//メルセンヌツイスターを使うため変数を作成
	std::uniform_int_distribution<> random(Min, Max); //範囲決定
	return random(engine);//範囲の中からランダムに選び出す。
};