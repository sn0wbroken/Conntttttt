#include "MazeGenerator.h"

Maze::MazeData::MazeData(const int height, const int width)
{
	m_info.m_height = height;
	m_info.m_width = width;
	m_info.m_data.assign(static_cast<size_t> (height * width), 0.0f);
}

void Maze::MazeData::MazeGenerator()
{
	//Maze 作成アルゴリズム
	//メルセンヌツイスター型乱数生成器
	std::random_device rnd;
	std::mt19937 mt(rnd());
	//迷路の広さ決定用 狭すぎず広すぎず
	std::uniform_int_distribution<> mazeran(30, 56);
	//ブロックを置く場所決定用
	std::uniform_int_distribution<> randblock3(0, 2);
	std::uniform_int_distribution<> randblock4(0, 3);
	//偶数になるとずれるので奇数になるように。
	do {
		width = mazeran(mt);
	} while (width % 2 != 1);
	do {
		height = mazeran(mt);
	} while (height % 2 != 1);
	//外側へ壁を挿入
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
			maze[x][y] = Block; //等間隔にブロックを設置

			while (true)
			{
				int direction; //方向変数
				if (x == 2) {
					direction = randblock4(mt); //方向
				}
				else {
					direction = randblock3(mt);//方向
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