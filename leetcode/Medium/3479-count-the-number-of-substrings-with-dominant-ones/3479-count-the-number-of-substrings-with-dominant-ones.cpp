/*
 Problem: 3479. Count the Number of Substrings With Dominant Ones
 Language: cpp
 Runtime: 72 ms (95.70%)
 Memory: 16.8 MB (90.13%)
 Tags: String, Enumeration
*/
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> c1(1, 0); 
        int ans = 0;
        int zero = 0, one = 0;

        for (char c : s) {
            if (c == '1') one++;
            else { zero++; c1.push_back(one); }

            ans += one - c1[zero];

            for (int prevZero = zero - 1; prevZero >= 0; prevZero--) {
                int num0 = zero - prevZero;
                int need = num0 * num0;

                if (need > one) break;

                int hi = one - c1[prevZero];
                int lo = one - c1[prevZero + 1];

                if (hi < need) continue;

                ans += hi - max(lo, need) + 1;
            }
        }

        return ans;
    }
};