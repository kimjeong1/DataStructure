#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int n = 1005;
vector<int> edge[n];
bool visit[n];

void insertEdge(int srcVertexId, int dstVertexId) {
    edge[srcVertexId].push_back(dstVertexId);
    edge[dstVertexId].push_back(srcVertexId);
}

void DFS(int curVertexId) {
    visit[curVertexId] = true;
    for (int i = 0; i < edge[curVertexId].size(); i++) {
        int nextVertexId = edge[curVertexId][i];
        if (!visit[nextVertexId]) {
            DFS(nextVertexId);
        }
    }
}

void BFS(int vertexId) {
    queue<int> que;
    que.push(vertexId);
    visit[vertexId] = true;
    while (!que.empty()) {
        int curVertexId = que.front();
        que.pop();
        for (int i = 0; i < edge[curVertexId].size(); i++) {
            int nextVertexId = edge[curVertexId][i];
            if (!visit[nextVertexId]) {
                que.push(nextVertexId);
                visit[nextVertexId] = true;
            }
        }
    }
}

int main() {
    insertEdge(1, 2);
    insertEdge(1, 3);
    insertEdge(2, 4);
    insertEdge(3, 4);

    cout << "DFS 방문 순서: ";
    DFS(1);
    for (int i = 1; i <= 4; ++i) {
        if (visit[i]) cout << i << " ";
    }
    cout << endl;

    fill(begin(visit), end(visit), false);

    cout << "BFS 방문 순서: ";
    BFS(1);
    for (int i = 1; i <= 4; ++i) {
        if (visit[i]) cout << i << " ";
    }
    cout << endl;

    return 0;
}
