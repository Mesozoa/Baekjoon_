#include <iostream>
#include <string>
#include <queue>
#define MAX 1000
#define endl "\n"
using namespace std;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int n, m;
int map[MAX][MAX];
bool Isvisited[MAX][MAX][2];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string inp;
		cin >> inp;

		for (int j = 0; j < m; j++)
		{
			int tmp = inp[j] - '0';
			map[i][j] = tmp;
		}
	}

}

int bfs()
{
	queue<pair<pair<int, int>, pair<int, int>>> Q;
	Q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
	Isvisited[0][0][0] = true;

	while (!Q.empty())
	{
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int B = Q.front().second.first;
		int Cnt = Q.front().second.second;
		Q.pop();

		if (x == n - 1 && y == m - 1)
			return Cnt;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (map[nx][ny] == 1 && B == 0)
				{
					Isvisited[nx][ny][B + 1] = true;
					Q.push(make_pair(make_pair(nx, ny), make_pair(B + 1, Cnt + 1)));
				}
				else if (map[nx][ny] == 0 && Isvisited[nx][ny][B] == false)
				{
					Isvisited[nx][ny][B] = true;
					Q.push(make_pair(make_pair(nx, ny), make_pair(B , Cnt + 1)));
				}


			}

		}

	}

	return -1;

}

void Solution()
{
	int R = bfs();
	cout << R << endl;
}

void Solve()
{
	input();
	Solution();
}


int main()
{
	Solve();


	return 0;
}