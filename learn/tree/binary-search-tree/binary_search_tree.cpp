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

    void deleteValue(int value) {
        root = deleteNode(root, value);
    }

    bool search(int value) {
        BSTNode* current = root;
        while (current) {
            if (value == current->data) return true;
            current = (value < current->data) ? current->left : current->right;
        }
        return false;
    }
};