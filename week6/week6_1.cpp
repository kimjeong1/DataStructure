#include <iostream>
#include <vector>

using namespace std;

struct node {
	int data;
	node* parent;
	vector<node*> childList;
	node(int data, node* parent) {
		this->data = data;
		this->parent = parent;
	}
};

class Tree {
public:
	Tree(int data) {
		root = new node(data, NULL);
		nodeList.push_back(root);
	}
	void insertNode(int parData, int data) {
		if (find(data, nodeList) != -1) {
			cout << "-1\n";
			return;
		}

		int idx = find(parData, nodeList);
		if (idx == -1) {
			cout << "-1\n";
			return;
		}

		node* parNode = nodeList[idx];
		node* newNode = new node(data, parNode);
		parNode->childList.push_back(newNode);
		nodeList.push_back(newNode);
	}
	void deleteNode(int data) {
		int idx = find(data, nodeList);
		if (idx == -1) return;

		node* delNode = nodeList[idx];
		if (delNode == root) return;

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
		if (idx <= 0) {
			cout << "-1\n";
			return;
		}

		node* curNode = nodeList[idx];
		cout << curNode->parent->data << "\n";
	}
	void printChild(int data) {
		int idx = find(data, nodeList);
		if (idx == -1) {
			cout << "-1\n";
		}

		vector<node*>& child = nodeList[idx]->childList;
		if (child.empty()) {
			cout << "-1\n";
		}

		for (int i = 0; i < child.size(); i++) {
			cout << child[i]->data << " ";
		}
		cout << "\n";
	}

	void printMinMaxChild(int data) {
		int idx = find(data, nodeList);
		if (idx == -1 || nodeList[idx]->childList.size() < 2) {
			cout << "-1\n";
			return;
		}

		int minVal = nodeList[idx]->childList[0]->data;
		int maxVal = nodeList[idx]->childList[0]->data;

		for (int i = 1; i < nodeList[idx]->childList.size(); i++) {
			int childData = nodeList[idx]->childList[i]->data;
			if (childData < minVal) minVal = childData;
			if (childData > maxVal) maxVal = childData;
		}

		cout << minVal + maxVal << "\n";
	}

private:
	node* root;
	vector<node*> nodeList;
	int find(int data, vector<node*>& List) {
		for (int i = 0; i < List.size(); i++) {
			if (List[i]->data == data) return i;
		}
		return -1;
	}

};

int main() {
	int t;
	cin >> t;
	string s;
	int x, y;

	Tree tree(1);

	for (int i = 0; i < t; i++) {
		cin >> s;

		if (s == "insert") {
			cin >> x >> y;
			tree.insertNode(x, y);
		}
		else if (s == "delete") {
			cin >> x;
			tree.deleteNode(x);
		}
		else if (s == "parent") {
			cin >> x;
			tree.printParent(x);
		}
		else if (s == "child") {
			cin >> x;
			tree.printChild(x);
		}
		else if (s == "min_maxChild") {
			cin >> x;
			tree.printMinMaxChild(x);
		}
	}

	return 0;
}
