#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val; // 값
    int depth; // 깊이
    TreeNode* parent; // 부모 노드
    vector<TreeNode*> childList; // 벡터 자식 리스트

    TreeNode(int val, int depth, TreeNode* parent = nullptr) { // 생성자
        this->val = val; // 값
        this->depth = depth; // 깊이
        this->parent = parent; // 부모 노드
    }
};

class Tree {
private:
    TreeNode* root; // 뿌리
    vector<TreeNode*> childList; // 벡터 노드 리스트(자식 리스트저장)

public:
    Tree() {
        root = new TreeNode(1, 0); // 동적 할당 트리 노드 루트 값:1, 깊이:0
        childList.push_back(root); // 뿌리뒤에 자식 추가
    }

    void insertNode(int parentVal, int val) {
        int parentIdx = find(parentVal);
        if (parentIdx == -1) {
            cout << "-1\n";
            return;
        }

        if (find(val) != -1) {
            cout << "-1\n";
            return;
        }

        TreeNode* newNode = new TreeNode(val, childList[parentIdx]->depth + 1, childList[parentIdx]);
        childList[parentIdx]->childList.push_back(newNode);
        childList.push_back(newNode);
    }

    int find(int val) {
        for (int i = 0; i < childList.size(); ++i) {
            if (childList[i]->val == val) {
                return i;
            }
        }
        return -1;
    }

    int getDepth(int val) {
        int idx = find(val);
        if (idx == -1) return -1;
        return childList[idx]->depth;
    }

    int getDepthDifference(int val1, int val2) {
        int depth1 = getDepth(val1);
        int depth2 = getDepth(val2);

        if (depth1 == -1 || depth2 == -1) {
            return -1;
        }

        return depth1 - depth2;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Tree tree;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        tree.insertNode(x, y);
    }

    for (int i = 0; i < m; ++i) {
        int val1, val2;
        cin >> val1 >> val2;
        int diff = tree.getDepthDifference(val1, val2);
        cout << diff << endl;
    }

    return 0;
}
