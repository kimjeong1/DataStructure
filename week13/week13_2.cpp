#include <iostream>

using namespace std;

int graph[501][501];
bool link[501][501];
int n, m, d;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> d;
    while (d--) {
        int a, b;
        cin >> a >> b;
        link[a][b] = true;
        link[b][a] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] == 1) {
                for (int k = 1; k <= n; k++) {
                    if (graph[j][k] == 1 && graph[i][k] != 1 && k != i) {
                        graph[i][k] = 2;
                        graph[k][i] = 2;
                    }
                }
            }
        }
    }

    while (m--) {
        int k, s;
        cin >> k >> s;

        int flag = false;
        if (s == 1) {
            for (int i = 1; i <= n; i++) {
                if (graph[k][i] == 1) {
                    if (!link[k][i]) {
                        cout << i << ' ';
                        flag = true;
                    }
                }
                else {
                    for (int j = 1; j <= n; j++) {
                        if (i != k && graph[k][j] == 1 && link[j][i] == 1) {
                            cout << i << ' ';
                            flag = true;
                        }
                    }
                }
            }
        }
        else {
            for (int i = 1; i <= n; i++) {
                if (graph[k][i] == 1 || graph[k][i] == 2) {
                    if (!link[k][i]) {
                        cout << i << ' ';
                        flag = true;
                    }
                }
                else {
                    for (int j = 1; j <= n; j++) {
                        if (i == k || !link[i][j]) continue;
                        if (graph[k][j] == 1 || graph[k][j] == 2) {
                            cout << i << ' ';
                            flag = true;
                        }
                    }
                }
            }
        }
        if (!flag) {
            cout << '0';
        }

        cout << '\n';
    }
}
/*
7 3 2
1 3
2 4
0 1 0 0 0 1 1
1 0 0 0 0 0 1
0 0 0 1 1 0 1
0 0 1 0 1 0 0
0 0 1 1 0 1 0
1 0 0 0 1 0 1
1 1 1 0 0 1 0
1 2
6 1
7 1
 */
