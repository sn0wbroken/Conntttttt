#pragma once 
#include <string>
#include <map>
#include "CSV_Reader.h"
#include"singleton.h"

class CSVData : public Singleton<CSVData>
{
public:
	CSVData();
	~CSVData();
#pragma region CSVで読み込むデータの構造体
	struct M_SoundFiles
	{
		int			ID;			
		std::string FileName;
		std::string FilePath;
		int			SHandle;
	};
#pragma endregion
#pragma region CSVデータの格納先
	std::map<int, M_SoundFiles> sounds;
#pragma endregion
	//CSVDataのコンストラクタが動いた時Load処理を開始するのでprivateにしておく
	//構造体もprivateでいいかもしれない。
private:
	CSV_Reader reader; //TODO::とりあえずここに
#pragma region CSVデータロード関数
	void LoadSound();
#pragma endregion
};