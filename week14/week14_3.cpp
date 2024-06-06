#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[1002];
int visit[1002];
int cnt;

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visit[v] = ++cnt;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int adj : graph[cur]) {
            if (visit[adj])continue;
            q.push(adj);
            visit[adj] = ++cnt;
        }
    }

}

void clear(int n) {
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        visit[i] = 0;
    }
}



int main() {
    int n, m, q;
    int cnt;
    cin >> n >> m >> q;

    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        bfs(a);
        cout << visit[b] << '\n';
        clear(n);
    }
}
/*
6 6 4
1 5
5 2
1 2
1 3
2 4
3 6
2 1
2 6
3 6
1 4
 */
