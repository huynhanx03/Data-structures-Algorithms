/*
 Problem: 3794. Find the Minimum Amount of Time to Brew Potions
 Language: cpp
 Runtime: 101 ms (93.29%)
 Memory: 45.3 MB (77.32%)
 Tags: Array, Simulation, Prefix Sum
*/
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        using ll = long long;
        int n = skill.size(), m = mana.size();
        vector<ll> prefix(n, 0);
        for (int i = 1; i < n; ++i)
            prefix[i] = prefix[i - 1] + skill[i];

        ll total = 1LL * skill[0] * mana[0];
        for (int j = 1; j < m; ++j) {
            ll mx = 1LL * skill[0] * mana[j];
            for (int i = 1; i < n; ++i) {
                ll diff = prefix[i] * mana[j - 1] - prefix[i - 1] * mana[j];
                if (diff > mx) mx = diff;
            }
            total += mx;
        }
        return total + prefix.back() * mana.back();
    }
};
