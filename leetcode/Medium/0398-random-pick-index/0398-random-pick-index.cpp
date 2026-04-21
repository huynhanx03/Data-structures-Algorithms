/*
 Problem: 398. Random Pick Index
 Language: cpp
 Runtime: 1623 ms (17.55%)
 Memory: 50.5 MB (78.49%)
 Tags: Hash Table, Math, Reservoir Sampling, Randomized
*/
class Solution {
public:
    vector<int> a;

    Solution(vector<int>& nums) {
        a = nums;
    }
    
    int pick(int target) {
        int cnt = 0, ans = -1;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == target) {
                ++cnt;
                if (rand() % cnt == 0) ans = i;
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */