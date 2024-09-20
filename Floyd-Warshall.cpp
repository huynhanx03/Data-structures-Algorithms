#include "bits/stdc++.h"

using namespace std;

const int oo = 1e9;

int n;
vector <vector<int>> dist, path;

void init()
{
    cin >> n;
    dist.resize(n);
    path.resize(n);
    for (int i = 0; i < n; ++i)
    {
        dist[i].resize(n);
        path[i].resize(n);
        for (int j = 0; j < n; ++j)
        {
            int x;
            cin >> x;
            if (i == j) path[i][j] = 0;
            if (x == 0 && i != j) 
            {
                dist[i][j] = oo;
                path[i][j] = -1;
            }
            else 
            {
                dist[i][j] = x;
                path[i][j] = i;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    init();
    for (int i = 0; i < n ;++i)
    {
        for (int j = 0; j < n; ++j) cout << dist[i][j] << ' ';
        cout << '\n';
        // chua xong
    }
        
}