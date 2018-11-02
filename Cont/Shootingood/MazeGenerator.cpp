#include "MazeGenerator.h"
#include "RandomNumGenerator.h"

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
	//����x��+����+�� �œY�������o����B
	//0 X 1 + 0 * 1�̏ꍇ�� 1�ɂȂ邪-1���Ă�����Ƃ��� height��0���� width��1����
	//�����_�}�C�U�[
	Utility::NumGenerator *randomNum;
	randomNum = new Utility::NumGenerator;
	//Maze �쐬�A���S���Y��
	//�����Z���k�c�C�X�^�[�^����������
	std::random_device rnd;
	std::mt19937 mt(rnd());
	//�ꎟ���ň������@�����܂����v�����Ȃ����ߓ񎟌��z��쐬��ꎟ���ɖ|�󂷂���̂Ƃ���
	int maze[99][99];
	//�����ɂȂ�Ƃ����̂Ŋ�ɂȂ�悤�ɁB
	do {
		m_info.m_width = randomNum->GenerateNum(31, maxheight);
	} while (m_info.m_width % 2 != 1);
	do {
		m_info.m_height = randomNum->GenerateNum(31,maxwidth);
	} while (m_info.m_height % 2 != 1);
	//�O���֕ǂ�}��
	for (int i = 0; i < m_info.m_width; i++) {
		for (int n = 0; n < m_info.m_height; n++) {
			if (n == 0 || i == 0 || n == m_info.m_height - 1 || i == m_info.m_width - 1) {
				maze[i][n] = Block;
			}
			else {
				maze[i][n] = Path;
			}
		}
	}

	for (int x = 2; x < m_info.m_width - 1; x += 2)
	{
		for (int y = 2; y < m_info.m_height - 1; y += 2)
		{
			maze[x][y] = Block; //���Ԋu�Ƀu���b�N��ݒu

			while (true)
			{
				int direction; //�����ϐ�
				if (x == 2) {
					direction = randomNum->GenerateNum(0, 3); //����
				}
				else {
					direction = randomNum->GenerateNum(0, 2);//����
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
				if (maze[wallX][wallY] != Block)
				{
					//�u���b�N��ݒu
					maze[wallX][wallY] = Block;
					break;
				}
			}
		}
	}
	//������Ƀv���C���[��ݒu
	maze[1][0] = Player;
	//�E���̂ق��ɃS�[����ݒu
	maze[m_info.m_width - 2][m_info.m_height - 1] = Goal;
	int a = 0;
	for (int i = 0; i < m_info.m_width; i++) {
		for (int n = 0; n < m_info.m_height; n++) {
			m_info.m_data[a++] = maze[i][n];
		}
	}
		a = a + (1 - 1);

}

Maze::MazeDataInfo Maze::MazeData::GetInfo()
{
	return m_info;
}