#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	else
	{
		return a.second < b.second;
	}
}

int main()
{
	int N;
	int count = 0;
	int t = -1;
	cin >> N;

	vector<pair<int, int>> input;

	for (int i = 0; i < N; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		input.push_back({tmp1,tmp2});
	}

	sort(input.begin(), input.end(), compare);

	for (int i = 0; i < N; i++)
	{
		int tmp1, tmp2;
		tmp1 = input[i].first;
		tmp2 = input[i].second;


		if (tmp1 >= t)
		{
			++count;
			t = tmp2;
		}

	}


	/*for (int i = 0; i < N; i++)
	{
		cout << input[i].first << ' ' << input[i].second << endl;

	}*/

	cout << count;


	return 0;
}