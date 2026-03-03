/*
 Problem: 443. String Compression
 Language: cpp
 Runtime: 3 ms (13.72%)
 Memory: 14.9 MB (13.81%)
 Tags: Two Pointers, String
*/
class Solution {
private:
    void write(vector<char>& chars, int& pos, char c, int cnt) {
        chars[pos++] = c;
        if (cnt > 1) {
            string num = to_string(cnt);
            for (char d : num) {
                chars[pos++] = d;
            }
        }
    }

public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int pos = 0;
        int cnt = 1;

        for (int i = 1; i <= n; ++i) {
            if (i < n && chars[i] == chars[i - 1]) {
                cnt++;
            } else {
                write(chars, pos, chars[i - 1], cnt);
                cnt = 1;
            }
        }
        return pos;
    }
};
