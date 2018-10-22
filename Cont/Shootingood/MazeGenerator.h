#pragma once

#include <vector>
#include <random>

namespace Maze {
	enum MazeBlock
	{
		None,
		Block,
		Path,
		Goal,
		Player,
	};

	struct MazeDataInfo //TODO::要修正
	{
		int m_height;	//高さ
		int m_width;	//長さ
		std::vector<float> m_data; //マップ配置データ

		inline int GetHeight()
		{
			return m_height;
		};
		inline int GetWidth()
		{
			return m_width;
		};

		inline std::vector<float> GetData()
		{
			return m_data;
		};
	};

	class MazeData
	{
		// コンストラクタ
		MazeData(const int height, const int width);
		// デストラクタ
		~MazeData() {};
		//迷路作成機
		void MazeGenerator();

		MazeDataInfo m_info;
	};
}