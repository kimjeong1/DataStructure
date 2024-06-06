
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
    ans = ans < v ? v : ans;
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
    int n, m, q, t;
    
    cin >> t;
    while (t--) {
        cin >> n >> m >> q;
        while (m--) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
        }

        while (q--) {
            int a;
            cin >> a;
            //dfs(a);
            bfs(a);
            cout << ans << '\n';
            clear(n);
        }
    }
}



/*
1
12 18 6
1 4
4 3
3 1
3 2
4 2
6 4
5 6
10 1
5 10
5 12
5 11
11 5
7 8
8 9
9 7
8 7
7 9
9 8
1
7
5
2
12
11
 */
