#include "bits/stdc++.h"

using namespace std;

#define ii pair<int,int>

const int xmax = 1e5 + 5;
const int oo = 1e9;

int n, m;
vector <int> path, dist;
vector <ii> graph[xmax];
vector <bool> visited;

void init()
{
    cin >> n >> m;
    path.assign(n, -1);
    dist.assign(n, oo);
    visited.assign(n,0);
    int u, v, w;
    while (m--)
    {
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }
}

void prim(int s)
{
    priority_queue <ii,vector<ii>, greater<ii>> qu;
    dist[s] = 0;
    qu.push({0,s});
    while(!qu.empty())
    {
        int u = qu.top().second;
        qu.pop();
        visited[u] = 1;
        for (auto [w, v] : graph[u])
        {
          if (!visited[v] && dist[v] > w)
		  {
			  dist[v] = w;
			  path[v] = u;
			  qu.push({w,v});
		  }
        }
    }
}

void Print()
{
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (path[i] == -1) continue;
		ans+=dist[i];
		cout << path[i]<< " - " << i << " : " << dist[i] << '\n';
	}
	cout << "Weight of MST "<< ans;
}

void sol()
{
	init();
	prim(0);
	Print();
}

int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    sol();
    return 0;
}