#pragma once 
#include<string>
#include<map>
#include"CSV_Reader.h"

class CSVData{
public:
	CSVData();
	~CSVData();
//CSVで読み込むデータの構造体
	struct m_SoundFile{
		int			ID;			
		std::string FileName;
		std::string FilePath;
		int			SHandle;
	};
//CSVデータの格納先
	std::map<int, m_SoundFile> m_sounds;
	//CSVDataのコンストラクタが動いた時Load処理を開始するのでprivateにしておく
	//構造体もprivateでいいかもしれない。
private:
	CSV_Reader m_reader; //TODO::とりあえずここに
//CSVデータロード関数
	void LoadSound();
};