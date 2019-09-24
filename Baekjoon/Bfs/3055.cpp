#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

char map[1001][1001];
int visit[1001][1001];
int w, h;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
pair<int, int> Start,End;
queue<pair<int, int>> river;


void input()
{
	cin >> w >> h;

	for (int j = 0; j < w; j++)
	{
		for (int k = 0; k < h; k++)
		{
			cin >> map[j][k];

			if (map[j][k] == 'S')
			{
				Start = make_pair(j, k);
			}
			else if (map[j][k] == 'D')
			{
				End = make_pair(j, k);
			}
			else if (map[j][k] == '*')
			{
				river.push(make_pair(j, k));
			}

		}
	}

}


int bfs()
{
	queue<pair<int, int>> q;
	q.push(Start);
	visit[Start.first][Start.second] = 1;

	while (!q.empty())
	{
		int flameSize = river.size();
		for (int i = 0; i < flameSize; i++)
		{
			int y = river.front().first;
			int x = river.front().second;
			river.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny >= 0 && ny < w && nx >= 0 && nx < h)
				{
					if (map[ny][nx] == '.')
					{
						map[ny][nx] = '*';
						river.push(make_pair(ny, nx));
					}
				}

			}

		}

		int curSize = q.size();

		for (int i = 0; i < curSize; i++)
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			if (y == End.first && x == End.second)
				return visit[y][x]-1;

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny >= 0 && ny < w && nx >= 0 && nx < h)
				{
					if (visit[ny][nx] == 0 && map[ny][nx] != '*'
						&& map[ny][nx] != 'X')
					{
						visit[ny][nx] = visit[y][x] + 1;
						q.push(make_pair(ny, nx));
					}

				}

			}

		}

	}

	return -1;

}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();

	int rst = bfs();

	if (rst == -1)
		cout << "KAKTUS" << '\n';
	else
		cout << rst << '\n';



	return 0;
}