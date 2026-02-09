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

        long long s = 0;
        vector <int> a(n);
        for (auto& x : a) {
            cin >> x;
            s += x;
        }

        long long ans = LLONG_MAX;

        auto dfs = [&](auto self, int idx, long long cur) -> void {
            if (idx == n) {
                ans = min(ans, abs(s - 2 * cur));
                return;
            }

            self(self, idx + 1, cur + a[idx]);
            self(self, idx + 1, cur);
        };
        
        dfs(dfs, 0, 0);

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
