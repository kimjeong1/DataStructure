//실습 예제코드
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
	void insertNode(int pardata, int data) {
		if (find(data, nodeList) != -1) return;

		int idx = find(pardata, nodeList);
		if (idx == -1) {
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
		if (idx <= 0) return;

		node* curNode = nodeList[idx];
		cout << curNode->parent->data << "\n";
	}
	void printChild(int data) {
		int idx = find(data, nodeList);
		if (idx == -1) return;

		vector<node*>& child = nodeList[idx]->childList;
		if (child.empty()) return;

		for (int i = 0; i < child.size(); i++) {
			cout << child[i]->data << " ";
		}
		cout << "\n";
	}

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
};

int main() {

	return 0;
}
