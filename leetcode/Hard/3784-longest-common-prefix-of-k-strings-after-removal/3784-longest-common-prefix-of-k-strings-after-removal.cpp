/*
 Problem: 3784. Longest Common Prefix of K Strings After Removal
 Language: cpp
 Runtime: 1126 ms (16.28%)
 Memory: 507.5 MB (11.63%)
 Tags: Array, String, Trie
*/
struct TrieNode {
    TrieNode* children[26];
    int count, bestPrefixLength;
    bool isEndOfWord;
    TrieNode() : count(0), bestPrefixLength(-1), isEndOfWord(false) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Solution {
private:
    TrieNode* root;

    void updateTrie(const string& word, int delta, int k) {
        int wordLength = word.size();
        vector<TrieNode*> nodePath(wordLength + 1, nullptr);
        vector<int> depths(wordLength + 1, 0);
        nodePath[0] = root;
        depths[0] = 0;
        for (int i = 0; i < wordLength; i++) {
            int letterIndex = word[i] - 'a';
            if (nodePath[i]->children[letterIndex] == nullptr) {
                nodePath[i]->children[letterIndex] = new TrieNode();
            }
            nodePath[i + 1] = nodePath[i]->children[letterIndex];
            depths[i + 1] = depths[i] + 1;
        }
        for (TrieNode* node : nodePath) {
            node->count += delta;
        }

        for (int i = wordLength; i >= 0; i--) {
            TrieNode* currentNode = nodePath[i];
            int candidate = (currentNode->count >= k ? depths[i] : -1);
            for (int j = 0; j < 26; j++) {
                TrieNode* childNode = currentNode->children[j];
                if (childNode != nullptr) {
                    candidate = max(candidate, childNode->bestPrefixLength);
                }
            }
            currentNode->bestPrefixLength = candidate;
        }
    }

public:
    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        int totalWords = words.size();
        vector<int> result(totalWords, 0);
        if (totalWords - 1 < k)
            return result;
        root = new TrieNode();
        for (const string& word : words) {
            updateTrie(word, 1, k);
        }

        for (int i = 0; i < totalWords; i++) {
            updateTrie(words[i], -1, k);
            result[i] = root->bestPrefixLength;
            updateTrie(words[i], 1, k);
        }
        return result;
    }
};