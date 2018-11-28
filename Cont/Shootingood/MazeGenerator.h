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

	struct MazeDataInfo
	{
		int m_height;	//�c��
		int m_width;	//����
		std::vector<float> m_data; //�}�b�v�z�u�f�[�^
	};

	class MazeData
	{
	public:
		MazeData();
		// �R���X�g���N�^
		MazeData(const int height, const int width);
		// �f�X�g���N�^
		~MazeData() {};

		void setMazeSize(const int height, const int width);
		//���H�쐬�@
		void MazeGenerator();

		MazeDataInfo GetInfo();
	private:
		MazeDataInfo m_info;

		int maxheight;
		int maxwidth;
	};
}