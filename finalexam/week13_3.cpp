#include <iostream>
#include <vector>

using namespace std;

pair<bool, int> vertices[10002];
bool graph[10002][10002];

void insertVertex(int s) {
    if (vertices[s].first) {
        cout << "Exist\n";
        return;
    }
    vertices[s].first = true;
}

void insertEdge(int s, int d) {
    if (graph[s][d]) {
        cout << "Exist\n";
        return;
    }
    graph[s][d] = true;
    graph[d][s] = true;
    vertices[s].second++;
    vertices[d].second++;
}

void eraseVertex(int s) {
    vertices[s].first = false;
    for (int i = 1; i <= 10000; i++) {
        if (graph[s][i]) {
            graph[s][i] = false;
            vertices[s].second--;
        }
        if (graph[i][s]) {
            graph[i][s] = false;
            vertices[i].second--;
        }

    }
}

void eraseEdge(int s, int d) {
    if (!graph[s][d]) {
        cout << "None\n";
        return;
    }
    graph[s][d] = false;
    graph[d][s] = false;
    vertices[s].second--;
    vertices[d].second--;
}

void isAdjacent(int s, int d) {
    if (graph[s][d] == true) {
        cout << "True ";
    }
    else {
        cout << "False ";
    }
    if (vertices[s].second == vertices[d].second) cout << max(s, d) << '\n';
    else if (vertices[s].second > vertices[d].second) cout << s << '\n';
    else cout << d << '\n';
}

void maxVertexInfo() {
    pair<int, int> ans = make_pair(-1, 0);
    for (int i = 0; i <= 10000; i++) {
        if (!vertices[i].first) continue;
        ans.first = i;
        ans.second = vertices[i].second;
    }

    if (ans.first == -1) cout << "-1\n";
    else cout << ans.first << ' ' << ans.second << '\n';
}

int main() {
    int t;

    cin >> t;

    for (int i = 0; i < t; i++) {
        string cmd;
        int s, d;
        cin >> cmd;
        if (cmd == "insertVertex") {
            cin >> s;
            insertVertex(s);

        }
        else if (cmd == "insertEdge") {
            cin >> s >> d;
            insertEdge(s, d);

        }
        else if (cmd == "eraseVertex") {
            cin >> s;
            eraseVertex(s);
        }
        else if (cmd == "eraseEdge") {
            cin >> s >> d;
            eraseEdge(s, d);

        }
        else if (cmd == "isAdjacent") {
            cin >> s >> d;
            isAdjacent(s, d);

        }
        else if (cmd == "maxVertexInfo") {
            maxVertexInfo();
        }
    }

    return 0;
}
