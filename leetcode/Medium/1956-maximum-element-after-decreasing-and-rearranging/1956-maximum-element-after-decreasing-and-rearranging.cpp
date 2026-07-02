/*
 Problem: 1956. Maximum Element After Decreasing and Rearranging
 Language: cpp
 Runtime: 7 ms (64.12%)
 Memory: 55.2 MB (75.67%)
 Tags: Array, Greedy, Sorting
*/
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        arr[0] = 1;

        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > arr[i - 1] + 1) {
                arr[i] = arr[i - 1] + 1;
            }
        }

        return arr.back();
    }
};