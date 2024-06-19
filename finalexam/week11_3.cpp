#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode(int x) : key(x), left(NULL), right(NULL), parent(NULL) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int key, TreeNode* parent, int& comparisons) {
        comparisons++;
        if (node == NULL) {
            TreeNode* newNode = new TreeNode(key);
            newNode->parent = parent;
            return newNode;
        }
        if (key < node->key) {
            node->left = insert(node->left, key, node, comparisons);
        } else {
            node->right = insert(node->right, key, node, comparisons);
        }
        return node;
    }

    int search(TreeNode* node, int key, int& comparisons) {
        if (node == NULL) {
            return comparisons;
        }
        comparisons++;
        if (key == node->key) {
            return comparisons;
        } else if (key < node->key) {
            return search(node->left, key, comparisons);
        } else {
            return search(node->right, key, comparisons);
        }
    }

    TreeNode* searchNode(TreeNode* node, int key) {
        while (node != NULL && node->key != key) {
            if (key < node->key) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return node;
    }

public:
    BinarySearchTree() : root(NULL) {}

    int insert(int key) {
        int comparisons = 0;
        root = insert(root, key, NULL, comparisons);
        return comparisons;
    }

    int search(int key) {
        if (root == NULL) return -1; // empty
        int comparisons = 0;
        return search(root, key, comparisons);
    }

    int getParent(int key) {
        TreeNode* node = searchNode(root, key);
        if (node == NULL) return -1; // node not found
        if (node->parent == NULL) return -2; // no parent
        return node->parent->key;
    }

    int getRightChild(int key) {
        TreeNode* node = searchNode(root, key);
        if (node == NULL) return -1; // node not found
        if (node->right == NULL) return -2; // no right child
        return node->right->key;
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
                cout << bst.insert(x)-1 << endl;
            } else if (command == "search") {
                int x;
                cin >> x;
                int result = bst.search(x);
                if (result == -1) {
                    cout << "empty" << endl;
                } else {
                    cout << result << endl;
                }
            } else if (command == "parent") {
                int x;
                cin >> x;
                cout << bst.getParent(x) << endl;
            } else if (command == "child") {
                int x;
                cin >> x;
                cout << bst.getRightChild(x) << endl;
            }
        }
    }

    return 0;
}
