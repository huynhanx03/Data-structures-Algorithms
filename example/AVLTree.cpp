#include <iostream>
using namespace std;

class AVLNode {
public:
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVLTree {
private:
    AVLNode* root;

    int getHeight(AVLNode* node) {
        return node ? node->height : 0;
    }

    int getBalanceFactor(AVLNode* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    AVLNode* rotateLeft(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    AVLNode* insert(AVLNode* node, int value) {
        if (!node) return new AVLNode(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        else
            return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        return balance(node);
    }

    AVLNode* minValueNode(AVLNode* node) {
        AVLNode* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    AVLNode* deleteNode(AVLNode* node, int value) {
        if (!node) return node;

        if (value < node->data)
            node->left = deleteNode(node->left, value);
        else if (value > node->data)
            node->right = deleteNode(node->right, value);
        else {
            if (!node->left || !node->right) {
                AVLNode* temp = node->left ? node->left : node->right;
                if (!temp) {
                    temp = node;
                    node = nullptr;
                } else
                    *node = *temp;
                delete temp;
            } else {
                AVLNode* temp = minValueNode(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }

        if (!node) return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        return balance(node);
    }

    AVLNode* balance(AVLNode* node) {
        int balanceFactor = getBalanceFactor(node);

        // Left Left Case
        if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0)
            return rotateRight(node);

        // Left Right Case
        if (balanceFactor > 1 && getBalanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Right Case
        if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0)
            return rotateLeft(node);

        // Right Left Case
        if (balanceFactor < -1 && getBalanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void preOrder(AVLNode* node) {
        if (node) {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void inOrder(AVLNode* node) {
        if (node) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

    void postOrder(AVLNode* node) {
        if (node) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->data << " ";
        }
    }

public:
    AVLTree() { root = nullptr; }

    void insert(int value) {
        root = insert(root, value);
    }

    void deleteValue(int value) {
        root = deleteNode(root, value);
    }

    void preOrderTraversal() {
        preOrder(root);
        cout << endl;
    }

    void inOrderTraversal() {
        inOrder(root);
        cout << endl;
    }

    void postOrderTraversal() {
        postOrder(root);
        cout << endl;
    }
};

int main() {
    AVLTree tree;

    // Insert nodes
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "Pre-order traversal (NLR): ";
    tree.preOrderTraversal();

    cout << "In-order traversal (LNR): ";
    tree.inOrderTraversal();

    cout << "Post-order traversal (LRN): ";
    tree.postOrderTraversal();

    // Delete nodes
    tree.deleteValue(30);
    cout << "After deleting 30, In-order traversal: ";
    tree.inOrderTraversal();

    tree.deleteValue(40);
    cout << "After deleting 40, In-order traversal: ";
    tree.inOrderTraversal();

    return 0;
}
