/*
 Problem: 745. Find Smallest Letter Greater Than Target
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 19.7 MB (87.32%)
 Tags: Array, Binary Search
*/
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int pos = 0;
        for (int i = 0; i < letters.size(); ++i) {
            if (letters[i] > target) {
                pos = i;
                break;
            }
        }

        return letters[pos];
    }
};