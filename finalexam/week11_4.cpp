#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    int size; // size of the subtree rooted at this node

    TreeNode(int x) : key(x), left(NULL), right(NULL), size(1) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int key) {
        if (node == NULL) {
            return new TreeNode(key);
        }
        if (key < node->key) {
            node->left = insert(node->left, key);
        } else {
            node->right = insert(node->right, key);
        }
        node->size = 1 + getSize(node->left) + getSize(node->right);
        return node;
    }

    TreeNode* deleteNode(TreeNode* node, int key) {
        if (node == NULL) return node;
        if (key < node->key) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->key) {
            node->right = deleteNode(node->right, key);
        } else {
            if (node->left == NULL) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode* temp = findMin(node->right);
            node->key = temp->key;
            node->right = deleteNode(node->right, temp->key);
        }
        node->size = 1 + getSize(node->left) + getSize(node->right);
        return node;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    int getSize(TreeNode* node) {
        return node == NULL ? 0 : node->size;
    }

    int findKthMin(TreeNode* node, int k) {
        int leftSize = getSize(node->left);
        if (leftSize + 1 == k) {
            return node->key;
        } else if (k <= leftSize) {
            return findKthMin(node->left, k);
        } else {
            return findKthMin(node->right, k - leftSize - 1);
        }
    }

public:
    BinarySearchTree() : root(NULL) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void deleteKey(int key) {
        root = deleteNode(root, key);
    }

    int findKthMin(int k) {
        return findKthMin(root, k);
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        BinarySearchTree bst;

        for (int i = 0; i < N; ++i) {
            string command;
            cin >> command;

            if (command == "insert") {
                int x;
                cin >> x;
                bst.insert(x);
            } else if (command == "delete") {
                int x;
                cin >> x;
                bst.deleteKey(x);
            } else if (command == "min") {
                int k;
                cin >> k;
                cout << bst.findKthMin(k) << endl;
            }
        }
    }

    return 0;
}
