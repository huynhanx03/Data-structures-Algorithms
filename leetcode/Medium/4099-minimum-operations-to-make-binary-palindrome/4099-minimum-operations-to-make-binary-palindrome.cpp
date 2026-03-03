/*
 Problem: 4099. Minimum Operations to Make Binary Palindrome
 Language: cpp
 Runtime: 283 ms (58.03%)
 Memory: 44.7 MB (82.93%)
 Tags: Array, Two Pointers, Binary Search, Bit Manipulation
*/
class Solution {
private:
    bool isOke(long long x) {
        string s;
        while (x > 0) {
            s.push_back((x & 1) + '0');
            x >>= 1;
        }

        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return 0;
            ++l;
            --r;
        }

        return 1;
    }
public:
    vector<int> minOperations(vector<int>& nums) {
        vector<int> ans;

        for (const auto& x : nums) {
            int d = 0;
            while (1) {
                int a = x - d;
                int b = x + d;
    
                if (a >= 1 && isOke(a)) {
                    ans.push_back(d);
                    break;
                }
    
                if (isOke(b)) {
                    ans.push_back(d);
                    break;
                }
                ++d;
            }
                
        }
        
        return ans;
    }
};