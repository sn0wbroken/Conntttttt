#include "RandomNumGenerator.h"

int Utility::NumGenerator::GenerateNum(int Min, int Max)
{
	//メルセンヌツイスターを使うため変数を作成
	//メルセンヌツイスタにランダムデバイスを挿入
	std::mt19937 engine(rnd());
	std::uniform_int_distribution<> random(Min, Max); //範囲決定
	int temp = random(engine);//範囲の中からランダムに選び出す。
	return temp;
};