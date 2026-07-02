/*
 Problem: 3965. Earliest Finish Time for Land and Water Rides I
 Language: cpp
 Runtime: 8 ms (37.36%)
 Memory: 96.7 MB (5.17%)
 Tags: Array, Two Pointers, Binary Search, Greedy, Sorting
*/
class Solution {
public:
    long long solve(vector<int>& start1, vector<int>& duration1,
                    vector<int>& start2, vector<int>& duration2) {
        vector<long long> finishTimes;

        for (int i = 0; i < start1.size(); ++i) {
            finishTimes.push_back(1LL * start1[i] + duration1[i]);
        }

        sort(finishTimes.begin(), finishTimes.end());

        vector<pair<int, int>> rides;

        for (int i = 0; i < start2.size(); ++i) {
            rides.push_back({start2[i], duration2[i]});
        }

        sort(rides.begin(), rides.end());

        int m = rides.size();

        vector<long long> minFutureFinish(m + 1, LLONG_MAX);

        for (int i = m - 1; i >= 0; --i) {
            minFutureFinish[i] = min(
                minFutureFinish[i + 1],
                1LL * rides[i].first + rides[i].second
            );
        }

        long long answer = LLONG_MAX;
        long long minOpenedDuration = LLONG_MAX;

        int rideIndex = 0;

        for (long long finishTime : finishTimes) {
            while (rideIndex < m && rides[rideIndex].first <= finishTime) {
                minOpenedDuration = min(
                    minOpenedDuration,
                    1LL * rides[rideIndex].second
                );

                ++rideIndex;
            }

            if (minOpenedDuration != LLONG_MAX) {
                answer = min(
                    answer,
                    finishTime + minOpenedDuration
                );
            }

            if (rideIndex < m) {
                answer = min(
                    answer,
                    minFutureFinish[rideIndex]
                );
            }
        }

        return answer;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        long long landFirst = solve(
            landStartTime,
            landDuration,
            waterStartTime,
            waterDuration
        );

        long long waterFirst = solve(
            waterStartTime,
            waterDuration,
            landStartTime,
            landDuration
        );

        return static_cast<int>(min(landFirst, waterFirst));
    }
};