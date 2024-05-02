#include <iostream>
#include <vector>

using namespace std;

struct compare {
	bool operator()(const int& lhs, const int& rhs) {
		return lhs < rhs;
	}
};

//비정렬
class unsortedSeqPQ {
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
		arr.push_back(e);
	}
	int top() {
		if (empty()) return -1;

		int minidx = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (C(arr[i], arr[minidx])) {
				minidx = i;
			}
		}

		return arr[minidx];
	}
	void pop() {
		if (empty()) return;

		int minidx = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (C(arr[i], arr[minidx])) {
				minidx = i;
			}
		}

		arr.erase(arr.begin() + minidx);
	}
};

//정렬
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
		vector<int> sorted;
		while (!empty()) {
			sorted.push_back(top());
			pop();
		}

		return sorted;
	}

	
};

void printSum(const vector<int>& arr) {
	for (int i = 1; i < arr.size(); i++) {
		int sum = arr[0] + arr[i];
		cout << sum << " ";
	}
	cout << endl;
}

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

		vector<int> sort = pq.insertionSort();

		for (int num : sort) {
			cout << num << " ";
		}
		cout << endl;
		
		printSum(sort);

	}

	return 0;
}
