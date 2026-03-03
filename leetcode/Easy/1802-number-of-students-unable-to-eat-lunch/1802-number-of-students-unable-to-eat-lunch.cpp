/*
 Problem: 1802. Number of Students Unable to Eat Lunch
 Language: cpp
 Runtime: 5 ms (1.72%)
 Memory: 10.7 MB (100.00%)
 Tags: Array, Stack, Queue, Simulation
*/
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int d[2] = {0, 0};

        for (auto& student: students)
            ++d[student];

        int n = sandwiches.size();

        for (int i = 0; i < n; ++i)
            if (d[sandwiches[i]] > 0) --d[sandwiches[i]];
            else 
                return n - i;

        return 0;
    }
};