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

class Solution {
    vector<pair<int,int>> moves;

    void move(int n, int from, int mid, int to) {
        if (n == 0) return;
        move(n - 1, from, to, mid);
        moves.emplace_back(from, to);
        move(n - 1, mid, from, to);
    }

public:
    void sol() {
        int n;
        cin >> n;

        move(n, 1, 2, 3);

        cout << moves.size() << '\n';
        for (const auto &m : moves) {
            cout << m.first << " " << m.second << '\n';
        }
    }
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
