/*
 Problem: 759. Set Intersection Size At Least Two
 Language: cpp
 Runtime: 3 ms (74.12%)
 Memory: 21.6 MB (98.76%)
 Tags: Array, Greedy, Sorting
*/
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        int a = -1, b = -1;
        int count = 0;

        for (auto &in : intervals) {
            int L = in[0], R = in[1];

            bool aIn = (a >= L && a <= R);
            bool bIn = (b >= L && b <= R);

            if (aIn && bIn) continue;

            if (aIn) {
                count++;
                b = a;
                a = R;
            } else {
                count += 2;
                b = R - 1;
                a = R;
            }
        }

        return count;
    }
};