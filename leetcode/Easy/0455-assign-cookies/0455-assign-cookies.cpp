/*
 Problem: 455. Assign Cookies
 Language: cpp
 Runtime: 28 ms (5.40%)
 Memory: 17.4 MB (100.00%)
 Tags: Array, Two Pointers, Greedy, Sorting
*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ns=s.size(),ng=g.size(),ds=0,dg=0,ans=0;
        while (ds<ns && dg<ng) {
            if (s[ds]>=g[dg]) {
                ++ans;
                ++dg;
            }
            ++ds;
        }
        return ans;
    }
};