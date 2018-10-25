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

	struct MazeDataInfo //TODO::�v�C��
	{
		int m_height;	//����
		int m_width;	//����
		std::vector<float> m_data; //�}�b�v�z�u�f�[�^

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
		// �R���X�g���N�^
		MazeData(const int height, const int width);
		// �f�X�g���N�^
		~MazeData() {};
		//���H�쐬�@
		void MazeGenerator();

		MazeDataInfo m_info;
	};
}