/*
 Problem: 3493. Maximum Number of Operations to Move Ones to the End
 Language: cpp
 Runtime: 4 ms (71.28%)
 Memory: 15.9 MB (22.56%)
 Tags: String, Greedy, Counting
*/
class Solution {
public:
    int maxOperations(string s) {
        int ones = 0, ans = 0;
        int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++ones;
            } else if (i == n - 1 || s[i + 1] == '1') {
                ans += ones;
            }
        }
        return ans;
    }
};