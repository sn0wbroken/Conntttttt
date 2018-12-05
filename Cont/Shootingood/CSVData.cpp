#include"CSVData.h"
#include"DxLib.h" 
#include<string>
#include<sstream>
//TODO::ここにCSVデータロード関数のコードを追加する
CSVData::CSVData()
{
	LoadSound();
}
//TODO::いらないかも
CSVData::~CSVData()
{
}
//サウンドデータをメモリにロード
void CSVData::LoadSound(){
	//VectorのVectorを取得 
	//　列の配列　　要素の配列をcsvreaderから受け取る
	std::vector<std::vector <std::string>> vector_temp = reader.Read_File("Resources/CSV/SoundPathes.csv");
	for (const auto & a : vector_temp){
		if (a.size() <= 0) { //列の中の要素が０以下の場合は飛ばす。
			continue;
		}

		for (auto i = a.begin(); i != a.end();) { //要素を変数に入れるために、範囲ForではないForを使用する。
			m_SoundFile sound_temp;
			std::string string_temp = *i;
			sound_temp.ID = atoi(string_temp.c_str());
			i++;
			sound_temp.FileName = *i;
			i++;
			sound_temp.FilePath = *i;
			sound_temp.SHandle = LoadSoundMem(sound_temp.FilePath.c_str()); //サウンドをメモリをロードする。
			m_sounds.insert_or_assign(sound_temp.ID, sound_temp); //
			break;
		}
	}
}
