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
        
        if (n == 1) {
            cout << "1";
            return;
        }

        if (n <= 3) {
            cout << "NO SOLUTION";
            return;
        }

        for (int i = 2; i <= n; i += 2) cout << i << " ";
        for (int i = 1; i <= n; i += 2) cout << i << " ";
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
        // INPUT
        sol.sol();
    }
    return 0;
}
