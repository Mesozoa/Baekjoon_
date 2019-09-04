#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph
{
public:
	int N;
	vector<vector<int>> adj;
	vector<bool> visited;


	Graph() : N(0) {}
	Graph(int n) : N(n)
	{
		adj.resize(N+1);
		visited.resize(N+1);
	}

	void addEdge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void sortList()
	{
		for (int i = 0; i < N; i++)
		{
			sort(adj[i].begin(), adj[i].end());
		}
	}

	int dfs(int curr)
	{
		int nodes = 1;
		visited[curr] = true;
		for (int next : adj[curr])
		{
			if (!visited[next])
			{
				nodes += dfs(next);
			}
		}
		return nodes;
	}

};
int main()
{
	int com_num;
	int adj_num;

	cin >> com_num;
	cin >> adj_num;

	Graph g(com_num);

	for (int i = 0; i < adj_num; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		g.addEdge(tmp1, tmp2);
	}

	cout<<g.dfs(1) - 1;

	return 0;
}