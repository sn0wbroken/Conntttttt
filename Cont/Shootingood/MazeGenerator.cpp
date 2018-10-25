#include "MazeGenerator.h"
#include "RandomNumGenerator.h"

Maze::MazeData::MazeData(const int height, const int width)
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
	Utility::NumGenerator *randomNum();
	//Maze �쐬�A���S���Y��
	//�����Z���k�c�C�X�^�[�^����������
	std::random_device rnd;
	std::mt19937 mt(rnd());
	//�u���b�N��u���ꏊ����p
	std::uniform_int_distribution<> randblock3(0, 2);
	std::uniform_int_distribution<> randblock4(0, 3);
	//�����ɂȂ�Ƃ����̂Ŋ�ɂȂ�悤�ɁB
	do {
		m_info.m_width = randomNum()->GenerateNum(31, maxheight);
	} while (m_info.m_width % 2 != 1);
	do {
		m_info.m_height = randomNum()->GenerateNum(31,maxwidth);
	} while (m_info.m_height % 2 != 1);
	//�O���֕ǂ�}��
	for (int i = 1; i < m_info.m_height; i++) {
		for (int n = 0; n < m_info.m_width; n++) {
			int pos = ((i * n) + (i + n)) - 1;//����x��+����+�� - 1(MAGICNUMBER FUUUUUUUUUUUUUUCK) �Ƃ����̂�0����n�܂�z���1����n�܂���̂�������邽��
			if (n == 0 || i == 0 || i == m_info.m_height - 1 || n == m_info.m_width - 1) {
				m_info.m_data[pos] = Block;
			}
			else {
				m_info.m_data[pos] = Path;
			}
		}
	}

	for (int y = 2; y < m_info.m_height; y += 2)
	{
		for (int x = 2; x < m_info.m_width; x += 2)
		{
			int pos1 = ((y * x) + (y + x)) - 1;//����x��+����+�� - 1(MAGICNUMBER FUUUUUUUUUUUUUUCK) �Ƃ����̂�0����n�܂�z���1����n�܂���̂�������邽��
			m_info.m_data[pos1] = Block; //���Ԋu�Ƀu���b�N��ݒu

			while (true)
			{
				int direction; //�����ϐ�
				if (x == 2) {
					direction = randomNum->GenerateNum(0,3); //����
				}
				else {
					direction = randomNum->GenerateNum(0,2);//����
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
				int pos2 = ((wallY * wallX) + (wallY + wallX)) - 1;//����x��+����+�� - 1(MAGICNUMBER FUUUUUUUUUUUUUUCK) �Ƃ����̂�0����n�܂�z���1����n�܂���̂�������邽��
				//���Z���ꂽ���W�Ƀu���b�N���Ȃ���΃u���b�N����
				if (m_info.m_data[pos2] != Block)
				{
					//�u���b�N��ݒu
					m_info.m_data[pos2] = Block;
					break;
				}
			}
		}
	}
	//������Ƀv���C���[��ݒu
	m_info.m_data[1] = Player;
	//�E���̂ق��ɃS�[����ݒu
	int pos = (((m_info.m_width - 2) * (m_info.m_height - 1)) + ((m_info.m_width - 2) + (m_info.m_height - 1)) - 1);
	m_info.m_data[pos] = Goal;
	pos = 1 + 1;
}

Maze::MazeDataInfo Maze::MazeData::GetInfo()
{
	return m_info;
}