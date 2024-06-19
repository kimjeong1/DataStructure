#include <iostream>
#include <vector>

using namespace std;

struct compare {
	bool operator()(const int& lhs, const int& right) {
		return lhs < right;
	}
};

class unsortedPQ {
private:
	vector<int> pq;
	compare C;
	int level;
public:
	unsortedPQ() {
		pq.clear();
		level = 0;
	}
	void solve(vector<int>& v, int n) {
		int size = v.size();
		for (int i = 0; i < size; i++) {
			pq.push_back(v[0]);
			v.erase(v.begin());
			level++;
			if (level == n) {
				cout << "S : ";
				for (int j = 0; j < v.size(); j++)
					cout << v[j] << ' ';
				cout << "\nPQ : ";
				for (int j = 0; j < pq.size(); j++)
					cout << pq[j] << ' ';
				cout << '\n';
				return;
			}
		}
		v.clear();
		for (int i = 0; i < size; i++) {
			int max_index = 0;
			for (int j = 0; j < size-i; j++)
				if (C(pq[max_index], pq[j])) max_index = j;
			v.push_back(pq[max_index]);
			pq.erase(pq.begin() + max_index);
			level++;
			if (level == n) {
				cout << "S : ";
				for (int j = 0; j < v.size(); j++)
					cout << v[j] << ' ';
				cout << "\nPQ : ";
				for (int j = 0; j < pq.size(); j++)
					cout << pq[j] << ' ';
				cout << '\n';
				return;
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, input, level;
	cin >> T;
	while (T--) {
		vector <int> S;
		unsortedPQ pq;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> input;
			S.push_back(input);
		}
		cin >> level;
		pq.solve(S, level);
	}
}
