#include <iostream>

using namespace std;

int graph[501][501];
bool link[501][501];

int main() {
    int n, m, d;

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

    // Ensure indirect connections are marked with 2
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

        int score = 0;
        int cnt = 0;

        bool flag = false;

        if (s == 1) {
            for (int i = 1; i <= n; i++) {
                if (graph[k][i] == 1) {
                    if (!link[k][i]) {
                        cnt++;
                        score += 3;
                        flag = true;
                    }
                } else {
                    for (int j = 1; j <= n; j++) {
                        if (i != k && graph[k][j] == 1 && link[j][i]) {
                            cnt++;
                            score += 1;
                            flag = true;
                        }
                    }
                }
            }
        } else {
            for (int i = 1; i <= n; i++) {
                if (graph[k][i] == 1) {
                    if (!link[k][i]) {
                        cnt++;
                        score += 3;
                        flag = true;
                    }
                } else if (graph[k][i] == 2) {
                    if (!link[k][i]) {
                        cnt++;
                        score += 2;
                        flag = true;
                    }
                } else {
                    for (int j = 1; j <= n; j++) {
                        if (i == k || !link[i][j]) continue;
                        if (graph[k][j] == 1 || graph[k][j] == 2) {
                            cnt++;
                            score += 1;
                            flag = true;
                        }
                    }
                }
            }
        }

        if (!flag) {
            cout << "-1\n";
        } else {
            cout << cnt << ' ' << score << '\n';
        }
    }

    return 0;
}
