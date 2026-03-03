/*
 Problem: 4048. Minimum Time to Complete All Deliveries
 Language: cpp
 Runtime: 15 ms (5.04%)
 Memory: 54.8 MB (7.96%)
 Tags: Math, Binary Search
*/
typedef long long ll;

class Solution {
private:
    ll lcmll(ll a, ll b) {
        return a / gcd(a, b) * b;
    }
    
    bool canFinish(ll t, vector<int>& d, vector<int>& r) {
        int n = 2;
        vector<ll> w(n);
        ll bc = t / lcmll(r[0], r[1]);
        ll qw = 0, qd = 0; 
        ll av = t - bc;
        for (int i = 0; i < n; ++i) {
            w[i] = t - t / r[i];
            w[i] = min(w[i], 1LL * d[i]);
            qw += w[i];
            qd += d[i];
        }
        
        return (w[0] >= d[0] && w[1] >= d[1] && min(av, qw) >= d[0] + d[1]);
    }
    
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        ll l = 0, h = 1e18;
        ll ans = h;

        while (l <= h) {
            ll mid = l + (h - l) / 2;

            if (canFinish(mid, d, r)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};