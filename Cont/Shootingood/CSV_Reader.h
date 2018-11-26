#pragma once

#include"DxLib.h"

#include<vector>
#include<string>
#include <vector>
#include<fstream>
#include<cassert>

// CSV�t�@�C���ǂݍ��ݗp�N���X
class CSV_Reader {
public:
	// �R���X�g���N�^
	CSV_Reader() {
	}
	// �f�X�g���N�^
	~CSV_Reader() {}

	// �t�@�C���̓ǂݍ��݂��s��

	std::vector<std::vector <std::string>> Read_File(std::string file_pass) {
		auto ifstream = std::ifstream();
		// �t�@�C����ǂݍ���
		ifstream.open(file_pass);
		assert(ifstream.fail);
		// �s
		std::string row;

		// ����Ȃ��s��ǂ�
		std::getline(ifstream, row);
		std::getline(ifstream, row);
		// �ǂ񂾂���Ȃ��s��j������
		ifstream.clear();
		// �ǂݎ���������n���i�[
		std::vector<std::vector<std::string>> Array;
		Array.resize(30);
		// �t�@�C���̏I���܂œǂ�(�����ł�Excel�̂P�s���ɂȂ�)
		while (!std::getline(ifstream, row).eof()) {
			// ","���f���~�^�Ƃ��čs���������ɂ���
<<<<<<< HEAD
			Array.push_back(Parse(row, ","));
=======
			auto readed_row = Parse(row, ",");

			readed_row.size();

			// �������ɂ������̂�������
			status.ID   = std::stoi(readed_row[0]);
			status.name = readed_row[1];
			status.hp   = std::stoi(readed_row[2]);
			status.atk  = std::stoi(readed_row[3]);

			// �o�������̂��܂Ƃ߂�
			statuses.push_back(status);
>>>>>>> origin/ishikuraBranch
		}
		return Array;
	}

	// �������Ɏ������������A�������̃f���~�^�ŋ�؂������̂𕪂���
	std::vector<std::string> Parse(const std::string & str, const std::string & delimiter) {
		// ���������̂������(�����Ԃ�)
		std::vector<std::string> result;
		// ���ׂ镶����̗v�f��
		std::string::size_type pos = 0;

		// �ǂݎ�镶���񂪂Ȃ��Ȃ�܂ő�����
		while (pos != std::string::npos) {
			// ���ݓǂ�ł���Ƃ��납�玟�̃f���~�^�܂ł̃T�C�Y�����
			std::string::size_type p = str.find(delimiter, pos);

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
			pos = p + delimiter.size();
		}

		return result;
	}
};
