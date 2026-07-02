/*
 Problem: 3967. Earliest Finish Time for Land and Water Rides II
 Language: cpp
 Runtime: 3 ms (76.08%)
 Memory: 238.1 MB (37.42%)
 Tags: Array, Two Pointers, Binary Search, Greedy, Sorting
*/
class Solution {
    int solve(vector<int>& start1, vector<int>& duration1,
              vector<int>& start2, vector<int>& duration2) {
        int firstFinish = INT_MAX;

        for (int i = 0; i < start1.size(); ++i) {
            firstFinish = min(firstFinish, start1[i] + duration1[i]);
        }

        int answer = INT_MAX;

        for (int i = 0; i < start2.size(); ++i) {
            answer = min(answer, max(start2[i], firstFinish) + duration2[i]);
        }

        return answer;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int landFirst = solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int waterFirst = solve(waterStartTime, waterDuration, landStartTime, landDuration);

        return min(landFirst, waterFirst);
    }
};