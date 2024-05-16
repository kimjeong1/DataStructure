#include <iostream>

using namespace std;

struct node {
    int key;
    node* parent;
    node* left;
    node* right;

    node(int key) {
        this->key = key;
        parent = left = right = NULL;
    }
};

class bst {

public:
    node* root;
    int cnt;
    bst() {
        root = NULL;
        cnt = 0;
    }
    node* search(node* curNode, int key) {
        if (curNode == NULL) return NULL;

        if (curNode->key == key) {
            return curNode;
        }
        else if (curNode->key < key) {
            return search(curNode->right, key);
        }
        else
            return search(curNode->left, key);
    }
    void insert(int key) {
        if (search(root, key) != NULL) return;

        node* newNode = new node(key);
        if (root == NULL) {
            root = newNode;
            return;
        }

        node* curNode = root;
        node* parNode = NULL;

        while (curNode != NULL) {
            parNode = curNode;
            if (curNode->key < key) {
                curNode = curNode->right;
            }
            else {
                curNode = curNode->left;
            }
        }

        newNode->parent = parNode;
        if (parNode->key < key) {
            parNode->right = newNode;
        }
        else {
            parNode->left = newNode;
        }
    }
    void remove(int key) {
        node* delNode = search(root, key);
        if (delNode == NULL) return;

        node* parNode = delNode->parent;
        node* childNode;

        if (delNode->left == NULL && delNode->right == NULL) {
            childNode = NULL;
        }
        else if (delNode->left == NULL && delNode->right != NULL) {
            childNode = delNode->right;
        }
        else if (delNode->left != NULL && delNode->right == NULL) {
            childNode = delNode->left;
        }
        else {
            childNode = delNode->right;
            while (childNode->left != NULL) {
                childNode = childNode->left;
            }
            delNode->key = childNode->key;
            delNode = childNode;
            parNode = delNode->parent;
            childNode = delNode->right;
        }

        if (parNode == NULL) {
            root = childNode;
            if (root != NULL) {
                root->parent = NULL;
            }
        }
        else if (delNode == parNode->left) {
            parNode->left = childNode;
            if (childNode != NULL)
                childNode->parent = parNode;
        }
        else {
            parNode->right = childNode;
            if (childNode != NULL) {
                childNode->parent = parNode;
            }
        }
        delete delNode;
    }

    bool existleft(node* curNode) {
        return (curNode && curNode->left);
    }

    int pre(node* node) {
        if (!node)
            return 0;
        return 1 + pre(node->left) + pre(node->right);
    }

};

int main() {
    int n, m;
    cin >> n >> m;

    bst b;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.insert(x);
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        int cnt1 = 0, cnt2 = 0;
        if (b.existleft(b.search(b.root, x)))
            cnt1 = b.pre(b.search(b.root, x)->left);
        if (b.existleft(b.search(b.root, y)))
            cnt2 = b.pre(b.search(b.root, y)->left);

        cout << cnt1 + cnt2 << "\n";
    }

    return 0;
}
