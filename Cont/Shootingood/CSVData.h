#pragma once 
#include<string>
#include<map>
#include"CSV_Reader.h"

class CSVData{
public:
	CSVData();
	~CSVData();
//CSV�œǂݍ��ރf�[�^�̍\����
	struct m_SoundFile{
		int			ID;			
		std::string FileName;
		std::string FilePath;
		int			SHandle;
	};
//CSV�f�[�^�̊i�[��
	std::map<int, m_SoundFile> m_sounds;
	//CSVData�̃R���X�g���N�^����������Load�������J�n����̂�private�ɂ��Ă���
	//�\���̂�private�ł�����������Ȃ��B
private:
	CSV_Reader m_reader; //TODO::�Ƃ肠����������
//CSV�f�[�^���[�h�֐�
	void LoadSound();
};