/*
 Problem: 2888. Minimum Index of a Valid Split
 Language: cpp
 Runtime: 53 ms (23.60%)
 Memory: 103.1 MB (7.30%)
 Tags: Array, Hash Table, Sorting
*/
class Solution {
private:
    bool isDominant(unordered_map<int, int>& countMap, int total,
                    int candidate) {
        return countMap[candidate] > total / 2;
    }

public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> totalCount;
        for (int num : nums) {
            ++totalCount[num];
        }

        int dominant = -1;
        for (auto& pair : totalCount) {
            if (pair.second > n / 2) {
                dominant = pair.first;
                break;
            }
        }
        if (dominant == -1)
            return -1;

        unordered_map<int, int> leftCount;

        int leftSize = 0;
        for (int i = 0; i < n - 1; ++i) {
            ++leftCount[nums[i]];
            ++leftSize;
            
            if (!isDominant(leftCount, leftSize, dominant))
                continue;

            int rightSize = n - leftSize;
            int rightDominantCount = totalCount[dominant] - leftCount[dominant];
            if (rightDominantCount > rightSize / 2) {
                return i;
            }
        }
        return -1;
    }
};