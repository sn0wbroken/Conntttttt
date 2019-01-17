#pragma once 
#include<string>
#include<map>
#include<list>
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
	
	struct m_EnemyArriveList
	{
		int			TIME;
		int			STAGE;
	};
//CSVデータの格納先
	std::map<int, m_SoundFile> m_sounds;
	std::list<m_EnemyArriveList> m_stage1;
	//CSVDataのコンストラクタが動いた時Load処理を開始するのでprivateにしておく
	//構造体もprivateでいいかもしれない。
private:
	CSV_Reader m_reader; //TODO::とりあえずここに
//CSVデータロード関数
	//サウンドデータをメモリにロード
	void LoadSound();
	//敵の出現リストをロードする
	void LoadEnemyArriveList();
};