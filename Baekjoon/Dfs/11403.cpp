#include <iostream>
#include <string.h>
using namespace std;

int N;
int input[101][101];
bool isvisited[101];

void dfs(int j)
{
	for (int k = 0; k < N; k++) {
		if (input[j][k] && !isvisited[k]) {
			isvisited[k]++;
			dfs(k);
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
		}
	}

	for (int i = 0; i < N; i++)
	{
		memset(isvisited, 0, sizeof(isvisited));
		dfs(i);

		for (int j = 0; j < N; j++)
		{
			if (isvisited[j])
				input[i][j] = 1;
		}

	}





	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << input[i][j] << ' ';
		}

		cout << '\n';

	}

	return 0;
}