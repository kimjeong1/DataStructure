#include <iostream>
#include <vector>

using namespace std;

struct node {
	int data;
	int depth;
	node* parent;
	vector<node*> childList;
	node(int data,int depth, node* parent = nullptr) {
		this->data = data;
		this->depth = depth;
		this->parent = parent;
	}
};

class Tree {
private:
	node* root;
	vector<node*> childList;
public:
	Tree() {
		root = new node(1, 0);
		childList.push_back(root);
	}
	void insertnode(int pval, int val) {
		int pidx = find(pval);
		if (pidx == -1) {
			cout << "-1\n";
			return;
		}

		if (find(val) != -1) {
			cout << "-1\n";
			return;
		}

		
		node* newnode = new node(val, childList[pidx]->depth + 1, childList[pidx]);
		childList[pidx]->childList.push_back(newnode);
		childList.push_back(newnode);
	}


	int find(int val) {
		for (int i = 0; i < childList.size(); i++) {
			if (childList[i]->data == val) return i;
		}
		return -1;
	}
	int getdepth(int val) {
		int idx = find(val);
		if (idx == -1) return -1;
		return childList[idx]->depth;
	}
	int diffdepth(int val1 , int val2) {
		int depth1 = getdepth(val1);
		int depth2 = getdepth(val2);

		if (depth1 == -1 || depth2 == -1) return -1;

		return depth1 + depth2;
	}
};

int main() {
	int n, m;
	Tree tree;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		tree.insertnode(x, y);
	}

	for (int i = 0; i < m; i++) {
		int v, w;
		cin >> v >> w;
		cout << tree.diffdepth(v, w) << "\n";
	}

	return 0;
}
