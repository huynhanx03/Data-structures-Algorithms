/*
 Problem: 3770. Lexicographically Smallest Generated String
 Language: cpp
 Runtime: 29 ms (23.73%)
 Memory: 23 MB (18.64%)
 Tags: String, Greedy, String Matching
*/
class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int L = n + m - 1;
        string word(L, '?');
        
        int max_copied = 0;
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'T') {
                for (int j = max(i, max_copied); j < i + m; ++j) {
                    word[j] = str2[j - i];
                }
                max_copied = max(max_copied, i + m);
            }
        }
        
        vector<int> pi(m, 0);
        for (int i = 1, j = 0; i < m; ++i) {
            while (j > 0 && str2[i] != str2[j]) j = pi[j - 1];
            if (str2[i] == str2[j]) j++;
            pi[i] = j;
        }
        
        vector<bool> t_match(L, false);
        for (int i = 0, j = 0; i < L; ++i) {
            while (j > 0 && (word[i] == '?' || word[i] != str2[j])) j = pi[j - 1];
            if (word[i] != '?' && word[i] == str2[j]) j++;
            if (j == m) {
                t_match[i - m + 1] = true;
                j = pi[j - 1];
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'T' && !t_match[i]) return "";
        }
        
        int words = (m + 63) / 64;
        vector<uint64_t> D(words, 0);
        vector<vector<uint64_t>> pos(26, vector<uint64_t>(words, 0));
        for (int j = 0; j < m; ++j) {
            pos[str2[j] - 'a'][j / 64] |= (1ULL << (j % 64));
        }
        
        vector<bool> f_match(n, false);
        for (int x = 0; x < L; ++x) {
            uint64_t carry = 1;
            for (int w = 0; w < words; ++w) {
                uint64_t next_carry = D[w] >> 63;
                D[w] = (D[w] << 1) | carry;
                carry = next_carry;
            }
            if (word[x] != '?') {
                int c = word[x] - 'a';
                for (int w = 0; w < words; ++w) {
                    D[w] &= pos[c][w];
                }
            }
            if (x >= m - 1) {
                if (D[(m - 1) / 64] & (1ULL << ((m - 1) % 64))) {
                    f_match[x - m + 1] = true;
                }
            }
        }
        
        vector<int> pref_q(L + 1, 0);
        vector<int> prev_q(L, -1);
        int last_q_idx = -1;
        for (int x = 0; x < L; ++x) {
            pref_q[x + 1] = pref_q[x] + (word[x] == '?');
            if (word[x] == '?') last_q_idx = x;
            prev_q[x] = last_q_idx;
        }
        
        set<int> active;
        vector<vector<int>> check_at(L);
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'F' && f_match[i]) {
                int q_count = pref_q[i + m] - pref_q[i];
                if (q_count == 0) return "";
                int last_q = prev_q[i + m - 1];
                active.insert(i);
                check_at[last_q].push_back(i);
            }
        }
        
        for (int k = 0; k < L; ++k) {
            if (word[k] == '?') {
                int forbidden = 0;
                for (int i : check_at[k]) {
                    if (active.count(i)) {
                        forbidden |= (1 << (str2[k - i] - 'a'));
                    }
                }
                
                char c = 'a';
                while (c <= 'z' && (forbidden & (1 << (c - 'a')))) c++;
                if (c > 'z') return "";
                word[k] = c;
                
                auto it = active.lower_bound(max(0, k - m + 1));
                while (it != active.end() && *it <= k) {
                    if (str2[k - *it] != c) {
                        it = active.erase(it);
                    } else {
                        ++it;
                    }
                }
            }
        }
        
        return word;
    }
};