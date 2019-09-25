#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

priority_queue< int, vector<int>, greater<int> > pq;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
	{
		return a.second < b.second;
	}
	else
	{
		return a.first < b.first;
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
		input.push_back({ tmp1,tmp2 });
	}

	sort(input.begin(), input.end(), compare);

	pq.push(input[0].second);

	for (int i = 1; i < N; i++)
	{
		if (pq.top() <= input[i].first)
		{
			pq.pop();
			pq.push(input[i].second);
		}
		else
		{
			pq.push(input[i].second);
		}

	}

	/*for (int i = 0; i < N; i++)
	{
		cout << input[i].first << ' ' << input[i].second << endl;
	}*/

	cout << pq.size() << endl;

	return 0;
}