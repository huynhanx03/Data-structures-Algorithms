#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#include <limits>
#include <numeric>
#include <functional>
#include <tuple>
#include <utility>
#include <bitset>
#include <sstream>
#include <iomanip>
 
using namespace std;
 
#define nhan43                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);
 
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
public:
    long long countingBits(long long n) {
        long long count = 0;
        long long bit = 0;
        while ((1LL << bit) <= n) {
            long long cycle = 1LL << (bit + 1);
            long long completeCycles = n / cycle;
            count += completeCycles * (1LL << bit);
            long long remainder = n % cycle;
            if (remainder >= (1LL << bit)) {
                count += remainder - (1LL << bit) + 1;
            }
            bit++;
        }
 
        return count;
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
        long long n;
        cin >> n;
        cout << sol.countingBits(n) << "\n";
    }
 
    return 0;
}