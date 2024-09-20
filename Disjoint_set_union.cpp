#include "bits/stdc++.h"

using namespace std;

const int xmax = 1e5 + 5;

int n, parent[xmax], sz[xmax], ranh[xmax];

void makeSet()
{
    for (int i = 0; i < xmax; ++i) 
    {
        parent[i] = i;
        ranh[i] = 0; // Gốc của cây có độ cao = 0
        sz[i] = 1; // Ban đầu tập hợp có kích cỡ = 1
    }
}

int findSet(int u)
{
    while (u != parent[u]) u = parent[u];
    return u;

    // nén đường đi
    return u == parent[u] ? u : parent[u] = findSet(parent[u]);
}

void unionSet(int u, int v)
{
    int up = parent[u], vp = parent[v];

    if (up != vp) {
        /* ============== Xét theo độ cao ===============

        if (ranh[up] < ranh[vp]) swap(up, vp); // quy ước up luôn là gốc
        parent[up] = vp;
        if (ranh[up] == ranh[vp]) ++ranh[up];

        ================================================================*/
        
        /* ================= Xét theo kích thước ============== 
        if (sz[up] < sz[vp]) swap(up, vp); // quy ước up luôn là gốc
        parent[up] = vp;
        sz[up] += sz[vp];
        
        =================================================================*/
 
        parent[up] = vp; // cơ bản
    }
}

int32_t main() 
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    
    return 0;
}