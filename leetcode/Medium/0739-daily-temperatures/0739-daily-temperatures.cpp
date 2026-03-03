/*
 Problem: 739. Daily Temperatures
 Language: cpp
 Runtime: 114 ms (5.32%)
 Memory: 110.1 MB (11.15%)
 Tags: Array, Stack, Monotonic Stack
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> st;
        vector<int> ans(n, 0);

        for (int i = 0; i < n; ++i) {
            int value = temperatures[i];

            while (!st.empty()) {
                int x = st.top().first;
                int pos = st.top().second;

                if (value > x) {
                    st.pop();
                    ans[pos] = i - pos;
                } else 
                    break;
            }

            st.push({value, i});
        }

        return ans;
    }
};