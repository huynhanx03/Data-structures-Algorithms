#include <iostream>
using namespace std;

class BSTNode {
public:
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    BSTNode* root;

    // Traversal functions
    void preOrder(BSTNode* node) {
        if (node) {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void inOrder(BSTNode* node) {
        if (node) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

    void postOrder(BSTNode* node) {
        if (node) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->data << " ";
        }
    }

    // Helper for deletion
    BSTNode* deleteNode(BSTNode* node, int value) {
        if (!node) return nullptr;
        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            if (!node->left) {
                BSTNode* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                BSTNode* temp = node->left;
                delete node;
                return temp;
            }
            BSTNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    BSTNode* findMin(BSTNode* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

public:
    BST() { root = nullptr; }

    // Insert a node
    void insert(int value) {
        BSTNode* newNode = new BSTNode(value);
        if (!root) {
            root = newNode;
            return;
        }

        BSTNode* current = root;
        while (true) {
            if (value < current->data) {
                if (!current->left) {
                    current->left = newNode;
                    break;
                }
                current = current->left;
            } else {
                if (!current->right) {
                    current->right = newNode;
                    break;
                }
                current = current->right;
            }
        }
    }

    // Delete a node
    void deleteValue(int value) {
        root = deleteNode(root, value);
    }

    // Search a node
    bool search(int value) {
        BSTNode* current = root;
        while (current) {
            if (value == current->data) return true;
            current = (value < current->data) ? current->left : current->right;
        }
        return false;
    }

    // Traversal wrappers
    void preOrderTraversal() { preOrder(root); cout << endl; }
    void inOrderTraversal() { inOrder(root); cout << endl; }
    void postOrderTraversal() { postOrder(root); cout << endl; }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Pre-order (NLR): ";
    tree.preOrderTraversal();

    cout << "In-order (LNR): ";
    tree.inOrderTraversal();

    cout << "Post-order (LRN): ";
    tree.postOrderTraversal();

    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    tree.deleteValue(20);
    cout << "After deleting 20 (In-order): ";
    tree.inOrderTraversal();

    return 0;
}
    