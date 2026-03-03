/*
 Problem: 3483. Alternating Groups II
 Language: cpp
 Runtime: 70 ms (60.36%)
 Memory: 102.6 MB (95.50%)
 Tags: Array, Sliding Window
*/
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size(), count = 0, start = 0;

        for (int end = 0; end < n + k - 1; ++end) {
            if (end > 0 && colors[end % n] == colors[(end - 1) % n]) {
                start = end;
            }

            if (end - start + 1 >= k) {
                ++count;
                start++;
            }
        }
        
        return count;
    }
};
