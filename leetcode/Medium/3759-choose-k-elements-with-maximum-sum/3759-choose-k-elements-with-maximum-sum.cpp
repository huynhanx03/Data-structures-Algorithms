/*
 Problem: 3759. Choose K Elements With Maximum Sum
 Language: cpp
 Runtime: 112 ms (58.23%)
 Memory: 159.5 MB (100.00%)
 Tags: Array, Sorting, Heap (Priority Queue)
*/
class Solution
{
private:
    struct Pair
    {
        int nums1;
        int nums2;
        int index;
        Pair(int n1, int n2, int i) : nums1(n1), nums2(n2), index(i) {}
    };

public:
    vector<long long> findMaxSum(vector<int> &nums1, vector<int> &nums2,
                                 int k)
    {

        int n = nums1.size();

        vector<Pair> sorted_pairs;
        for (int i = 0; i < n; ++i)
        {
            sorted_pairs.emplace_back(nums1[i], nums2[i], i);
        }
        sort(sorted_pairs.begin(), sorted_pairs.end(),
             [](const Pair &a, const Pair &b)
             {
                 if (a.nums1 == b.nums1)
                     return a.nums2 < b.nums2;

                 return a.nums1 < b.nums1;
             });

        vector<long long> answer(n, 0);
        long long total = 0;     
        priority_queue<int, vector<int>, greater<int>> pq;
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            if (i > 0 && sorted_pairs[i].nums1 == sorted_pairs[i - 1].nums1) {
                answer[sorted_pairs[i].index] = answer[sorted_pairs[i - 1].index];
            } else {
                answer[sorted_pairs[i].index] = total;
            }
            
            total += sorted_pairs[i].nums2;
            pq.push(sorted_pairs[i].nums2);
            ++cnt;

            if (cnt > k) {
                total -= pq.top();
                pq.pop();
                --cnt;
            }
        }

        return answer;
    }
};