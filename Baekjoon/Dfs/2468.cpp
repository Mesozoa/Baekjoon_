#include <iostream>
#include <string.h>
using namespace std;
int N;
int input[101][101];
bool isvisited[101][101];
int _max = -1;
int _min = 101;
int component = 0;
int ans = -1;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

void dfs(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < N&&ny >= 0 && nx < N&&nx >= 0 && !isvisited[nx][ny] && input[nx][ny])
		{
			++isvisited[nx][ny];
			dfs(nx, ny);
		}

	}


}

void rain(int height)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (input[i][j] <= height)
				input[i][j] = 0;
		}
	}

}


int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> input[i][j];

			if (input[i][j] > _max)
				_max = input[i][j];
			if (input[i][j] < _min)
				_min = input[i][j];
		}
	}

	_min--;


	for (int i = _min; i<= _max; ++i)
	{
		rain(i);

		/*for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << input[i][j] << ' ';
			}
			cout << endl;
		}

		cout << endl;
*/
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!isvisited[i][j] && input[i][j])
				{
					++component;
					++isvisited[i][j];
					dfs(i, j);
				}

			}
		}

		if (component > ans)
			ans = component;

		memset(isvisited, false, sizeof(isvisited));
		component = 0;
	}

	cout << ans;

	return 0;
}