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
        vector <string> ans;

        vector <int> cnt(26, 0);
        for (const auto& c : s) {
            ++cnt[c - 'a'];
        }

        auto generate = [&](auto self, int idx, string cur) -> void {
            if (idx == n) {
                ans.push_back(cur);
                return;
            }

            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > 0) {
                    --cnt[i];
                    self(self, idx + 1, cur + (char)('a' + i));
                    ++cnt[i];
                }
            }
        };

        generate(generate, 0, "");

        cout << ans.size() << '\n';
        for (const auto &x : ans) {
            cout << x << '\n';
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
