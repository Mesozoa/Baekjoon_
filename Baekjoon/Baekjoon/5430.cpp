#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		string func;
		cin >> func;

		int N;
		cin >> N;

		string arr;
		cin >> arr;


		deque<int> dq;

		string temp;

		for (int j = 0; j < arr.length(); j++)
		{
			if (arr[j] == '[')
				continue;
			else if (arr[j] >= '0' && arr[j] <= '9')
				temp += arr[j];
			else if (arr[j] == ',' || arr[j] == ']')
			{
				if (!temp.empty())
				{
					dq.push_back(stoi(temp));
					temp.clear();
				}
			}

		}

		bool print = true;
		bool left = true;

		for (int k = 0; k < func.length(); k++)
		{
			if (func[k] == 'R')
			{
				left = !left;
			}
			else
			{
				if (dq.empty())
				{
					print = false;
					cout << "error\n";
					break;
				}
				else
				{
					if (left)
						dq.pop_front();
					else
						dq.pop_back();
				}
			}
		}

		if (print)
		{
			if (left)
			{
				cout << "[";
				while (!dq.empty())
				{
					cout << dq.front();
					dq.pop_front();
					if (!dq.empty())
						cout << ",";
				}
				cout << "]\n";
			}
			else
			{
				cout << "[";
				while (!dq.empty())
				{
					cout << dq.back();
					dq.pop_back();
					if (!dq.empty())
						cout << ",";
				}
				cout << "]\n";
			}
		}


	}


	return 0;
}