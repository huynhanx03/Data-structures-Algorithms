/*
 Problem: 3019. Furthest Point From Origin
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 9.2 MB (30.54%)
 Tags: String, Counting
*/
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cnt = 0;
        int ans = 0;

        for (const auto& c : moves) {
            if (c == '_') ++cnt;
            else ans += (c == 'L' ? -1 : 1);
        }

        return max(abs(ans + cnt), abs(ans - cnt));
    }
};