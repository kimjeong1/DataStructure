#include <iostream>
#include <vector>
using namespace std;

struct Graph {
    vector<int> vertices;
    vector<pair<int, int>> edges;
};

Graph graphs[90]; // 그래프 ID 범위는 10 <= GID < 100
bool graphExists[90];

void insertVertex(int GID, int S) {
    Graph &g = graphs[GID - 10];
    for (int vertex : g.vertices) {
        if (vertex == S) {
            cout << "ERRORCODE 01" << endl;
            return;
        }
    }
    g.vertices.push_back(S);
}

void insertEdge(int GID, int S, int D) {
    Graph &g = graphs[GID - 10];
    bool foundS = false, foundD = false;
    for (int vertex : g.vertices) {
        if (vertex == S) foundS = true;
        if (vertex == D) foundD = true;
    }
    if (!foundS || !foundD) {
        cout << "ERRORCODE 03" << endl;
        return;
    }
    for (auto &edge : g.edges) {
        if ((edge.first == S && edge.second == D) || (edge.first == D && edge.second == S)) {
            cout << "ERRORCODE 02" << endl;
            return;
        }
    }
    g.edges.push_back({S, D});
}

void eraseVertex(int GID, int S) {
    Graph &g = graphs[GID - 10];
    bool found = false;
    for (size_t i = 0; i < g.vertices.size(); ++i) {
        if (g.vertices[i] == S) {
            found = true;
            g.vertices.erase(g.vertices.begin() + i);
            break;
        }
    }
    if (!found) {
        cout << "ERRORCODE 03" << endl;
        return;
    }
    for (size_t i = 0; i < g.edges.size(); ++i) {
        if (g.edges[i].first == S || g.edges[i].second == S) {
            g.edges.erase(g.edges.begin() + i);
            i--; // adjust index after erasing
        }
    }
}

void eraseEdge(int GID, int S, int D) {
    Graph &g = graphs[GID - 10];
    bool foundS = false, foundD = false, foundEdge = false;
    for (int vertex : g.vertices) {
        if (vertex == S) foundS = true;
        if (vertex == D) foundD = true;
    }
    if (!foundS || !foundD) {
        cout << "ERRORCODE 03" << endl;
        return;
    }
    for (size_t i = 0; i < g.edges.size(); ++i) {
        if ((g.edges[i].first == S && g.edges[i].second == D) || (g.edges[i].first == D && g.edges[i].second == S)) {
            g.edges.erase(g.edges.begin() + i);
            foundEdge = true;
            break;
        }
    }
    if (!foundEdge) {
        cout << "ERRORCODE 04" << endl;
    }
}

void printAdjSum(int GID, int S) {
    Graph &g = graphs[GID - 10];
    bool found = false;
    for (int vertex : g.vertices) {
        if (vertex == S) {
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "ERRORCODE 03" << endl;
        return;
    }
    int sum = 0, count = 0;
    for (auto &edge : g.edges) {
        if (edge.first == S) {
            sum += edge.second;
            count++;
        } else if (edge.second == S) {
            sum += edge.first;
            count++;
        }
    }
    cout << count << " " << sum << endl;
}

void printAdjMin(int GID, int S) {
    Graph &g = graphs[GID - 10];
    bool found = false;
    for (int vertex : g.vertices) {
        if (vertex == S) {
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "ERRORCODE 03" << endl;
        return;
    }
    int minValue = -1;
    for (auto &edge : g.edges) {
        if (edge.first == S) {
            if (minValue == -1 || edge.second < minValue) {
                minValue = edge.second;
            }
        } else if (edge.second == S) {
            if (minValue == -1 || edge.first < minValue) {
                minValue = edge.first;
            }
        }
    }
    cout << minValue << endl;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        string command;
        cin >> command;

        if (command == "Graph") {
            int GID;
            cin >> GID;
            graphExists[GID - 10] = true;
        } else if (command == "InsertVertex") {
            int GID, S;
            cin >> GID >> S;
            insertVertex(GID, S);
        } else if (command == "InsertEdge") {
            int GID, S, D;
            cin >> GID >> S >> D;
            insertEdge(GID, S, D);
        } else if (command == "EraseVertex") {
            int GID, S;
            cin >> GID >> S;
            eraseVertex(GID, S);
        } else if (command == "EraseEdge") {
            int GID, S, D;
            cin >> GID >> S >> D;
            eraseEdge(GID, S, D);
        } else if (command == "PrintAdjSum") {
            int GID, S;
            cin >> GID >> S;
            printAdjSum(GID, S);
        } else if (command == "PrintAdjMin") {
            int GID, S;
            cin >> GID >> S;
            printAdjMin(GID, S);
        }
    }

    return 0;
}
