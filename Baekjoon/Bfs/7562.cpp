#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

bool visit[301][301];
int h;
int dx[8] = { 1,1,-1,-1,2,2 ,-2,-2};
int dy[8] = {2, -2,2,-2,1,-1,1,-1};
pair<int, int> Start,End;


void input()
{
	cin >> h;
	//int Sfirst, Ssecond;
	//int Efirst, Esecond;

	cin >> Start.first >> Start.second;
	cin >> End.first >> End.second;

}

void Initialize()
{
	memset(visit, false, sizeof(visit));
}

int bfs()
{
	queue<pair<pair<int, int>,int>> q;
	q.push(make_pair(make_pair(Start.first,Start.second),0));

	int result = 0;

	while (!q.empty())
	{
		int curSize = q.size();

		for (int i = 0; i < curSize; i++)
		{
			int y = q.front().first.first;
			int x = q.front().first.second;
			int cnt = q.front().second;
			q.pop();

			if (y == End.first && x == End.second)
			{
				return cnt;
			}

			for (int i = 0; i < 8; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny >= 0 && ny < h && nx >= 0 && nx < h)
				{
					if (!visit[ny][nx])
					{
						visit[ny][nx] = true;
						q.push(make_pair(make_pair(ny, nx),cnt+1));
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