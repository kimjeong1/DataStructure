
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
	int count;
	bst() {
		root = NULL;
		count = 0;
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

	void count_clear() {
		count = 0;
	}

	node* search_x(node* curNode, int key) {
		if (root == NULL) {
			cout << "empty\n";
			return NULL;
		}
		if (curNode == NULL) {
			cout << count << '\n';
			return NULL;
		}

		if (curNode->key == key) {
			count++;
			cout << count << '\n';
			return curNode;
		}
		else if (curNode->key < key) {
			count++;
			return search_x(curNode->right, key);
		}
		else {
			count++;
			return search_x(curNode->left, key);
		}

	}
	void insert(int key) {
		int cnt = 0;
		if (search(root, key) != NULL) return;

		node* newNode = new node(key);
		if (root == NULL) {
			root = newNode;
			cout << cnt << '\n';
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
			cnt++;
		}

		newNode->parent = parNode;
		if (parNode->key < key) {
			parNode->right = newNode;
		}
		else {
			parNode->left = newNode;
		}
		cout << cnt << '\n';
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
	}

	int p(int key) {
		node* parNode = search(root, key);
		if (parNode == NULL) return -1;
		else if (parNode == root) return -2; // caution
		else return parNode->parent->key;
	}

	int c(int key) {
		node* child = search(root, key);
		if (child == NULL) return -1;
		else if (child->left == NULL) return -2;
		else return child->left->key;
	}

	bool existleft(node* n) {
		return n->left;
	}

	int pre(node* node) {
		if (!node)
			return 0;
		return 1 + pre(node->left) + pre(node->right);
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
			else if (c == "search") {
				b.count_clear();
				b.search_x(b.root, x);
			}
			else if (c == "parent") {
				cout << b.p(x) << '\n';
			}
			else if (c == "child") {
				cout << b.c(x) << '\n';
			}
		}
	}


	return 0;
}
