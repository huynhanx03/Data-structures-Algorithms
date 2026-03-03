/*
 Problem: 2195. Time Needed to Buy Tickets
 Language: cpp
 Runtime: 5 ms (4.07%)
 Memory: 9.3 MB (100.00%)
 Tags: Array, Queue, Simulation
*/
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int sum = tickets[k];

        for (int i = 0; i < k; ++i) {
            sum += min(tickets[i], tickets[k]);
        }

        for (int i = k + 1; i < tickets.size(); ++i) {
            sum += min(tickets[i], tickets[k] - 1);
        }

        return sum;
    }
};