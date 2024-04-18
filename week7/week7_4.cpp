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
		if (idx == -1) {
			return;
		}
		node* parNode = nodeList[idx];
		node* newNode = new node(data, nodeList[idx]->depth+1, parNode);
		parNode->childList.push_back(newNode);
		nodeList.push_back(newNode);
		return;
	}

	node* getRoot() {
		return root;
	}

	bool preoreder(node* curNode, int x) {
		bool found = false;
		if (curNode->childList.empty()) {
			if (curNode->depth == x) {
				cout << curNode->data << " ";
				found = true;
			}
		}
		for (int i = 0; i < curNode->childList.size(); i++) {
			if (preoreder(curNode->childList[i], x)) {
				found = true;
			}
		}
		return found;
	}

};

int main() {
	int n, m;
	cin >> n >> m;

	Tree tree(1);


	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		tree.insertNode(x, y);
	}
	for (int j = 0; j < m; j++) {
		int x;
		cin >> x;
		if (!tree.preoreder(tree.getRoot(), x)) {
			cout << "-1";
		}
		cout << "\n";
	}

	return 0;
}
