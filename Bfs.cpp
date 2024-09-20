#include "bits/stdc++.h"

#define ll long long

using namespace std;

const int xmax = 1e5 + 5;
class bfs
{
    private:
        int n;
        vector<int> g[100005];
        queue<int> s;
        bool check[100005];
        int path[100005];

    public:
        void do_bfs(int x)
        {
            check[x] = 1;
            s.push(x);
            while (!s.empty())
            {
                int u = s.front();
                s.pop();
                for (int i = 0; i < (int)g[u].size(); ++i)
                {
                    int v = g[u][i];
                    if (check[v])
                        continue;
                    check[v] = 1;
                    s.push(v);
                    path[v] = u;
                }
            }
        }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    bfs sol;
    return 0;
}