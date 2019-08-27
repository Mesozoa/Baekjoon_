#include <iostream>
using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

int input[51][51];
bool visited[51][51];
int M, N, K;

void dfs(int x,int y)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;

		if (input[nx][ny] && !visited[nx][ny])
		{
			visited[nx][ny]++;
			dfs(nx, ny);
		}

	}
}

int main()
{

	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++)
	{

		cin >> M >> N>>K;

		memset(input, 0, sizeof(input));
		memset(visited, 0, sizeof(visited));
		
		int ans = 0;

		for (int i = 0; i < K; i++)
		{
			int tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			input[tmp1][tmp2] = 1;
		}

		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (input[j][k] && !visited[j][k])
				{
					++ans;
					visited[j][k]++;
					dfs(j,k);
				}

			}
		}

		cout << ans << endl;

	}


	return 0;
}