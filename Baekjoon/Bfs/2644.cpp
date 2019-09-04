#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int target1, target2;

class Graph
{
public:
	int N;
	vector<vector<int>> adj;

	Graph() : N(0) {}
	Graph(int n) : N(n) { adj.resize(N + 1); }

	void addEdge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void sortList()
	{
		for (int i = 0; i < N; i++)
			sort(adj[i].begin(), adj[i].end());
	}

	void bfs(int p)
	{
		vector<int> visited(N+1, 0);
		queue<int> Q;
		Q.push(p);

		while (!Q.empty())
		{
			int curr = Q.front();
			Q.pop();

			if (curr == target2)
				break;

			for (int next : adj[curr])
			{
				if (!visited[next])
				{
					visited[next] = visited[curr] + 1;
					Q.push(next);
				}
			}

		}

		if (visited[target2] != 0)
			cout << visited[target2] << endl;
		else
			cout << -1 << endl;

	}

};


int main()
{
	
	

	cin >> n;
	cin >> target1 >> target2;
	cin >> m;

	Graph g(n);

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		g.addEdge(x, y);
	}

	g.bfs(target1);

	return 0;
}
