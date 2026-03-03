/*
 Problem: 211. Design Add and Search Words Data Structure
 Language: cpp
 Runtime: 386 ms (57.22%)
 Memory: 568.3 MB (37.71%)
 Tags: String, Depth-First Search, Design, Trie
*/
class WordDictionary {
public:
    WordDictionary() { root = new TrieNode; }

    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';

            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }

            node = node->children[index];
        }

        node->isEndOfWord = true;
    }

    bool search(string word) {
        return searchInNode(word, root);
    }

private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEndOfWord;

        TrieNode() {
            isEndOfWord = false;
            for (int i = 0; i < 26; ++i) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;

    bool searchInNode(string word, TrieNode* node) {
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            if (c == '.') {
                for (int j = 0; j < 26; ++j) {
                    if (node->children[j] &&
                        searchInNode(word.substr(i + 1), node->children[j])) {
                        return true;
                    }
                }
                return false;
            } else {
                int index = c - 'a';
                if (!node->children[index]) {
                    return false;
                }
                node = node->children[index];
            }
        }
        return node->isEndOfWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */