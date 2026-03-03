/*
 Problem: 3834. Minimum Operations to Convert All Elements to Zero
 Language: cpp
 Runtime: 29 ms (63.64%)
 Memory: 222.2 MB (36.18%)
 Tags: Array, Hash Table, Stack, Greedy, Monotonic Stack
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int ans = 0;
        for (const auto& num : nums) {
            while (!st.empty()) {
                int top = st.top();
                if (top > num) {
                    ++ans;
                    st.pop();
                }
                if (top == num)
                    st.pop();
                if (top < num)
                    break;
            }
            st.push(num);
        }
        while (!st.empty()) {
            int top = st.top();
            st.pop();
            if (top != 0)
                ++ans;
        }
        return ans;
    }
};