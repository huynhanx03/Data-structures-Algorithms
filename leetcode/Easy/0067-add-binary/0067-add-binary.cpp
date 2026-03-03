/*
 Problem: 67. Add Binary
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8.9 MB (82.65%)
 Tags: Math, String, Bit Manipulation, Simulation
*/
class Solution {
public:
    string addBinary(string a, string b) {
        int pa = a.size() - 1;
        int pb = b.size() - 1;
        string ans = "";
        int carry = 0;

        while (pa >= 0 || pb >= 0 || carry) {
            int sum = carry;
            if (pa >= 0)
                sum += a[pa--] - '0';
            if (pb >= 0)
                sum += b[pb--] - '0';
            ans += (sum % 2) + '0';
            carry = sum / 2;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};