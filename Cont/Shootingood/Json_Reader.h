#pragma once

#include<vector>
#include<string>
#include<utility>
#include<fstream>

//TEST_STATUS
struct Status {
	int ID;
	std::string name;
	int hp;
	int atk;
};

// Json�ǂݍ��݃N���X
class Json_Reader {
public:
	// �R���X�g���N�^
	Json_Reader() {};
	// �f�X�g���N�^
	~Json_Reader() {};

	// �ǂݎ���������n���i�[
	std::vector<Status> statuses;

	// �t�@�C���̓ǂݍ��݂��s��
	void Read_File(std::string file_pass) {
		auto ifstream = std::ifstream();
		// �t�@�C����ǂݍ���
		ifstream.open(file_pass);
		// �s
		std::string row;

		// ����Ȃ��s��ǂ�
		std::getline(ifstream, row);
		std::getline(ifstream, row);
		// �ǂ񂾂���Ȃ��s��j������
		ifstream.clear();

		// �t�@�C���̏I���܂œǂ�(�����ł�Excel�̂P�s���ɂȂ�)
		while (!std::getline(ifstream, row).eof()) {
			// �ǂݍ��񂾂��̂�������ꕨ
			Status status;
			// ","���f���~�^�Ƃ��čs���������ɂ���
			auto readed_row = Parse(row, ",");

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
	std::string Parse(const std::string & str, const std::string & delimiter) {
		//TEST_STRUCT
		Status status;

		// ���ׂ镶����̗v�f��
		std::string::size_type pos = 0;

		// �ǂݎ�镶���񂪂Ȃ��Ȃ�܂ő�����
		while (pos != std::string::npos) {
			// ���ݓǂ�ł���Ƃ��납�玟�̃f���~�^�܂ł̃T�C�Y�����
			std::string::size_type p = str.find(delimiter, pos);

			// ���Ńf���~�^��������Ȃ��Ȃ�(�ǂݎ�镶����̏I���)�܂ŗ��������
			if (p == std::string::npos) {
				// �Ō�̃f���~�^���當����̏I���܂ł�Ԃ��Ă����܂�
				return str.substr(pos);
				break;
			}
			// ������΂�����
			else {
				return str.substr(pos, p - pos);
			}

			// �f���~�^��ǂݔ�΂����߂Ƀf���~�^�̃T�C�Y�𑫂�
			pos = p + delimiter.size();
		}
	}

};