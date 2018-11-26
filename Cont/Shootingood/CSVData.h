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
#pragma region CSV�œǂݍ��ރf�[�^�̍\����
	struct M_SoundFiles
	{
		int			ID;			
		std::string FileName;
		std::string FilePath;
		int			SHandle;
	};
#pragma endregion
#pragma region CSV�f�[�^�̊i�[��
	std::map<int, M_SoundFiles> sounds;
#pragma endregion
	//CSVData�̃R���X�g���N�^����������Load�������J�n����̂�private�ɂ��Ă���
	//�\���̂�private�ł�����������Ȃ��B
private:
	CSV_Reader reader; //TODO::�Ƃ肠����������
#pragma region CSV�f�[�^���[�h�֐�
	void LoadSound();
#pragma endregion
};