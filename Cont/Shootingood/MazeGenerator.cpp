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
	//ランダマイザー
	Utility::Number_Generator *random_number;
	random_number = new Utility::Number_Generator;
	//Maze 作成アルゴリズム
	//偶数になるとずれるので奇数になるように。
	do {
		m_info.m_width = random_number->Generate_Number(31, maxheight);
	} while (m_info.m_width % 2 != 1);
	do {
		m_info.m_height = random_number->Generate_Number(31,maxwidth);
	} while (m_info.m_height % 2 != 1);
	//外側へ壁を挿入
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
			m_info.m_data[x + y * m_info.m_width] = Block; //等間隔にブロックを設置

			while (true)
			{
				int direction; //方向変数
				if (x == 2) {
					direction = random_number->Generate_Number(0, 3); //方向
				}
				else {
					direction = random_number->Generate_Number(0, 2);//方向
				}
				int wallX = x;//x座標
				int wallY = y;//y座標
				switch (direction)
				{
				case 0://下 方向へ1加算
					wallY += 1;
					break;
				case 1://上 方向へ1加算
					wallY -= 1;
					break;
				case 2://右 方向へ1加算
					wallX += 1;
					break;
				case 3://左 方向へ1加算
					wallX -= 1;
					break;
				}
				//加算された座標にブロックがなければブロックを代入
				if (m_info.m_data[wallX + wallY * m_info.m_width] != Block)
				{
					//ブロックを設置
					m_info.m_data[wallX + wallY * m_info.m_width] = Block;
					break;
				}
			}
		}
	}
	//入り口にプレイヤーを設置
	m_info.m_data[1] = Player;
	//右下のほうにゴールを設置
	m_info.m_data[(m_info.m_width - 2) + ((m_info.m_height - 2) * m_info.m_width)] = Goal;
}

Maze::MazeDataInfo Maze::MazeData::GetInfo()
{
	return m_info;
}