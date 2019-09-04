#include <iostream>
using namespace std;

int n, k;
int input[1001][1001];
bool visite[1001];

int main()
{
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		int tmp;
		cin >> tmp;
		input[i][tmp] = 1;
	}


	return 0;
}