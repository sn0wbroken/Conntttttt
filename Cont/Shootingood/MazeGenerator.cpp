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
	//高さx横+高さ+横 で添え字を出せる。
	//0 X 1 + 0 * 1の場合は 1になるが-1してあげるといい heightは0から widthは1から
	//ランダマイザー
	Utility::NumGenerator *randomNum;
	randomNum = new Utility::NumGenerator;
	//Maze 作成アルゴリズム
	//メルセンヌツイスター型乱数生成器
	std::random_device rnd;
	std::mt19937 mt(rnd());
	//一次元で扱う方法がいまいち思いつかないため二次元配列作成後一次元に翻訳するものとする
	int maze[99][99];
	//偶数になるとずれるので奇数になるように。
	do {
		m_info.m_width = randomNum->GenerateNum(31, maxheight);
	} while (m_info.m_width % 2 != 1);
	do {
		m_info.m_height = randomNum->GenerateNum(31,maxwidth);
	} while (m_info.m_height % 2 != 1);
	//外側へ壁を挿入
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
			maze[x][y] = Block; //等間隔にブロックを設置

			while (true)
			{
				int direction; //方向変数
				if (x == 2) {
					direction = randomNum->GenerateNum(0, 3); //方向
				}
				else {
					direction = randomNum->GenerateNum(0, 2);//方向
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
				if (maze[wallX][wallY] != Block)
				{
					//ブロックを設置
					maze[wallX][wallY] = Block;
					break;
				}
			}
		}
	}
	//入り口にプレイヤーを設置
	maze[1][0] = Player;
	//右下のほうにゴールを設置
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