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
public:
    void sol()
    {
        int n;
        cin >> n;

        vector<vector<int>> ans(n, vector<int>(n, -1));
        queue<pair<int,int>> q;
        
        const int dx[] = {1,2,2,1,-1,-2,-2,-1};
        const int dy[] = {2,1,-1,-2,-2,-1,1,2};

        ans[0][0] = 0;
        q.push({0, 0});

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (ans[nx][ny] != -1) continue;

                ans[nx][ny] = ans[x][y] + 1;
                q.push({nx, ny});
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    };
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
