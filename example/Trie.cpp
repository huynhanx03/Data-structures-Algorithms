#include <iostream>
#include <unordered_map>
using namespace std;

// TrieNode structure
struct TrieNode {
    unordered_map<char, TrieNode*> children;  // Store child nodes for each character
    bool isEndOfWord;  // Flag to indicate if it's the end of a word
};

// Trie class to manage the Trie data structure
class Trie {
private:
    TrieNode* root;  // Root node of the Trie

public:
    // Constructor to initialize the Trie
    Trie() {
        root = new TrieNode();  // Create a root node
        root->isEndOfWord = false;  // The root is not the end of a word
    }

    // Insert a word into the Trie
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            // If the character does not exist in the children, create a new node
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];  // Move to the next node
        }
        node->isEndOfWord = true;  // Mark the last node as the end of a word
    }

    // Search for a word in the Trie
    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            // If the character is not found, return false
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];  // Move to the next node
        }
        return node->isEndOfWord;  // Return true if the node is the end of a word
    }

    // Check if there is any word in the Trie that starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            // If the character is not found, return false
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];  // Move to the next node
        }
        return true;  // Return true if the prefix is found in the Trie
    }
};

int main() {
    Trie trie;

    // Insert words into the Trie
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");
    trie.insert("ball");

    // Test the search function
    cout << trie.search("apple") << endl;  // Output: 1 (true)
    cout << trie.search("app") << endl;    // Output: 1 (true)
    cout << trie.search("bat") << endl;    // Output: 1 (true)
    cout << trie.search("bake") << endl;   // Output: 0 (false)

    // Test the startsWith function
    cout << trie.startsWith("ba") << endl; // Output: 1 (true)
    cout << trie.startsWith("ball") << endl; // Output: 1 (true)
    cout << trie.startsWith("balloon") << endl; // Output: 0 (false)

    return 0;
}
