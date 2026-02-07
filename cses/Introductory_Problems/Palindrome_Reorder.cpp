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
        string s;
        cin >> s;
        
        int n = s.size();
        string ans(n, '.');

        vector <int> cnt(26, 0);
        for (const char& c : s) {
            ++cnt[c - 'A'];
        }

        int odd = -1;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] & 1) {
                if (odd == -1) {
                    odd = i;
                    --cnt[i];
                }
                else {
                    cout << "NO SOLUTION\n";
                    return;
                }
            }
        }

        if (odd != -1) {
            ans[n / 2] = 'A' + odd;
        }

        int l = 0, r = n - 1;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < cnt[i] / 2; ++j) {
                ans[l++] = ans[r--] = 'A' + i;
            }
        }

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
