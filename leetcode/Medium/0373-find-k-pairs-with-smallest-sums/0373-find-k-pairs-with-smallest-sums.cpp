/*
 Problem: 373. Find K Pairs with Smallest Sums
 Language: cpp
 Runtime: 31 ms (96.48%)
 Memory: 136.1 MB (55.13%)
 Tags: Array, Heap (Priority Queue)
*/
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> result;
        if (nums1.empty() || nums2.empty() || k == 0)
            return {};

        for (int i = 0; i < nums1.size() && i < k; ++i) {
            addHeap(nums1, nums2, {i, 0});
        }

        for (int i = 0; i < k && !heap.empty(); ++i) {
            auto key = heap[0];
            popHeap(nums1, nums2);

            result.push_back(key);
            
            if (key.second + 1 < nums2.size()) {
                addHeap(nums1, nums2, {key.first, key.second + 1});
            }
        }

        vector<vector<int>> ret;
        for (const auto& p : result) {
            ret.push_back({nums1[p.first], nums2[p.second]});
        }

        return ret;
    }

private:
    vector<pair<int, int>> heap;

    bool compare(vector<int>& nums1, vector<int>& nums2, pair<int, int>& a, pair<int, int>& b) {
        return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
    }

    int sizeHeap;

    int parent(int i) { return (i - 1) >> 1; }

    int left(int i) { return (i << 1) + 1; }

    int right(int i) { return (i << 1) + 2; }

    void heapify(vector<int>& nums1, vector<int>& nums2, int i) {
        int l = left(i);
        int r = right(i);

        int cur = i;

        if (l < sizeHeap && compare(nums1, nums2, heap[cur], heap[l])) {
            cur = l;
        }

        if (r < sizeHeap && compare(nums1, nums2, heap[cur], heap[r])) {
            cur = r;
        }

        if (cur != i) {
            swap(heap[cur], heap[i]);
            heapify(nums1, nums2, cur);
        }
    }

    void addHeap(vector<int>& nums1, vector<int>& nums2, pair<int, int> p) {
        heap.push_back(p);
        sizeHeap = heap.size();
        int i = sizeHeap - 1;
        while (i > 0 && compare(nums1, nums2, heap[parent(i)], heap[i])) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void popHeap(vector<int>& nums1, vector<int>& nums2) {
        swap(heap[0], heap[--sizeHeap]);
        heapify(nums1, nums2, 0);
        heap.pop_back();
    }
};
