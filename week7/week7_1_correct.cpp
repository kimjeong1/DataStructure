#include <iostream>
#include <vector>

using namespace std;

struct node {
	int data;
	node* parent;
	int depth;
	vector<node*> childList;
	node(int data, int depth, node* parent = nullptr) {
		this->data = data;
		this->depth = depth;
		this->parent = parent;
	}
};

class Tree {
private:
	node* root;
	vector<node*> nodeList;

	int find(int data, vector<node*>& list) {
		for (int i = 0; i < list.size(); i++) {
			if (list[i]->data == data) return i;
		}
		return -1;
	}

public:
	Tree(int data) {
		root = new node(data, 0);
		nodeList.push_back(root);
	}
	void insertNode(int parData, int data) {
		if (find(data, nodeList) != -1) {
			return;
		}
		int idx = find(parData, nodeList);
		if (idx == -1) return;

		node* parNode = nodeList[idx];
		node* newNode = new node(data, nodeList[idx]->depth + 1, parNode);
		parNode->childList.push_back(newNode);
		nodeList.push_back(newNode);
		return;
	}

	node* getRoot() { return root; }

	void preorder(node* Node) {
		int tmp = Node->data;
		node* cur = Node;

		while (cur != nullptr) {
			if (cur->data > tmp) {
				tmp = cur->data;
			}
			cur = cur->parent;
		}
		cout << tmp << " ";

		for (int i = 0; i < Node->childList.size(); i++) {
			preorder(Node->childList[i]);
		}
	}

};

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		Tree tree(1);

		for (int j = 0; j < n - 1; j++) {
			int x, y;
			cin >> x >> y;
			tree.insertNode(x, y);
		}

		tree.preorder(tree.getRoot());
		cout << "\n";
	}

	return 0;
}
