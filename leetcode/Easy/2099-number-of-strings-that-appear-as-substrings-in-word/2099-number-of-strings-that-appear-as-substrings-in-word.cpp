/*
 Problem: 2099. Number of Strings That Appear as Substrings in Word
 Language: cpp
 Runtime: 3 ms (27.12%)
 Memory: 13.2 MB (17.26%)
 Tags: Array, String
*/
class Solution {
    struct State {
        int next[26];
        int link, len;

        State() : link(-1), len(0) {
            memset(next, -1, sizeof(next));
        }
    };

    vector<State> st;
    int last;

    void extend(char c) {
        int cur = st.size();
        st.emplace_back();
        st[cur].len = st[last].len + 1;

        int x = c - 'a';
        int p = last;

        while (p != -1 && st[p].next[x] == -1) {
            st[p].next[x] = cur;
            p = st[p].link;
        }

        if (p == -1) {
            st[cur].link = 0;
        } else {
            int q = st[p].next[x];

            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = st.size();
                st.push_back(st[q]);
                st[clone].len = st[p].len + 1;

                while (p != -1 && st[p].next[x] == q) {
                    st[p].next[x] = clone;
                    p = st[p].link;
                }

                st[q].link = clone;
                st[cur].link = clone;
            }
        }

        last = cur;
    }

    bool contains(const string& pattern) {
        int state = 0;

        for (const auto& c : pattern) {
            state = st[state].next[c - 'a'];

            if (state == -1) {
                return false;
            }
        }

        return true;
    }

public:
    int numOfStrings(vector<string>& patterns, string word) {
        st.reserve(word.size() * 2);
        st.emplace_back();
        last = 0;

        for (const auto& c : word) {
            extend(c);
        }

        int ans = 0;

        for (const auto& pattern : patterns) {
            ans += contains(pattern);
        }

        return ans;
    }
};