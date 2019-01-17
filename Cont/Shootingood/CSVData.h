#pragma once 
#include<string>
#include<map>
#include<list>
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
	
	struct m_EnemyArriveList
	{
		int			TIME;
		int			STAGE;
	};
//CSV�f�[�^�̊i�[��
	std::map<int, m_SoundFile> m_sounds;
	std::list<m_EnemyArriveList> m_stage1;
	//CSVData�̃R���X�g���N�^����������Load�������J�n����̂�private�ɂ��Ă���
	//�\���̂�private�ł�����������Ȃ��B
private:
	CSV_Reader m_reader; //TODO::�Ƃ肠����������
//CSV�f�[�^���[�h�֐�
	//�T�E���h�f�[�^���������Ƀ��[�h
	void LoadSound();
	//�G�̏o�����X�g�����[�h����
	void LoadEnemyArriveList();
};