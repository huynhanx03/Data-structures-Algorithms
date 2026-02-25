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
};
