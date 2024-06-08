
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
	int arr[10001];
	int idx;
	int size;

	bst() {
		root = NULL;
		size = 0;
	}
	node* search(node* curNode, int key) {
		if (curNode == NULL) return NULL;

		if (curNode->key == key)
			return curNode;
		else if (curNode->key < key)
			return search(curNode->right, key);
		else
			return search(curNode->left, key);
	}
	void insert(int key) {
		if (search(root, key) != NULL) return;

		node* newNode = new node(key);
		if (root == NULL) {
			root = newNode;
			size++;
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
		size++;
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
			while (childNode->left != NULL)
			{
				childNode = childNode->left;
			}
			delNode->key = childNode->key;
			delNode = childNode;
			parNode = delNode->parent;
			childNode = delNode->right;
		}

		if (parNode == NULL) {
			root = childNode;
			if (root != NULL)
				root->parent = NULL;
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
		size--;
	}


	int getmax(int k) {
		idx = 0;
		inorder(root, idx);
		return arr[size - k];

	}

	void inorder(node* node, int& idx)
	{
		if (node == NULL) return;
		if (node->left) {
			inorder(node->left, idx);
		}
		arr[idx] = node->key;
		idx++;
		if (node->right) {
			inorder(node->right, idx);
		}
	}


};

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		bst b;

		for (int j = 0; j < n; j++) {
			string c;
			cin >> c;
			int x;
			cin >> x;
			if (c == "insert") {
				b.insert(x);
			}
			else if (c == "delete") {
				b.remove(x);
			}
			else if (c == "max") {
				cout << b.getmax(x) << '\n';
			}
		}
	}


	return 0;
}
