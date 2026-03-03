/*
 Problem: 12. Integer to Roman
 Language: cpp
 Runtime: 6 ms (33.20%)
 Memory: 10.1 MB (68.56%)
 Tags: Hash Table, Math, String
*/
class Solution {
public:
    string intToRoman(int num) {
        int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string s[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int idx =0;
        
        string str = ""; 
        
        while (num>0){
            if (num >= value[idx]){
                str = str + s[idx];
                num -= value[idx];
            } else {
                ++idx;
            }
        }
        
        return str;
    }
};