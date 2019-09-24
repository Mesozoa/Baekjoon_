#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

int n, t, g;
int dist[100000];

void bfs() 
{
	queue<int> q;
	q.push({ n });
	dist[n] = 0;
	while (!q.empty()) 
	{
		int x = q.front(); q.pop();
		if (dist[x] > t) break;
		if (x == g) 
		{
			printf("%d\n", dist[x]);
			return;
		}
		int dx[] = { x + 1, x * 2 };
		for (int i = 0; i < 2; i++) 
		{
			int nx = dx[i];
			if (nx > 99999) continue;
			if (i && nx) 
			{
				string s = to_string(nx);
				s[0] -= 1;
				nx = stoi(s);
			}
			if (dist[nx] == -1) 
			{
				q.push(nx);
				dist[nx] = dist[x] + 1;
			}
		}
	}
	printf("ANG\n");
}

int main() 
{
	memset(dist, -1, sizeof(dist));
	scanf("%d %d %d", &n, &t, &g);
	bfs();
	return 0;
}
