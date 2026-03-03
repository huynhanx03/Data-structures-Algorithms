/*
 Problem: 215. Kth Largest Element in an Array
 Language: cpp
 Runtime: 27 ms (68.42%)
 Memory: 59.3 MB (86.81%)
 Tags: Array, Divide and Conquer, Sorting, Heap (Priority Queue), Quickselect
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        buildHeap(nums);

        for (int i = 0; i < k - 1; ++i) {
            swap(nums[0], nums[--sizeHeap]);            
            heapify(nums, 0);
        }

        return nums[0];
    }

private:
    int sizeHeap;

    int left(int i) {
        return (i << 1) + 1;
    }

    int right(int i) {
        return (i << 1) + 2;
    }

    void heapify(vector<int>& nums, int i) {
        int l = left(i);
        int r = right(i);

        int cur = i;

        if (l < sizeHeap && nums[l] > nums[cur]) {
            cur = l;
        }

        if (r < sizeHeap && nums[r] > nums[cur]) {
            cur = r;
        }

        if (cur != i) {
            swap(nums[cur], nums[i]);
            heapify(nums, cur);
        }
    }

    void buildHeap(vector<int>& nums) {
        sizeHeap = nums.size();

        for (int i = (sizeHeap >> 1) - 1; i >= 0; --i) {
            heapify(nums, i);
        }
    } 
};