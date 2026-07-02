/*
 Problem: 3408. Count the Number of Special Characters I
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8.9 MB (82.44%)
 Tags: Hash Table, String
*/
class Solution {
public:
    int numberOfSpecialChars(string word) {
        bitset<27> A[2];
        for(char c: word){
            bool isLower=c&32;
            A[isLower][31&c]=1;
        }
        return (A[0]&A[1]).count();
    }
};