#include <iostream>

#define INF 987654321
using namespace std;

int graph[501][501];
bool deny[501];


int main() {
    int n, m, d;
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

        bool flag = false;

        int cnt = 0;
        int score = 0;

        for (int i = 1; i <= n; i++) {
            if (deny[i]) continue;
            if (graph[k][i] != 0 && graph[k][i] <= s) {
                cnt++;
                if (graph[k][i] == 1) {
                    score += 2;
                }
                else if (graph[k][i] == 2) {
                    score += 1;
                }
                flag = true;
            }
        }

        if (cnt == 0) {
            cout << "-1";
        } else {
            cout << cnt << ' ' << score;
        }

        cout << '\n';
    }
}
