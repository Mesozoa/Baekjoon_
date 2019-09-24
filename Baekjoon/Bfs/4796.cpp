#include <iostream>
using namespace std;
int main()
{
	int L, P, V;
	

	cin >> L >> P >> V;

	while (L!=0 || P != 0 || V != 0)
	{
		int i = 1;
		int result = 0;
		while (V > 0)
		{
			if (V - L > 0)
			{
				V = V - L;
				result += L;

				if (V - (P - L) > 0)
				{
					V = V - (P - L);
				}
				else
				{
					V = V - (P - L);
				}
			}
			else
			{
				result = result + V;
				V = V - L;
			}
		}

		cout << "Case " << i << ": " << result << '\n';
		++i;

		cin >> L >> P >> V;
	}



	return 0;
}