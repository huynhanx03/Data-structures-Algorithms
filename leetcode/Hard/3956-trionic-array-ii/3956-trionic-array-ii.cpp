/*
 Problem: 3956. Trionic Array II
 Language: cpp
 Runtime: 10 ms (49.10%)
 Memory: 153.3 MB (40.10%)
 Tags: Array, Dynamic Programming
*/
class Solution {
public:
    long long maxSumTrionic(vector<int>& a) {
        int n = a.size();
        
        vector<long long> inc(n, -1e18), dec(n, -1e18);

        long long ans = -1e18;
        for(int i = 0; i < n; i++) {
            inc[i] = a[i];
            if(i && a[i] > a[i - 1]) 
                inc[i] = max((long long) a[i - 1] + a[i], inc[i - 1] + a[i]);
        }

        for(int i = n - 1; i >= 0; i--) {
            dec[i] = a[i];
            if(i < n - 1 && a[i] < a[i + 1]) 
                dec[i] = max((long long) a[i] + a[i + 1], dec[i + 1] + a[i]);
        }

        for(int i = 1; i < n - 1; i++) {
            if(a[i] > a[i - 1] && a[i] > a[i + 1]) {
                int j = i;  //i is peak
                long long sum = 0;

                while(j < n - 1 && a[j] > a[j + 1]) sum += a[j++];
                if(j < n - 1 && a[j] < a[j + 1]) //j is now valley
                    ans = max(ans, inc[i] - a[i] + sum + dec[j]);

                i = j;
            }
        }

        return ans;
    }
};