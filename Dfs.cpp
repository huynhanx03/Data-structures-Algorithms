#include "bits/stdc++.h"

#define ll long long

using namespace std;

class dfs
{
    private:
        int n;
        vector <int> g[100005];
        bool check[100005];
    public:
        void do_dfs(int x)
        {
            check[x] = 1;
            for (int i = 0; i < (int) g[x].size(); ++i)
            {
                int u = g[x][i];
                if (check[u]) continue;
                do_dfs(u);
            }
        }
};

int32_t main() 
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    dfs sol;
    return 0;
}