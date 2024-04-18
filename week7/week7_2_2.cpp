#include <iostream>
#include <vector>

using namespace std;

struct node {
	int data;
	int size_n;
	node* parent;
	vector<node*> childList;
	node(int data, node* parent = nullptr) {
		this->data = data;
		size_n = 0;
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
		if (idx == -1) {
			return;
		}
		node* parNode = nodeList[idx];
		node* newNode = new node(data, parNode);
		parNode->childList.push_back(newNode);
		nodeList.push_back(newNode);
		return;
	}

	void setsize(int data, int size) {
		int idx = find(data, nodeList);
		if (idx == -1) return;

		nodeList[idx]->size_n = size;
	}

	bool postorder(node* curNode, int s) {
		bool found = false;
		for (int i = 0; i < curNode->childList.size(); i++) {
			postorder(curNode->childList[i], s);
		}
		for (int i = 0; i < curNode->childList.size(); i++) {
			curNode->size_n += curNode->childList[i]->size_n;
		}
		if (curNode->size_n > s) {
			cout << curNode->data << " ";
			found = true;
		}

		return found;
	}

	node* getRoot() {
		return root;
	}
};

int main() {
	int n, c;
	cin >> n >> c;
	Tree tree(1);

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		tree.insertNode(x, y);
		
	}
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		tree.setsize(x, y);
	}
	
	if (!tree.postorder(tree.getRoot(), c))
		cout << "-1";
	cout << '\n';

	return 0;
}
