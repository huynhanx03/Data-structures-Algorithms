/*
 Problem: 127. Word Ladder
 Language: cpp
 Runtime: 66 ms (50.87%)
 Memory: 21.2 MB (43.60%)
 Tags: Hash Table, String, Breadth-First Search
*/
class Solution {
private:
    bool isWordInList(const string& word, const unordered_set<string>& st) {
        return st.find(word) != st.end();
    }

public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        int n = beginWord.size();

        unordered_set<string> st(wordList.begin(), wordList.end());

        if (!isWordInList(endWord, st))
            return 0;

        queue<pair<string, int>> q;

        unordered_set<string> visited;

        q.push({beginWord, 1});

        st.erase(beginWord);

        while (!q.empty()) {
            auto [s, v] = q.front();

            q.pop();

            for (int i = 0; i < n; ++i) {
                char cc = s[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    s[i] = ch;

                    if (s == endWord)
                        return v + 1;

                    if (isWordInList(s, st)) {
                        st.erase(s);
                        q.push({s, v + 1});
                    }
                }

                s[i] = cc;
            }
        }

        return 0;
    }
};