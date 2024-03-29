#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

char map[1001][1001];
bool visit[1001][1001];
int w, h;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
pair<int, int> Start;
vector<pair<int, int>> fire;


void input()
{
	cin >> w >> h;

	for (int j = 0; j < h; j++)
	{
		for (int k = 0; k < w; k++)
		{
			cin >> map[j][k];

			if (map[j][k] == '@')
			{
				Start = make_pair(j, k);
			}
			else if (map[j][k] == '*')
			{
				fire.push_back(make_pair(j, k));
			}

		}
	}

}

void Initialize()
{
	memset(visit, false, sizeof(visit));
	fire.clear();
}

int bfs()
{
	queue<pair<int, int>> q;
	q.push(Start);
	queue<pair<int, int>> flame;

	for (int i = 0; i < fire.size(); i++)
		flame.push(fire[i]);
	int result = 0;

	while (!q.empty())
	{
		int flameSize = flame.size();
		for (int i = 0; i < flameSize; i++)
		{
			int y = flame.front().first;
			int x = flame.front().second;
			flame.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny >= 0 && ny<h && nx >= 0 && nx<w)
				{
					if (map[ny][nx] == '.')
					{
						map[ny][nx] = '*';
						flame.push(make_pair(ny, nx));
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

			if (y == 0 || y == h - 1 || x == 0 || x == w - 1)
				return result + 1;

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny >= 0 && ny<h && nx >= 0 && nx<w)
				{
					if (!visit[ny][nx] && map[ny][nx] != '*'
						&& map[ny][nx] != '#')
					{
						visit[ny][nx] = true;
						q.push(make_pair(ny, nx));
					}

				}

			}

		}

		result++;
	}

	return -1;

}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		Initialize();
		input();

		int rst = bfs();

		if (rst == -1)
			cout << "IMPOSSIBLE" << '\n';
		else
			cout << rst << '\n';

	}


	return 0;
}