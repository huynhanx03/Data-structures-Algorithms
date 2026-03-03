/*
 Problem: 1460. Number of Substrings Containing All Three Characters
 Language: cpp
 Runtime: 3 ms (87.78%)
 Memory: 11.1 MB (56.58%)
 Tags: Hash Table, String, Sliding Window
*/
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> cnt(3, 0);
        int left = 0, n = s.size(), res = 0;

        for (int right = 0; right < n; ++right) {
            ++cnt[s[right] - 'a'];

            while (cnt[0] && cnt[1] && cnt[2]) {
                res += n - right;
                --cnt[s[left++] - 'a'];
            }
        }

        return res;
    }
};