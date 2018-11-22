#pragma once

#include"DxLib.h"

#include<string>
#include <vector>
#include<fstream>
#include<cassert>

// CSVファイル読み込み用クラス
class CSV_Reader {
public:
	// コンストラクタ
	CSV_Reader() {
	}
	// デストラクタ
	~CSV_Reader() {}

	// ファイルの読み込みを行う

	std::vector<std::vector <std::string>> Read_File(std::string file_pass) {
		auto ifstream = std::ifstream();
		// ファイルを読み込む
		ifstream.open(file_pass);
		assert(ifstream.fail);
		// 行
		std::string row;

		// いらない行を読む
		std::getline(ifstream, row);
		std::getline(ifstream, row);
		// 読んだいらない行を破棄する
		ifstream.clear();
		// 読み取った完成系を格納
		std::vector<std::vector<std::string>> Array;
		Array.resize(30);
		// ファイルの終わりまで読む(ここではExcelの１行ずつになる)
		while (!std::getline(ifstream, row).eof()) {
			// ","をデリミタとして行を小分けにする
			Array.push_back(Parse(row, ","));
		}
		return Array;
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
