/*
 Problem: 3329. Find the Length of the Longest Common Prefix
 Language: cpp
 Runtime: 128 ms (86.00%)
 Memory: 160.9 MB (31.77%)
 Tags: Array, Hash Table, String, Trie
*/
class Trie {
private:
    struct Node {
        Node* next[10] = {};
    };

    Node* root = new Node();

public:
    void insert(const string& s) {
        auto* node = root;

        for (const auto& ch : s) {
            const int digit = ch - '0';

            if (!node->next[digit]) {
                node->next[digit] = new Node();
            }

            node = node->next[digit];
        }
    }

    int longestPrefix(const string& s) const {
        auto* node = root;
        int length = 0;

        for (const auto& ch : s) {
            const int digit = ch - '0';

            if (!node->next[digit]) {
                break;
            }

            node = node->next[digit];
            ++length;
        }

        return length;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;

        for (const auto& num : arr1) {
            trie.insert(to_string(num));
        }

        int ans = 0;

        for (const auto& num : arr2) {
            ans = max(ans, trie.longestPrefix(to_string(num)));
        }

        return ans;
    }
};