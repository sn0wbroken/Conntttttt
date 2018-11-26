#include"CSVData.h"
#include"DxLib.h" 
//TODO::ここにCSVデータロード関数のコードを追加する
CSVData::CSVData()
{
	LoadSound();
}
//TODO::いらないかも
CSVData::~CSVData()
{
}
//サウンドデータをロード Dxlibではサウンドデータをメモリに置いておくことが可能だが、
void CSVData::LoadSound()
{
	std::vector<std::vector <std::string>> TempVector = reader.Read_File("Resources/CSV/SoundPathes.csv");
	for (const auto & a : TempVector)
	{
		M_SoundFiles TempSound;
		for (auto i = a.begin(); i != a.end();)
		{
			std::string TempString = *i;
			TempSound.ID = atoi(TempString.c_str());
			i++;
			TempSound.FileName = *i;
			i++;
			TempSound.FilePath = *i;
			TempSound.SHandle = LoadSoundMem(TempSound.FilePath.c_str());
			sounds.insert_or_assign(TempSound.ID, TempSound);
			break;
		}
	}

}
