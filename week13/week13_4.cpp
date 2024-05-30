#include <iostream>

#define INF 987654321
using namespace std;

int graph[501][501];
bool deny[501];
int n, m, d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> d;
    while (d--) {
        int a;
        cin >> a;
        deny[a] = true;

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
                    if (k == i)continue;
                    if (graph[i][k] == 1)continue;
                    if (graph[j][k] == 1) {
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

        for (int i = 1; i <= n; i++) {
            if (deny[i])continue;
            if (graph[k][i] != 0 && graph[k][i] <= s) {
                cout << i << ' ';
                flag = true;
            }
        }

        if (!flag) {
            cout << '0';
        }

        cout << '\n';
    }
}
/*
7 4 2
1 3
0 1 0 0 0 1 1
1 0 0 0 0 0 1
0 0 0 1 1 0 1
0 0 1 0 1 0 0
0 0 1 1 0 1 0
1 0 0 0 1 0 1
1 1 1 0 0 1 0
1 2
5 1
6 1
7 2
 */
