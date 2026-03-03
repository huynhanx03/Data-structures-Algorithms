/*
 Problem: 212. Word Search II
 Language: cpp
 Runtime: 223 ms (81.48%)
 Memory: 19.1 MB (69.26%)
 Tags: Array, String, Backtracking, Trie, Matrix
*/
class TrieNode {
public:
    TrieNode* children[26];
    string word;

    TrieNode() {
        word = "";
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->word = word;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        Trie trie;
        for (string word : words) {
            trie.insert(word);
        }

        vector<string> result;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, trie.root, result);
            }
        }

        return result;
    }

private:
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node,
             vector<string>& result) {
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a'])
            return;
        node = node->children[c - 'a'];
        
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = "";
        }

        board[i][j] = '#';
        if (i > 0)
            dfs(board, i - 1, j, node, result);
        if (j > 0)
            dfs(board, i, j - 1, node, result);
        if (i < board.size() - 1)
            dfs(board, i + 1, j, node, result);
        if (j < board[0].size() - 1)
            dfs(board, i, j + 1, node, result);
        board[i][j] = c;
    }
};
