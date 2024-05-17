//
// Created by 김정일 on 2024. 5. 17..
//

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
    int arr[10001];
    int idx;
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

    int depth(node *node) {
        if (node == root) {
            return 0;
        } else {
            return depth(node->parent) + 1;
        }
    }

    int height(node *node) {
        if (!node) {
            return -1;
        }
        int lHeight = height(node->left);
        int rHeight = height(node->right);
        return ((lHeight > rHeight) ? lHeight : rHeight) + 1;
    }

    int getmin(int k) {
        int idx = 0;
        inorder(root, idx);
        return arr[k-1];
    }
    void inorder(node* n, int& idx) {
        if(n == NULL) return;
        if(n->left) inorder(n->left, idx);
        arr[idx] = n->key;
        idx++;
        if(n->right) inorder(n->right, idx);
    }

};

int main() {
    int t;
    cin >> t;
    bst b;

    for(int i = 0; i<t; i++) {
        string c;
        cin >> c;

        int x;
        cin >> x;
        if(c == "insert") {
            b.insert(x);
            cout << b.depth(b.search(b.root, x)) << '\n';
        }
        else if(c == "delete") {
            cout << b.depth(b.search(b.root, x)) << '\n';
            b.remove(x);
        }
        else if (c == "min") {
            cout << b.getmin(x) << '\n';
        }
        else if ( c == "height") {
            cout << b.height(b.search(b.root, x)) << '\n';
        }

    }

    return 0;
}
