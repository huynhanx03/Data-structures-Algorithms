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
        long long k;
        cin >> k;

        long long d = 1;
        long long cnt = 9;
        long long start = 1;

        while (k > cnt * d) {
            k -= cnt * d;
            d++;
            cnt *= 10;
            start *= 10;
        }

        long long idx = (k - 1) / d;
        long long num = start + idx;

        int digit = (k - 1) % d;
        string s = to_string(num);

        cout << s[digit] << '\n';
    };
};

int main()
{
    fastIO();
    int tc = 1;
    cin >> tc;
    Solution sol;
    while (tc--)
    {
        sol.sol();
    }
    return 0;
}
