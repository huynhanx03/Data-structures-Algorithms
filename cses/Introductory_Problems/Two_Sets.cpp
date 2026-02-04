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

        if (n % 4 == 1 || n % 4 == 2) {
            cout << "NO\n";
            return;
        }
        
        cout << "YES\n";
        vector<int> a, b;

        if (n % 4 == 0) {
            for (int i = 1; i <= n; i += 4) {
                a.push_back(i);
                a.push_back(i + 3);
                b.push_back(i + 1);
                b.push_back(i + 2);
            }
        } else {
            a.push_back(1);
            a.push_back(2);
            b.push_back(3);
            for (int i = 4; i <= n; i += 4) {
                a.push_back(i);
                a.push_back(i + 3);
                b.push_back(i + 1);
                b.push_back(i + 2);
            }
        }

        auto print = [](const vector<int>& v) {
            cout << v.size() << "\n";
            for (int x : v) cout << x << " ";
            cout << "\n";
        };

        print(a);
        print(b);
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
