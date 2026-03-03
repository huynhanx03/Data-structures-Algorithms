/*
 Problem: 3430. Count Days Without Meetings
 Language: cpp
 Runtime: 71 ms (49.28%)
 Memory: 126.5 MB (57.58%)
 Tags: Array, Sorting
*/
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        int freeDays = 0;
        int lastEnd = 0;

        for (const auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            if (start > lastEnd + 1) {
                freeDays += (start - lastEnd - 1);
            }

            lastEnd = max(lastEnd, end);
        }

        if (lastEnd < days) {
            freeDays += (days - lastEnd);
        }

        return freeDays;
    }
};