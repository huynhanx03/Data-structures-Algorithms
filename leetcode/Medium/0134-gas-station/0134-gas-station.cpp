/*
 Problem: 134. Gas Station
 Language: cpp
 Runtime: 69 ms (5.18%)
 Memory: 111.3 MB (99.96%)
 Tags: Array, Greedy
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int idx = 0;
        int sum = 0;
        int current = 0;

        for (int i = 0; i < gas.size(); ++i) {
            int tmp = gas[i] - cost[i];

            current += tmp;

            if (current < 0) {
                current = 0;
                idx = i + 1;
            }

            sum += tmp;
        }

        return sum >= 0 ? idx : -1; 

    }
};