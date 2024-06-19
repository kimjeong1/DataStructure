#include <iostream>
#include <vector>

using namespace std;

struct compare {
    bool operator()(const int& lhs, const int& rhs){
        return lhs>rhs;
    }
};

class pqsort {
private:
    vector<int> pq;
    compare C;
    int level;


public:
    pqsort() {
        pq.clear();
        level = 0;
    }
    void insert(vector<int>& v, int n) {
        int size = v.size();
        for(int i = 0; i<size; i++) {
            int idx;
            for(idx = 0; idx<pq.size(); idx++) {
                if(C(pq[idx], v[0])) break;
            }
            pq.insert(pq.begin()+idx, v[0]);
            v.erase(v.begin());
            level++;
            if(level == n) {
                cout << "S : ";
                for(int j = 0; j<v.size(); j++) {
                    cout << v[j] << ' ';
                }
                cout << "\nPQ : ";
                for(int j = 0; j<pq.size(); j++) {
                    cout << pq[j] << ' ';
                }
                cout << '\n';
                return;
            }
        }
        v.clear();
        for(int i = 0; i<size; i++) {
            v.push_back(pq.back());
            pq.pop_back();
            level++;
            if(level == n) {
                cout << "S : ";
                for(int j = 0; j<v.size(); j++) {
                    cout << v[j] << ' ';
                }
                cout << "\nPQ : ";
                for(int j = 0; j<pq.size(); j++) {
                    cout << pq[j] << ' ';
                }
                cout << '\n';
                return;
            }
        }
    }
    
};

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> s;
        pqsort pq;

        for(int i = 0; i<n; i++) {
            int x;
            cin >> x;
            s.push_back(x);
        }

        int level;
        cin >> level;
        pq.insert(s, level);
    }

    return 0;
}
