#include <iostream>
#include <vector>

using namespace std;

struct node {
	int data;
	int size;
	node* parent;
	vector<node*> childList;
	node(int data, node* parent = nullptr) {
		this->data = data;
		this->parent = parent;
		this->size = 0;
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
		root = new node(data, NULL);
		nodeList.push_back(root);
	}
	void insertNode(int parData, int data) {
		if (find(data, nodeList) != -1) {
			return;
		}
		int idx = find(parData, nodeList);
		if (idx == -1)
			return;

		node* parNode = nodeList[idx];
		node* newNode = new node(data, parNode);
		parNode->childList.push_back(newNode);
		nodeList.push_back(newNode);
	}
	void setnum(int data, int n) {
		int idx = find(data, nodeList);
		if (idx == -1) {
			return;
		}

		nodeList[idx]->size = n;
	}

	node* getRoot() {
		return root;
	}


	bool postOrderTraversal(node* n, int c) {
		bool flag = false;
		for (node* child : n->childList) {
			postOrderTraversal(child, c);
		}
		for (node* child : n->childList) {
			n->size += child->size;
		}
		if (n->size >= c) {
			cout << n->data << " ";
			flag = true;
		}
		return flag;
	}

	void deleteTree(node* n) {
		for (node* child : n->childList) {
			deleteTree(child);
		}
		delete n;
	}


};

int main() {

	Tree tree(1);
	int n, c;

	cin >> n >> c;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		tree.insertNode(x, y);
	}
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		tree.setnum(x, y);
	}
	
	if (!tree.postOrderTraversal(tree.getRoot(), c)) {
		cout << -1 << '\n';
	}

	tree.deleteTree(tree.getRoot());

	return 0;
}
