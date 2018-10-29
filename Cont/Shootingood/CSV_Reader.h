#pragma once

#include"DxLib.h"

#include<string>
#include<fstream>

struct Status {
	int ID;
	std::string name;
	int hp;
	int atk;
};

// CSV�t�@�C���ǂݍ��ݗp�N���X
class CSV_Reader {
public:
	// �R���X�g���N�^
	CSV_Reader() {
		Read_File();
	}
	// �f�X�g���N�^
	~CSV_Reader() {}
	
	// �ǂݎ���������n���i�[
	std::vector<Status> statuses;

	// �t�@�C���̓ǂݍ��݂��s��
	void Read_File() {
		auto if_stream = std::ifstream();
		// �t�@�C����ǂݍ���
		if_stream.open("Resources/Enemy_Data.csv");
		// �s
		std::string row;

		// �t�@�C���̏I���܂œǂ�(�����ł�Excel�̂P�s���ɂȂ�)
		while (!std::getline(if_stream, row).eof()) {
			// �ǂݍ��񂾂��̂�������ꕨ
			Status status;
			// ","���f���~�^�Ƃ��čs���������ɂ���
			auto readed_row = Split(row, ",");

			// �������ɂ������̂�������
			status.ID   = std::stoi(readed_row[0]);
			status.name = readed_row[1];
			status.hp   = std::stoi(readed_row[2]);
			status.atk  = std::stoi(readed_row[3]);

			// �o�������̂��܂Ƃ߂�
			statuses.push_back(status);
		}
	}

	// �������Ɏ������������A�������̃f���~�^�ŋ�؂������̂𕪂���
	std::vector<std::string> Split(const std::string & str, const std::string & delim) {
		// ���������̂������(�����Ԃ�)
		std::vector<std::string> result;
		// ���ׂ镶����̗v�f��
		std::string::size_type pos = 0;

		// �ǂݎ�镶���񂪂Ȃ��Ȃ�܂ő�����
		while (pos != std::string::npos) {
			// ���ݓǂ�ł���Ƃ��납�玟�̃f���~�^�܂ł̃T�C�Y�����
			std::string::size_type p = str.find(delim, pos);

			// ���Ńf���~�^��������Ȃ��Ȃ�(�ǂݎ�镶����̏I���)�܂ŗ��������
			if (p == std::string::npos) {
				// �Ō�̃f���~�^���當����̍Ŋ��܂ł��i�[���Ă����܂�
				result.push_back(str.substr(pos));
				break;
			}
			// ������΂�����
			else {
				result.push_back(str.substr(pos, p - pos));
			}

			// �f���~�^��ǂݔ�΂����߂Ƀf���~�^�̃T�C�Y�𑫂�
			pos = p + delim.size();
		}

		return result;
	}
};
