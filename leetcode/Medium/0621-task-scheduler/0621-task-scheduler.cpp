/*
 Problem: 621. Task Scheduler
 Language: cpp
 Runtime: 35 ms (38.38%)
 Memory: 47.7 MB (30.87%)
 Tags: Array, Hash Table, Greedy, Sorting, Heap (Priority Queue), Counting
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Count the frequency of each task
        unordered_map<char, int> task_count;
        for (char task : tasks) {
            task_count[task]++;
        }

        // Max heap to store task frequencies
        priority_queue<int> pq;
        for (auto& [task, count] : task_count) {
            pq.push(count);
        }

        int intervals = 0;
        while (!pq.empty()) {
            vector<int> temp;
            int count = 0;
            
            // Process the tasks for the current interval
            for (int i = 0; i <= n; ++i) {
                if (!pq.empty()) {
                    temp.push_back(pq.top());
                    pq.pop();
                    count++;
                }
            }

            for (int freq : temp) {
                if (--freq > 0) {
                    pq.push(freq);
                }
            }

            intervals += !pq.empty() ? n + 1 : count;
        }

        return intervals;
    }
};