class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int last = INT_MIN;
        int res = 0;
        for (int x : nums) {
            int candidate = max(last + 1, x - k);
            if (candidate <= x + k) {
                res++;
                last = candidate;
            }
        }
        return res;
    }
};