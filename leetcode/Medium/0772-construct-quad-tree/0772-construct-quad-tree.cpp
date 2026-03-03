/*
 Problem: 772. Construct Quad Tree
 Language: cpp
 Runtime: 11 ms (53.51%)
 Memory: 18.8 MB (74.63%)
 Tags: Array, Divide and Conquer, Tree, Matrix
*/
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return createMatrix(grid, 0, 0, grid.size());
    }

private:
    bool checkLeaf(const vector<vector<int>>& grid, int r, int c, int len) {
        for (int i = r; i < r + len; ++i)
            for (int j = c; j < c + len; ++j)
                if (grid[i][j] != grid[r][c]) return 0;

        return 1;
    }

    Node* createMatrix(const vector<vector<int>>& grid, int r, int c, int len) {
        if (checkLeaf(grid, r, c, len)) return new Node(grid[r][c], 1);
        
        Node* root = new Node();

        int newLen = len / 2;

        root->topLeft = createMatrix(grid, r, c, newLen);
        root->topRight = createMatrix(grid, r, c + newLen, newLen);
        root->bottomLeft = createMatrix(grid, r + newLen , c, newLen);
        root->bottomRight = createMatrix(grid, r + newLen, c + newLen, newLen);

        return root;
    }
};