#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[1002];
bool visit[1002];
int ans;

void dfs(int v) {
    if (visit[v])return;
    visit[v] = true;
    if (ans > v) {
        ans = v;
    }
    for (int adj : graph[v]) {
        dfs(adj);
    }
}

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visit[v] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ans = ans < cur ? cur : ans;
        for (int adj : graph[cur]) {
            if (visit[adj]) continue;
            q.push(adj);
            visit[adj] = true;
        }
    }
}

void clear(int n) {
    ans = 0;
    for (int i = 1; i <= n; i++) {
        visit[i] = false;
    }
}


int main() {
    int n, m, q;
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

        bfs(a);
        int x = ans;
        clear(n);
        bfs(b);
        int y = ans;
        clear(n);

        if (x == y) cout << "True\n";
        else cout << "False\n";
    }

}
