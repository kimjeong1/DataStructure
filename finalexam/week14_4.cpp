#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[1002];
bool visited[1002];

int bfs(int start) {
    int count = 0;
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        count++;

        for (int adj : graph[v]) {
            if (!visited[adj]) {
                q.push(adj);
                visited[adj] = true;
            }
        }
    }
    return count;
}

void clear_visited(int n) {
    for (int i = 1; i <= n; ++i) {
        visited[i] = false;
    }
}

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    for (int i = 0; i < Q; ++i) {
        int C;
        cin >> C;

        clear_visited(N);
        int component_size = bfs(C);
        cout << component_size << endl;
    }

    return 0;
}
