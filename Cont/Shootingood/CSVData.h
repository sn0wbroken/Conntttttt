#pragma once 
#include<string>
#include<map>
#include"CSV_Reader.h"

class CSVData{
public:
	CSVData();
	~CSVData();
#pragma region CSV�œǂݍ��ރf�[�^�̍\����
	struct m_SoundFile{
		int			ID;			
		std::string FileName;
		std::string FilePath;
		int			SHandle;
	};
#pragma endregion
#pragma region CSV�f�[�^�̊i�[��
	std::map<int, m_SoundFile> m_sounds;
#pragma endregion
	//CSVData�̃R���X�g���N�^����������Load�������J�n����̂�private�ɂ��Ă���
	//�\���̂�private�ł�����������Ȃ��B
private:
	CSV_Reader reader; //TODO::�Ƃ肠����������
#pragma region CSV�f�[�^���[�h�֐�
	void LoadSound();
#pragma endregion
};