/*
 Problem: 4281. Score Validator
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 53.6 MB (95.95%)
 Tags: Array, String, Simulation
*/
class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        vector<int> ans(2, 0);

        for (const auto& e : events) {
            if (e == "W") {
                ++ans[1];
            } else if (e == "WD" || e == "NB") {
                ++ans[0];
            } else {
                ans[0] += e[0] - '0';
            }

            if (ans[1] == 10) break;
        }

        return ans;
    }
};