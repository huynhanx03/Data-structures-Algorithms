#include "bits/stdc++.h"

#define ll long long

using namespace std;

const int xmax = 1e5+5;
const int oo = 1e9;

class dijkstra
{
private:
    struct node
    {
        int d1;
        int c; // const
    };
    int n;
    int d[xmax];
    vector <node> g[xmax];
    int path[xmax];
    struct cmp
    {
        bool operator() (const node &x, const node &y) const 
        {
            return x.c > y.c;
        }
    };
public:
    void do_dijkstra(int x)
    {
        priority_queue <node,vector<node>,cmp> qu;
        for (int i = 1; i <= n; ++i) d[i] = oo;
        d[x] = 0;
        qu.push({0,x});
        while (!qu.empty())
        {
            int u = qu.top().d1;
            int du = qu.top().c;
            qu.pop();
            if (du > d[u]) continue;
            for (int i = 0; i < g[u].size(); ++i)
            {
                int v = g[u][i].d1;
                int dv = g[u][i].c;
                if (d[v] > du + dv)
                {
                    d[v] = du + dv;
                    qu.push({d[v],v});
                    path[v] = u;
                }
            }
        }
    }
};

int32_t main() 
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    dijkstra sol;
    return 0;
}