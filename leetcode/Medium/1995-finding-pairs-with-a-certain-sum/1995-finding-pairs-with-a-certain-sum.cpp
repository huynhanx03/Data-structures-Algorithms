/*
 Problem: 1995. Finding Pairs With a Certain Sum
 Language: cpp
 Runtime: 659 ms (6.65%)
 Memory: 194.4 MB (5.74%)
 Tags: Array, Hash Table, Design
*/
class FindSumPairs {
private:
    map<int, int> cnt;
    vector<int> n1, n2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (const auto& num : nums2) {
            ++cnt[num];
        }

        n1 = nums1;
        n2 = nums2;
    }
    
    void add(int index, int val) {
        --cnt[n2[index]];
        n2[index] += val;
        ++cnt[n2[index]];
    }
    
    int count(int tot) {
        int res = 0;
        
        for (const auto& num : n1) {
            res += cnt[tot - num];
        }        

        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */