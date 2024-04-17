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
	int depth;
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
	void deleteNode(int data) {
		int idx = find(data, nodeList);
		if (idx == -1)
			return;

		node* delNode = nodeList[idx];
		if (delNode == root)
			return;

		node* parNode = delNode->parent;
		for (int i = 0; i < delNode->childList.size(); i++) {
			parNode->childList.push_back(delNode->childList[i]);
			delNode->childList[i]->parent = parNode;
		}

		vector<node*>& child = parNode->childList;
		child.erase(child.begin() + find(data, child));
		nodeList.erase(nodeList.begin() + idx);
		delete delNode;
	}
	void printParent(int data) {
		int idx = find(data, nodeList);
		if (idx <= 0)
			return;

		node* curNode = nodeList[idx];
		cout << curNode->parent->data << "\n";
	}
	void printChild(int data) {
		int idx = find(data, nodeList);
		if (idx == -1)
			return;

		vector<node*>& child = nodeList[idx]->childList;
		if (child.empty())
			return;

		for (int i = 0; i < child.size(); i++) {
			cout << child[i]->data << " ";
		}
		cout << "\n";
	}

	int getdepth(int data) {
		int idx = find(data, nodeList);
		if (idx == -1)
			return -1;

		return nodeList[idx]->depth;
	}

	int getchildsize(int data) {
		int idx = find(data, nodeList);
		if (idx == -1)
			return -1;

		return nodeList[idx]->childList.size();
	}

	void preOrderTraversal(node* n) {
		if (n->childList.empty())
			cout << n->depth << ' ';
		else
			cout << n->childList.size() << ' ';
		for (node* child : n->childList) {
			preOrderTraversal(child);
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

		for (int j = 0; j < n -1; j++) {
			int x, y;
			cin >> x >> y;
			tree.insertNode(x, y);
		}
		tree.preOrderTraversal(tree.getRoot());
	}

	return 0;
}
