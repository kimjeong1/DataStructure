#include <iostream>
#include <vector>

using namespace std;

struct compare {
	bool operator()(const int& lhs, const int& rhs) {

		int count = 0;
		int l = lhs;
		int r = rhs;
		while (1) {
			l /= 10;
			r /= 10;
			if (l == 0 || r == 0) break;

		}
		if (l == 0 && r == 0) return lhs > rhs;

		else return lhs < rhs;
	}
};

class sortedSeqPQ {
private:
	compare C;
	vector<int> arr;
public:
	int size() {
		return arr.size();
	}
	bool empty() {
		return size() == 0;
	}

	void push(int e) {
		int idx;
		for (idx = 0; idx < arr.size(); idx++) {
			if (C(arr[idx], e)) break;
		}
		arr.insert(arr.begin() + idx, e);
	}
	int top() {
		if (empty()) return -1;

		return arr.back();
	}
	void pop() {
		if (empty()) return;

		arr.pop_back();
	}
	vector<int> insertionSort() {
		vector<int> sort;
		while (!empty()) {
			sort.push_back(top());
			pop();
		}
		return sort;
	}
};

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		sortedSeqPQ pq;



		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			pq.push(x);
		}


		cout << "Case #" << i + 1 << ".\n";


		vector<int> s = pq.insertionSort();
		for (int num : s) {
			cout << num << ' ';
		}

		cout << "\n";

	}

	return 0;
}
