#include <iostream>
#include <string.h>
using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int input[101][101] = { 0 };
bool visited[101][101] = { 0 };
int M, N, K;
int cnt = 1;
int ans = 0;

void dfs(int x, int y)
{

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (input[nx][ny] && !visited[nx][ny] && nx>=0 &&nx<N && ny>=0 && ny<M)
		{
			visited[nx][ny] = true;
			++cnt;
			dfs(nx, ny);
		}

	}

}

int main()
{
	cin >> N >> M >> K;

	for (int i = 0; i < K; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		input[tmp1-1][tmp2-1] = 1;
	}

	for (int j = 0; j < N; j++)
	{
		for (int k = 0; k < M; k++)
		{
			if (input[j][k] && !visited[j][k])
			{
				cnt = 0;
				dfs(j, k);
				if (cnt > ans)
					ans = cnt;
			}

		}
	}

	cout << ans ;




	return 0;
}