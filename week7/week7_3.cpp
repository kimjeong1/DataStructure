#include <iostream>
#include <vector>

using namespace std;

struct node {
	int data;
	int depth;
	node* parent;
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
	int find(int data, vector<node*>& List) {
		for (int i = 0; i < List.size(); i++) {
			if (List[i]->data == data)
				return i;
		}
		return -1;
	}

public:
	Tree(int data) {
		root = new node(data, 0);
		nodeList.push_back(root);
	}
	node* getRoot() {
		return root;
	}
	void insertNode(int parData, int data) {
		if (find(data, nodeList) != -1) {
			return;
		}
		int idx = find(parData, nodeList);
		if (idx == -1)
			return;

		node* parNode = nodeList[idx];
		node* newNode = new node(data, nodeList[idx]->depth + 1, parNode);
		parNode->childList.push_back(newNode);
		nodeList.push_back(newNode);
	}

	void postOrderTraversal(node* n) {
		for (node* child : n->childList) {
			postOrderTraversal(child);
		}
		if (n->childList.empty()) {
			cout << n->depth << " ";
		}
		else
			cout << n->childList.size() << " ";
	}
};

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		Tree tree(1);

		for (int j = 0; j < n-1; j++) {
			int x, y;
			cin >> x >> y;
			tree.insertNode(x, y);
		}
		tree.postOrderTraversal(tree.getRoot());
	}

	return 0;
}
