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

        vector <int> cnt(26, 0);
        for (const auto& c : s) {
            ++cnt[c - 'A'];
        }

        int n = s.size();
        if (*max_element(cnt.begin(), cnt.end()) > (n + 1) / 2) {
            cout << -1;
            return;
        }

        string ans = "";
        int prev = -1;

        for (int pos = 0; pos < n; ++pos) {
            for (int c = 0; c < 26; ++c) {
                if (cnt[c] == 0) continue;
                if (prev != -1 && c == prev) continue;

                --cnt[c];

                int rem = n - pos - 1;
                int mx = *max_element(cnt.begin(), cnt.end());

                if (mx <= (rem + 1) / 2) {
                    ans += char(c + 'A');
                    prev = c;
                    break;
                }

                ++cnt[c];
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
