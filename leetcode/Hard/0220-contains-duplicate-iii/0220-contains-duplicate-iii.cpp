/*
 Problem: 220. Contains Duplicate III
 Language: cpp
 Runtime: 268 ms (9.45%)
 Memory: 147.5 MB (90.38%)
 Tags: Array, Sliding Window, Sorting, Bucket Sort, Ordered Set
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff,
                                       int valueDiff) {
        map<int, int> buckets;
        int bucketSize = valueDiff + 1;

        for (int i = 0; i < nums.size(); ++i) {
            int bucketKey = nums[i] / bucketSize;

            if (nums[i] < 0) {
                bucketKey--;
            }

            if (buckets.count(bucketKey)) {
                return true;
            }

            if (buckets.count(bucketKey - 1) &&
                abs(nums[i] - buckets[bucketKey - 1]) <= valueDiff) {
                return true;
            }
            if (buckets.count(bucketKey + 1) &&
                abs(nums[i] - buckets[bucketKey + 1]) <= valueDiff) {
                return true;
            }

            buckets[bucketKey] = nums[i];

            if (i >= indexDiff) {
                int bucketToRemove = nums[i - indexDiff] / bucketSize;
                if (nums[i - indexDiff] < 0) {
                    bucketToRemove--;
                }
                buckets.erase(bucketToRemove);
            }
        }

        return false;
    }
};