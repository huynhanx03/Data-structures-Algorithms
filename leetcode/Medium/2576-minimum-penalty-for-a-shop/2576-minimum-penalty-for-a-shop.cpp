/*
 Problem: 2576. Minimum Penalty for a Shop
 Language: cpp
 Runtime: 5 ms (71.37%)
 Memory: 13.3 MB (84.59%)
 Tags: String, Prefix Sum
*/
class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = 0;
        for (char c : customers) {
            if (c == 'Y') penalty++;
        }

        int minPenalty = penalty;
        int bestHour = 0;

        for (int i = 0; i < customers.size(); i++) {
            if (customers[i] == 'Y') {
                penalty--;
            } else {
                penalty++;
            }

            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = i + 1;
            }
        }

        return bestHour;
    }
};
