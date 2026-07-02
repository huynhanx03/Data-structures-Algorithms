/*
 Problem: 4216. Weighted Word Mapping
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 43.7 MB (27.94%)
 Tags: Array, String, Simulation
*/
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string answer;

        for (const auto& word : words) {
            int weight = 0;

            for (const auto ch : word) {
                weight += weights[ch - 'a'];
            }

            answer += 'z' - weight % 26;
        }

        return answer;
    }
};