#include "MazeGenerator.h"
#include "Random_Number_Generator.h"

Maze::MazeData::MazeData()
{}
Maze::MazeData::MazeData(const int height, const int width)
{
	setMazeSize(height,width);
}

void Maze::MazeData::setMazeSize(const int height, const int width)
{
	maxheight = height;
	maxwidth = width;
	m_info.m_data.assign(static_cast<size_t> (height * width), 0);
}

void Maze::MazeData::MazeGenerator()
{
	//�����_�}�C�U�[
	Utility::Number_Generator *random_number;
	random_number = new Utility::Number_Generator;
	//Maze �쐬�A���S���Y��
	//�����ɂȂ�Ƃ����̂Ŋ�ɂȂ�悤�ɁB
	do {
		m_info.m_width = random_number->Generate_Number(31, maxheight);
	} while (m_info.m_width % 2 != 1);
	do {
		m_info.m_height = random_number->Generate_Number(31,maxwidth);
	} while (m_info.m_height % 2 != 1);
	//�O���֕ǂ�}��
	for (int x = 0; x < m_info.m_width; x++) {
		for (int y = 0; y < m_info.m_height; y++) {
			if (y == 0 || x== 0 || y == m_info.m_height - 1 || x == m_info.m_width - 1) {
				m_info.m_data[x + y * m_info.m_width] = Block;
			}
			else {
				m_info.m_data[x + y * m_info.m_width] = Path;
			}
		}
	}

	for (int x = 2; x < m_info.m_width - 1; x += 2)
	{
		for (int y = 2; y < m_info.m_height - 1; y += 2)
		{
			m_info.m_data[x + y * m_info.m_width] = Block; //���Ԋu�Ƀu���b�N��ݒu

			while (true)
			{
				int direction; //�����ϐ�
				if (x == 2) {
					direction = random_number->Generate_Number(0, 3); //����
				}
				else {
					direction = random_number->Generate_Number(0, 2);//����
				}
				int wallX = x;//x���W
				int wallY = y;//y���W
				switch (direction)
				{
				case 0://�� ������1���Z
					wallY += 1;
					break;
				case 1://�� ������1���Z
					wallY -= 1;
					break;
				case 2://�E ������1���Z
					wallX += 1;
					break;
				case 3://�� ������1���Z
					wallX -= 1;
					break;
				}
				//���Z���ꂽ���W�Ƀu���b�N���Ȃ���΃u���b�N����
				if (m_info.m_data[wallX + wallY * m_info.m_width] != Block)
				{
					//�u���b�N��ݒu
					m_info.m_data[wallX + wallY * m_info.m_width] = Block;
					break;
				}
			}
		}
	}
	//������Ƀv���C���[��ݒu
	m_info.m_data[1] = Player;
	//�E���̂ق��ɃS�[����ݒu
	m_info.m_data[(m_info.m_width - 2) + ((m_info.m_height - 2) * m_info.m_width)] = Goal;
}

Maze::MazeDataInfo Maze::MazeData::GetInfo()
{
	return m_info;
}