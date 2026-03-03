/*
 Problem: 4138. Minimum Deletion Cost to Make All Characters Equal
 Language: cpp
 Runtime: 23 ms (17.70%)
 Memory: 115.4 MB (7.48%)
 Tags: Array, Hash Table, String, Enumeration
*/
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        int n = s.size();

        long long ans = 0;

        vector <long long> cnt(26, 0);
        set<int> st;

        for (int i = 0; i < n; ++i) {
            cnt[s[i] - 'a'] += 1ll * cost[i];
            st.insert(s[i] - 'a');
        }

        sort(cnt.begin(), cnt.end(), greater<long long>());

        for (int i = 1; i < st.size(); ++i) {
            ans += cnt[i];    
        }
        
        return ans;
    }
};