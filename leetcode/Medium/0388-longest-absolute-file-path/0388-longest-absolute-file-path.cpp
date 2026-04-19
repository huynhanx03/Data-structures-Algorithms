/*
 Problem: 388. Longest Absolute File Path
 Language: cpp
 Runtime: 2 ms (12.72%)
 Memory: 9.5 MB (17.81%)
 Tags: String, Stack, Depth-First Search
*/
class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> pathLen(input.size() + 1, 0); 
        int ans = 0;
        int i = 0, n = input.size();

        while (i < n) {
            int depth = 0;

            while (i < n && input[i] == '\t') {
                ++depth;
                ++i;
            }

            int start = i;
            bool isFile = false;

            while (i < n && input[i] != '\n') {
                if (input[i] == '.') isFile = true;
                i++;
            }

            int nameLen = i - start;

            if (isFile) {
                ans = max(ans, pathLen[depth] + nameLen);
            } else {
                pathLen[depth + 1] = pathLen[depth] + nameLen + 1; 
            }

            ++i;
        }

        return ans;
    }
};