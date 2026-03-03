/*
 Problem: 721. Accounts Merge
 Language: cpp
 Runtime: 31 ms (67.62%)
 Memory: 39.7 MB (81.98%)
 Tags: Array, Hash Table, String, Depth-First Search, Breadth-First Search, Union-Find, Sorting
*/
class UnionFind {
public:
    UnionFind(int size) : parent(size), rank(size) {
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                ++rank[rootX];
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToIndex;
        UnionFind uf(accounts.size());

        for (int i = 0; i < accounts.size(); ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                string email = accounts[i][j];
                if (emailToIndex.count(email) == 0) {
                    emailToIndex[email] = i;
                } else {
                    uf.unite(i, emailToIndex[email]);
                }
            }
        }

        unordered_map<int, unordered_set<string>> indexToEmails;
        for (const auto& pair : emailToIndex) {
            int index = uf.find(pair.second);
            indexToEmails[index].insert(pair.first);
        }

        vector<vector<string>> mergedAccounts;
        for (const auto& pair : indexToEmails) {
            vector<string> emails(pair.second.begin(), pair.second.end());
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), accounts[pair.first][0]);
            mergedAccounts.push_back(emails);
        }

        return mergedAccounts;
    }
};