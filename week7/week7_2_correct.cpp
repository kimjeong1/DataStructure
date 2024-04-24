#include <iostream>
#include <vector>

using namespace std;

struct node {
	int data;
	int num;
	node* parent;
	vector<node*> childList;
	node(int data, node* parent = nullptr) {
		this->data = data;
		num = 0;
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
		root = new node(data);
		nodeList.push_back(root);
	}
	void insertNode(int parData, int data) {
		if (find(data, nodeList) != -1) {
			return;
		}
		int idx = find(parData, nodeList);
		if (idx == -1) return;

		node* parNode = nodeList[idx];
		node* newNode = new node(data, parNode);
		parNode->childList.push_back(newNode);
		nodeList.push_back(newNode);
		return;
	}
	void setnum(int data, int n) {
		int idx = find(data, nodeList);
		if (idx == -1) return;

		nodeList[idx]->num = n;
	}

	int getnum(int data) {
		int idx = find(data, nodeList);
		if (idx == -1) return -1;
		return nodeList[idx]->num;
	}

	void postorder(node* curNode) {
		for (int i = 0; i < curNode->childList.size(); i++) {
			postorder(curNode->childList[i]);
		}
		for (int i = 0; i < curNode->childList.size(); i++) {
			curNode->num += curNode->childList[i]->num;
		}
	}

	node* getRoot() { return root; }
};

int main() {

	int n, m;
	cin >> n >> m;

	Tree tree(1);

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >>  y;
		tree.insertNode(x, y);
	}
	for (int i = 0; i < n; i++) {
		int u, w;
		cin >> u >> w;
		tree.setnum(u, w);

	}
	tree.postorder(tree.getRoot());

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		cout << tree.getnum(x);
		cout << "\n";
	}


	return 0;
}
