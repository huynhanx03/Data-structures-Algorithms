#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#include <numeric>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define nhan43                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void fastIO()
{
    nhan43;
    if (fopen("main.inp", "r"))
    {
        freopen("main.inp", "r", stdin);
        freopen("main.out", "w", stdout);
    }
}

class Solution
{
    bool vis[9][9];
    int p[48];
    int ans = 0;

public:
    void dfs(int r, int c, int idx)
    {
        if (r == 7 && c == 1)
        {
            if (idx == 48) ans++;
            return;
        }

        if (vis[r][c - 1] && vis[r][c + 1] && !vis[r - 1][c] && !vis[r + 1][c]) return;
        if (vis[r - 1][c] && vis[r + 1][c] && !vis[r][c - 1] && !vis[r][c + 1]) return;

        vis[r][c] = true;

        if (p[idx] < 4)
        {
            int nr = r, nc = c;
            if (p[idx] == 0) nr--; // U
            else if (p[idx] == 1) nr++; // D
            else if (p[idx] == 2) nc--; // L
            else nc++; // R

            if (!vis[nr][nc]) dfs(nr, nc, idx + 1);
        }
        else
        {
            if (!vis[r - 1][c]) dfs(r - 1, c, idx + 1); // U
            if (!vis[r + 1][c]) dfs(r + 1, c, idx + 1); // D
            if (!vis[r][c - 1]) dfs(r, c - 1, idx + 1); // L
            if (!vis[r][c + 1]) dfs(r, c + 1, idx + 1); // R
        }

        vis[r][c] = false;
    }

    void sol()
    {
        string s;
        cin >> s;

        for (int i = 0; i < 48; i++)
        {
            if (s[i] == 'U') p[i] = 0;
            else if (s[i] == 'D') p[i] = 1;
            else if (s[i] == 'L') p[i] = 2;
            else if (s[i] == 'R') p[i] = 3;
            else p[i] = 4;
        }

        for (int i = 0; i < 9; i++)
        {
            vis[i][0] = true;
            vis[i][8] = true;
            vis[0][i] = true;
            vis[8][i] = true;
        }

        for (int i = 1; i <= 7; i++)
        {
            for (int j = 1; j <= 7; j++)
            {
                vis[i][j] = false;
            }
        }

        dfs(1, 1, 0);
        cout << ans << endl;
    }
};

int main()
{
    fastIO();
    int tc = 1;
    // cin >> tc;
    Solution sol;
    while (tc--)
    {
    sol.sol();
    }
    return 0;
}
