/*
 Problem: 3811. Reverse Degree of a String
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 9.7 MB (48.89%)
 Tags: String, Simulation
*/
class Solution {
public:
    int reverseDegree(string s) {
        int cnt = 0;

        for (int i = 0; i < s.size(); ++i) {
            cnt += (26 - (s[i] - 'a')) * (i + 1);
        }
        
        return cnt;
    }
};