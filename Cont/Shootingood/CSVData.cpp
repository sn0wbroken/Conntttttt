#include"CSVData.h"
#include"DxLib.h" 
//TODO::������CSV�f�[�^���[�h�֐��̃R�[�h��ǉ�����
CSVData::CSVData()
{
}
//TODO::����Ȃ�����
CSVData::~CSVData()
{
}
//�T�E���h�f�[�^�����[�h Dxlib�ł̓T�E���h�f�[�^���������ɒu���Ă������Ƃ��\�����A
void CSVData::LoadSound()
{
	std::vector<std::vector <std::string>> TempVector = reader.Read_File("Hello"); //TODO::��قǕύX
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
		}
	}
}
