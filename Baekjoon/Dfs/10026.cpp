#include <iostream>
using namespace std;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
char input[101][101];
bool isvisited[101][101];
int N;
int component = 0;


void dfs(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= 0 && ny < N && nx >= 0 && nx < N && !isvisited[nx][ny] && input[x][y] == input[nx][ny])
		{
			isvisited[nx][ny]++;
			dfs(nx, ny);
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
			cin>>input[i][j];
		}
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!isvisited[i][j])
			{
				++component;
				++isvisited[i][j];
				dfs(i, j);
			}

		}
	}
	cout << component<<' ';
	component = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (input[i][j] == 'G')
				input[i][j] = 'R';
			isvisited[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!isvisited[i][j])
			{
				++component;
				++isvisited[i][j];
				dfs(i, j);
			}

		}
	}
	
	cout << component;

	return 0;
}