#include <iostream>
using namespace std;

class BinaryTreeNode {
public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    BinaryTreeNode* root;

    void preOrder(BinaryTreeNode* node) {
        if (node) {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void inOrder(BinaryTreeNode* node) {
        if (node) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

    void postOrder(BinaryTreeNode* node) {
        if (node) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->data << " ";
        }
    }

    BinaryTreeNode* deleteNode(BinaryTreeNode* node, int value) {
        if (!node) return nullptr;

        if (node->data != value) {
            if (!node->left)
                deleteNode(node->left, value);

            if (!node->right)
                deleteNode(node->right, value);
        } else {
            if (!node->left) {
                BinaryTreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                BinaryTreeNode* temp = node->left;
                delete node;
                return temp;
            }

            BinaryTreeNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }

        return node;
    }

    BinaryTreeNode* findMin(BinaryTreeNode* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

public:
    BinaryTree() { root = nullptr; }

    void insert(int value) {
        BinaryTreeNode* newNode = new BinaryTreeNode(value);
        if (!root) {
            root = newNode;
            return;
        }

        BinaryTreeNode* current = root;
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

    void deleteValue(int value) {
        root = deleteNode(root, value);
    }

    void preOrderTraversal() { preOrder(root); cout << endl; }
    void inOrderTraversal() { inOrder(root); cout << endl; }
    void postOrderTraversal() { postOrder(root); cout << endl; }
};

int main() {
    BinaryTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Pre-order: ";
    tree.preOrderTraversal();

    cout << "In-order: ";
    tree.inOrderTraversal();

    cout << "Post-order: ";
    tree.postOrderTraversal();

    tree.deleteValue(20);
    cout << "After deleting 20 (In-order): ";
    tree.inOrderTraversal();

    return 0;
}
