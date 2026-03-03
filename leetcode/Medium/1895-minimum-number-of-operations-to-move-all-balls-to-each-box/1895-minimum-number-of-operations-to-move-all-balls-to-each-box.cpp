/*
 Problem: 1895. Minimum Number of Operations to Move All Balls to Each Box
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 12 MB (84.68%)
 Tags: Array, String, Prefix Sum
*/
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> result(n, 0);
        int countLeft = 0, countRight = 0, operationsLeft = 0, operationsRight = 0;

        for (int i = 0; i < n; ++i) {
            result[i] += operationsLeft;
            countLeft += boxes[i] == '1' ? 1 : 0;
            operationsLeft += countLeft;

            result[n - 1 - i] += operationsRight;
            countRight += boxes[n - 1 - i] == '1' ? 1 : 0;
            operationsRight += countRight;
        }

        return result;
    }
};
