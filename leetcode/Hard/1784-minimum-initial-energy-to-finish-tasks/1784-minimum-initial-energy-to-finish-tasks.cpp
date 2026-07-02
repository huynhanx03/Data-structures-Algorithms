/*
 Problem: 1784. Minimum Initial Energy to Finish Tasks
 Language: cpp
 Runtime: 31 ms (80.22%)
 Memory: 97.4 MB (70.30%)
 Tags: Array, Greedy, Sorting
*/
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](auto& a, auto& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int ans = 0;
        int energy = 0;

        for (auto& task : tasks) {
            int actual = task[0];
            int minimum = task[1];

            if (energy < minimum) {
                ans += minimum - energy;
                energy = minimum;
            }

            energy -= actual;
        }

        return ans;
    }
};