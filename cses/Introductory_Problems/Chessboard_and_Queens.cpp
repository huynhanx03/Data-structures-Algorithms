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
        vector <string> board(8);
        for (auto& x : board) {
            cin >> x;
        }

        int ans = 0;
        
        vector<int> col(8, 0);
        vector<int> diag1(15, 0);
        vector<int> diag2(15, 0);

        auto dfs = [&](auto self, int i) -> void {
            if (i == 8) {
                ++ans;
                return;
            }

            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == '*' || col[j] || diag1[i + j] || diag2[i - j + 7]) continue;
                
                col[j] = diag1[i + j] = diag2[i - j + 7] = 1;
                self(self, i + 1);
                col[j] = diag1[i + j] = diag2[i - j + 7] = 0;
            }
        };

        dfs(dfs, 0);

        cout << ans << '\n';
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
