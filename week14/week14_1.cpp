
#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[1002];
int visited[1002];

int cnt;

void dfs(int v) {
    if (visited[v]) return;
    visited[v] = ++cnt;
    for (int adj : graph[v]) {
        dfs(adj);
    }
}

void clear(int n) {
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }
}

int main() {
    int n, m, q; // n = 정점, m = 간선, q = 질의의 개수
    cin >> n >> m >> q;
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        dfs(a);
        cout << visited[b] << '\n';
        clear(n);
    }
}
