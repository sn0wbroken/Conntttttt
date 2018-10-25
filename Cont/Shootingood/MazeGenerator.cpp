#include "MazeGenerator.h"

Maze::MazeData::MazeData(const int height, const int width)
{
	m_info.m_height = height;
	m_info.m_width = width;
	m_info.m_data.assign(static_cast<size_t> (height * width), 0.0f);
}

void Maze::MazeData::MazeGenerator()
{
	//Maze �쐬�A���S���Y��
	//�����Z���k�c�C�X�^�[�^����������
	std::random_device rnd;
	std::mt19937 mt(rnd());
	//���H�̍L������p ���������L������
	std::uniform_int_distribution<> mazeran(30, 56);
	//�u���b�N��u���ꏊ����p
	std::uniform_int_distribution<> randblock3(0, 2);
	std::uniform_int_distribution<> randblock4(0, 3);
	//�����ɂȂ�Ƃ����̂Ŋ�ɂȂ�悤�ɁB
	do {
		width = mazeran(mt);
	} while (width % 2 != 1);
	do {
		height = mazeran(mt);
	} while (height % 2 != 1);
	//�O���֕ǂ�}��
	for (int i = 0; i < width; i++) {
		for (int n = 0; n < height; n++) {
			if (n == 0 || i == 0 || n == height - 1 || i == width - 1) {
				maze[i][n] = Block;
			}
			else {
				maze[i][n] = Path;
			}
		}
	}

	for (int x = 2; x < width - 1; x += 2)
	{
		for (int y = 2; y < height - 1; y += 2)
		{
			maze[x][y] = Block; //���Ԋu�Ƀu���b�N��ݒu

			while (true)
			{
				int direction; //�����ϐ�
				if (x == 2) {
					direction = randblock4(mt); //����
				}
				else {
					direction = randblock3(mt);//����
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
	maze[width - 2][height - 1] = Goal;

	int i = 0;

	for (int r = 0; r < m_info.GetWidth(); r++) {
		const int len = row.length();

		for (int c = 0; c < info.m_col; c++) {
			const std::string::size_type pos = chipNo.find(row[c]);

			info.m_data[i++] = static_cast<float> (pos - 1);
		}
	}
}