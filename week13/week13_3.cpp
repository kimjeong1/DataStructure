#include <iostream>
#include <vector>

using namespace std;

int t;
pair<bool, int> vertices[10002]; // 노드가 있는지, 간선의 개수
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

void isAdjacentEven(int s) {
    if (vertices[s].second % 2 == 0) {
        cout << "True " << vertices[s].second << '\n';
        return;
    }
    cout << "False " << vertices[s].second << '\n';;
}

void maxEdgeVertex() {
    pair<int, int> ans = make_pair(-1, 0);
    for (int i = 0; i <= 10000; i++) {
        if (!vertices[i].first) continue;
        if (vertices[i].second > ans.second) {
            ans.first = i;
            ans.second = vertices[i].second;
        }
    }

    cout << ans.first << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
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
        else if (cmd == "eraseEdge") {
            cin >> s >> d;
            eraseEdge(s, d);

        }
        else if (cmd == "isAdjacentEven") {
            cin >> s;
            isAdjacentEven(s);

        }
        else if (cmd == "maxEdgeVertex") {
            maxEdgeVertex();
        }

    }
}
