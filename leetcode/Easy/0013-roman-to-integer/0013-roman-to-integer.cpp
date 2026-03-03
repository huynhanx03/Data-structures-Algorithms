/*
 Problem: 13. Roman to Integer
 Language: cpp
 Runtime: 3 ms (74.43%)
 Memory: 10.9 MB (73.97%)
 Tags: Hash Table, Math, String
*/
class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();

        int idx = 0, ans = 0;;

        while (idx < n) {
            char c = s[idx];
            int value = 0;

            switch (c) {
                case 'I':
                    value = 1;

                    if (idx + 1 < n) {
                        int cNext = s[idx + 1];

                        switch (cNext) {
                            case 'V':
                                value = 4;
                                ++idx;
                                break;
                            case 'X':
                                value = 9;
                                ++idx;
                                break;
                        }
                    }

                    break;
                
                case 'X':
                    value = 10;

                    if (idx + 1 < n) {
                        int cNext = s[idx + 1];

                        switch (cNext) {
                            case 'L':
                                value = 40;
                                ++idx;
                                break;
                            case 'C':
                                value = 90;
                                ++idx;
                                break;
                        }
                    }

                    break;
                
                case 'C':
                    value = 100;

                    if (idx + 1 < n) {
                        int cNext = s[idx + 1];

                        switch (cNext) {
                            case 'D':
                                value = 400;
                                ++idx;
                                break;
                            case 'M':
                                value = 900;
                                ++idx;
                                break;
                        }
                    }

                    break;

                case 'V':
                    value = 5;
                    break;
                
                case 'L':
                    value = 50;
                    break;

                case 'D':
                    value = 500;
                    break;

                case 'M':
                    value = 1000;
                    break;
            }

            ++idx;
            ans += value;
        }

        return ans;
    }
};