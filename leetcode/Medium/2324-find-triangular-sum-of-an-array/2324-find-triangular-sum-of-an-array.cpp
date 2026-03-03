/*
 Problem: 2324. Find Triangular Sum of an Array
 Language: cpp
 Runtime: 36 ms (96.48%)
 Memory: 23.7 MB (44.71%)
 Tags: Array, Math, Simulation, Combinatorics, Number Theory
*/
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> C(n,0);
        C[0]=1;
        for(int k=1;k<=n-1;k++){
            for(int j=k;j>=1;j--){
                C[j]=(C[j]+C[j-1])%10;
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            res=(res+C[i]*nums[i])%10;
        }
        return res;
    }
};
