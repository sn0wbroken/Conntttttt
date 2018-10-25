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
	//高さx横+高さ+横 で添え字を出せる。
	//0 X 1 + 0 * 1の場合は 1になるが-1してあげるといい heightは0から widthは1から
	//ランダマイザー
	Utility::NumGenerator *randomNum();
	//Maze 作成アルゴリズム
	//メルセンヌツイスター型乱数生成器
	std::random_device rnd;
	std::mt19937 mt(rnd());
	//ブロックを置く場所決定用
	std::uniform_int_distribution<> randblock3(0, 2);
	std::uniform_int_distribution<> randblock4(0, 3);
	//偶数になるとずれるので奇数になるように。
	do {
		m_info.m_width = randomNum()->GenerateNum(31, maxheight);
	} while (m_info.m_width % 2 != 1);
	do {
		m_info.m_height = randomNum()->GenerateNum(31,maxwidth);
	} while (m_info.m_height % 2 != 1);
	//外側へ壁を挿入
	for (int i = 1; i < m_info.m_height; i++) {
		for (int n = 0; n < m_info.m_width; n++) {
			int pos = ((i * n) + (i + n)) - 1;//高さx横+高さ+横 - 1(MAGICNUMBER FUUUUUUUUUUUUUUCK) というのも0から始まる配列と1から始まるものが分かれるため
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
			int pos1 = ((y * x) + (y + x)) - 1;//高さx横+高さ+横 - 1(MAGICNUMBER FUUUUUUUUUUUUUUCK) というのも0から始まる配列と1から始まるものが分かれるため
			m_info.m_data[pos1] = Block; //等間隔にブロックを設置

			while (true)
			{
				int direction; //方向変数
				if (x == 2) {
					direction = randomNum->GenerateNum(0,3); //方向
				}
				else {
					direction = randomNum->GenerateNum(0,2);//方向
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
				int pos2 = ((wallY * wallX) + (wallY + wallX)) - 1;//高さx横+高さ+横 - 1(MAGICNUMBER FUUUUUUUUUUUUUUCK) というのも0から始まる配列と1から始まるものが分かれるため
				//加算された座標にブロックがなければブロックを代入
				if (m_info.m_data[pos2] != Block)
				{
					//ブロックを設置
					m_info.m_data[pos2] = Block;
					break;
				}
			}
		}
	}
	//入り口にプレイヤーを設置
	m_info.m_data[1] = Player;
	//右下のほうにゴールを設置
	int pos = (((m_info.m_width - 2) * (m_info.m_height - 1)) + ((m_info.m_width - 2) + (m_info.m_height - 1)) - 1);
	m_info.m_data[pos] = Goal;
	pos = 1 + 1;
}

Maze::MazeDataInfo Maze::MazeData::GetInfo()
{
	return m_info;
}