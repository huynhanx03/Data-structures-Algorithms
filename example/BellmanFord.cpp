#include "bits/stdc++.h"

using namespace std;

const int oo = 1e9;

struct Edge
{
	int source, target, weight;
	Edge(int source = 0, int target = 0, int weight = 0)
	{
		this->source = source;
		this->target = target;
		this->weight = weight;
	}
};

int n, m, u, v, w;
vector <int> dist, path;
vector <Edge> Graph;

void init()
{
	cin >> n >> m;
	dist.assign(n, oo);
	path.assign(n, -1);
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		Graph.push_back(Edge(u, v, w));
	}
}
bool Bellman_Ford(int s)
{
	int u, v, w;
	dist[s] = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			u = Graph[j].source;
			v = Graph[j].target;
			w = Graph[j].weight;
			if (dist[u] != oo && (dist[u] + w < dist[v]))
			{
				dist[v] = dist[u] + w;
				path[v] = u;
			}
		}
	for (int j = 0; j < m; ++j)
	{
		u = Graph[j].source;
		v = Graph[j].target;
		w = Graph[j].weight;
		if (dist[u] != oo && (dist[u] + w < dist[v])) return 0;
	}
	return 1;
}
void solve()
{
	init();
	int s = 0, t = 4;
	if (Bellman_Ford(s)) cout << dist[t];
	else cout << "Graph contains negative weight cycle";
}

int main() 
{
	ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

	return 0;
}