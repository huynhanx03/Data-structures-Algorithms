/*
 Problem: 208. Implement Trie (Prefix Tree)
 Language: cpp
 Runtime: 14 ms (89.31%)
 Memory: 50.4 MB (75.56%)
 Tags: Hash Table, String, Design, Trie
*/
class Trie {
public:
    Trie() { root = new TrieNode; }

    void insert(string word) {
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
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }

        return node->isEndOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }

        return true;
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
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */