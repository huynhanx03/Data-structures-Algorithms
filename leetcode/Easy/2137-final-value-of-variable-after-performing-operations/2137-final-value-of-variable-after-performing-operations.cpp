/*
 Problem: 2137. Final Value of Variable After Performing Operations
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 17.6 MB (42.40%)
 Tags: Array, String, Simulation
*/
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;

        for (const auto& ope : operations) {
            res = res + (ope[1] == '+' ? 1 : -1);
        }

        return res;
    }
};