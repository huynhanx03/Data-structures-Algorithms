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
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (auto& x : grid) cin >> x;
    
        vector<vector<char>> s(n, vector<char>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i + j) & 1) {
                    s[i][j] = grid[i][j] == 'A' ? 'B' : 'A';
                } else {
                    s[i][j] = grid[i][j] == 'C' ? 'D' : 'C';
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << s[i][j];
            }
            cout << '\n';
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
