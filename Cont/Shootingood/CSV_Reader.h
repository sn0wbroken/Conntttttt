#pragma once

#include"DxLib.h"

#include<vector>
#include<string>
#include<fstream>

//TEST_STATUS
struct Status {
	int ID;
	std::string name;
	int hp;
	int atk;
};

// CSVファイル読み込み用クラス
class CSV_Reader {
public:
	// コンストラクタ
	CSV_Reader() {
	}
	// デストラクタ
	~CSV_Reader() {}
	
	// 読み取った完成系を格納
	std::vector<Status> statuses;

	// ファイルの読み込みを行う
	void Read_File(std::string file_pass) {
		auto ifstream = std::ifstream();
		// ファイルを読み込む
		ifstream.open(file_pass);
		// 行
		std::string row;

		// いらない行を読む
		std::getline(ifstream, row);
		std::getline(ifstream, row);
		// 読んだいらない行を破棄する
		ifstream.clear();

		// ファイルの終わりまで読む(ここではExcelの１行ずつになる)
		while (!std::getline(ifstream, row).eof()) {
			// 読み込んだものを入れる入れ物
			Status status;
			// ","をデリミタとして行を小分けにする
			auto readed_row = Parse(row, ",");

			readed_row.size();

			// 小分けにしたものを代入する
			status.ID   = std::stoi(readed_row[0]);
			status.name = readed_row[1];
			status.hp   = std::stoi(readed_row[2]);
			status.atk  = std::stoi(readed_row[3]);

			// 出来たものをまとめる
			statuses.push_back(status);
		}
	}

	// 第一引数に取った文字列を、第二引数のデリミタで区切ったものを分ける
	std::vector<std::string> Parse(const std::string & str, const std::string & delimiter) {
		// 分けたものをいれる(これを返す)
		std::vector<std::string> result;
		// 調べる文字列の要素数
		std::string::size_type pos = 0;

		// 読み取る文字列がなくなるまで続ける
		while (pos != std::string::npos) {
			// 現在読んでいるところから次のデリミタまでのサイズを取る
			std::string::size_type p = str.find(delimiter, pos);

			// ↑でデリミタが見つからなくなる(読み取る文字列の終わり)まで来たら入る
			if (p == std::string::npos) {
				// 最後のデリミタから文字列の最期までを格納しておしまい
				result.push_back(str.substr(pos));
				break;
			}
			// 見つかればこっち
			else {
				result.push_back(str.substr(pos, p - pos));
			}

			// デリミタを読み飛ばすためにデリミタのサイズを足す
			pos = p + delimiter.size();
		}

		return result;
	}
};
