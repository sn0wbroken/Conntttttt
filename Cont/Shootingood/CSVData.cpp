#include"CSVData.h"
#include"DxLib.h" 
#include<string>

//TODO::������CSV�f�[�^���[�h�֐��̃R�[�h��ǉ�����
CSVData::CSVData()
{
	LoadSound();
	//LoadEnemyArriveList();
}
//TODO::����Ȃ�����
CSVData::~CSVData()
{
}

void CSVData::LoadSound(){
	//Vector��Vector���擾 
	//�@��̔z��@�@�v�f�̔z���csvreader����󂯎��
	std::vector<std::vector <std::string>> vector_temp = m_reader.Read_File("Resources/CSV/SoundPathes.csv");
	for (const auto & a : vector_temp){
		if (a.size() <= 0) { //��̒��̗v�f���O�ȉ��̏ꍇ�͔�΂��B
			continue;
		}

		for (auto i = a.begin(); i != a.end();) { //�v�f��ϐ��ɓ���邽�߂ɁA�͈�For�ł͂Ȃ�For���g�p����B
			m_SoundFile sound_temp;
			std::string string_temp = *i;
			sound_temp.ID = atoi(string_temp.c_str());
			i++;
			sound_temp.FileName = *i;
			i++;
			sound_temp.FilePath = *i;
			sound_temp.SHandle = LoadSoundMem(sound_temp.FilePath.c_str()); //�T�E���h�������������[�h����B
			m_sounds.insert_or_assign(sound_temp.ID, sound_temp); //
			break;
		}
	}
}

void CSVData::LoadEnemyArriveList()
{
	//Vector��Vector���擾 
//�@��̔z��@�@�v�f�̔z���csvreader����󂯎��
	std::vector<std::vector <std::string>> vector_temp = m_reader.Read_File("Resources/CSV/Enemy_Data.csv");
	for (const auto & a : vector_temp) {
		if (a.size() <= 0) { //��̒��̗v�f���O�ȉ��̏ꍇ�͔�΂��B
			continue;
		}

		for (auto i = a.begin(); i != a.end();) { //�v�f��ϐ��ɓ���邽�߂ɁA�͈�For�ł͂Ȃ�For���g�p����B
			m_EnemyArriveList TempList;
			std::string string_temp = *i;
			TempList.TIME = atoi(string_temp.c_str()); //�o�������鎞�Ԃ��擾
			i++;
			string_temp = *i;
			TempList.STAGE = atoi(string_temp.c_str()); //�o��������X�e�[�W���擾
			m_stage1.push_back(TempList);
			break;
		}
	}
}
