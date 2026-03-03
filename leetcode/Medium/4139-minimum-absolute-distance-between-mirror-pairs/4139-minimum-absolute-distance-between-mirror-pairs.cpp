/*
 Problem: 4139. Minimum Absolute Distance Between Mirror Pairs
 Language: cpp
 Runtime: 203 ms (42.49%)
 Memory: 135 MB (43.01%)
 Tags: Array, Hash Table, Math
*/
class Solution {
private:
    int reverse(int x) {
        int r = 0;
        while (x > 0) {
            r = r * 10 + (x % 10);
            x /= 10;
        }
        return r;
    }
    
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int ans = 1e9;
        map<int, int> mp;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (mp.count(nums[i])) {
                ans = min(ans, i - mp[nums[i]]);
            }

            mp[reverse(nums[i])] = i;
        }

        return ans == 1e9 ? -1 : ans;
    }
};