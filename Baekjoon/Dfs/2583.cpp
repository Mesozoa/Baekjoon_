#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int input[101][101] = { 0 };
bool isvisited[101][101] = { 0 };
int cnt = 1;

void dfs(int y,int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (input[ny][nx] == 0 && !isvisited[ny][nx] && ny < M && ny >= 0 && nx < N &&nx >= 0)
		{
			isvisited[ny][nx]++;
			++cnt;
			dfs(ny, nx);
		}

	}

}

int main()
{
	cin >> M >> N >> K;

	for (int i = 0; i < K; i++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = y1; j < y2; j++)
		{
			for (int k = x1; k < x2; k++)
			{
					input[j][k]++;
			}
		}
	}

	vector<int> ans;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (input[i][j] == 0 && !isvisited[i][j])
			{
				isvisited[i][j]++;
				dfs(i, j);
				ans.push_back(cnt);
				cnt = 1;
			}
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << ' ';
	}

	/*for (int j = 0; j < M; j++)
	{
		for (int k = 0; k < N; k++)
		{
			cout << input[j][k];
		}
		cout << endl;
	}*/


	return 0;
}