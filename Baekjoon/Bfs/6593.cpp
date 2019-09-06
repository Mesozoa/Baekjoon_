#include <iostream>
#include <string>
#include <string.h>
#include <queue>
using namespace std;

int L, R, C;
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int df[6] = {0,0,0,0,1,-1};
char MAP[30][30][30];
bool visit[30][30][30];
string Answer;

pair<pair<int, int>, int> Start, End;

void Initialize()
{
	memset(visit, false, sizeof(visit));
	Answer.clear();
}

void Input()
{
	cin >> L >> R >> C;
	if (L == 0 && R == 0 && C == 0)
		exit(0);

	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < R; j++)
		{
			for (int k = 0; k < C; k++)
			{
				cin >> MAP[i][j][k];
				if (MAP[i][j][k] == 'S')
				{
					Start.first.first = i;
					Start.first.second = j;
					Start.second = k;
				}
				else if (MAP[i][j][k] == 'E')
				{
					End.first.first = i;
					End.first.second = j;
					End.second = k;
				}
			}
		}
	}
}

int BFS(int a, int b, int c)
{
	queue<pair<pair<int, int>, pair<int, int>>> Q;
	Q.push(make_pair(make_pair(a, b), make_pair(c, 0)));
	visit[a][b][c] = true;

	while (Q.empty() == 0)
	{
		int f = Q.front().first.first;
		int x = Q.front().first.second;
		int y = Q.front().second.first;
		int Cnt = Q.front().second.second;
		Q.pop();

		if (f == End.first.first && x == End.first.second &&
			y == End.second)
		{
			return Cnt;
		}

		for (int i = 0; i < 6; i++)
		{
			int nf = f + df[i];
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nf >= 0 && nx >= 0 && ny >= 0
				&& nf < L&&nx < R&&ny < C)
			{
				if (MAP[nf][nx][ny] == '#')
					continue;
				if (MAP[nf][nx][ny] == '.' || MAP[nf][nx][ny] == 'E')
				{
					if (visit[nf][nx][ny] == false)
					{
						visit[nf][nx][ny] = true;
						Q.push(make_pair(make_pair(nf, nx), make_pair(ny, Cnt + 1)));
					}
				}
			}


		}


	}

	return -1;

}

void Solution()
{
	int R = BFS(Start.first.first, Start.first.second, Start.second);
	if (R == -1)
		cout << "Trapped!" << '\n';
	else
		cout << "Escaped in " << R << " minute(s)." << '\n';

}

void Solve()
{
	while (1)
	{
		Initialize();
		Input();
		Solution();
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	Solve();


	return 0;
}