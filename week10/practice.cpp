#include <iostream>
#include <vector>

using namespace std;

struct compare {
	bool operator()(const int& lhs, const int& rhs) {
		return lhs < rhs;
	}
};

class heap {
private:
	compare C;
	vector<int> arr;

	void swap(int i1, int i2) {
		arr[0] = arr[i1];
		arr[i1] = arr[i2];
		arr[i2] = arr[0];
	}
	void upheap(int i) {
		if (i == 1) return;

		int parent = i / 2;
		if (!C(arr[parent], arr[i])) {
			swap(parent, i);
			upheap(parent);
		}

	}
	void downheap(int i) {
		int left = 2 * i;
		int right = 2 * i + 1;
		int child;

		if (left > size()) {
			return;
		}
		else if (left == size()) {
			child = left;
		}
		else {
			if (C(arr[left], arr[right]))
				child = left;
			else child = right;
		}

		if (!C(arr[i], arr[child)) {
			swap(child, i);
			downheap(child);
		}
	}

public:
	heap() {
		arr.push_back(0);
	}
	int size() {
		return arr.size() - 1;
	}
	bool empty() {
		return size() == 0;
	}
	void push(int e) {
		arr.push_back(e);
		upheap(size());
	}
	int top() {
		if (empty()) return -1;

		return arr[1];
	}
	void pop() {
		if (empty()) return;

		swap(1, size());
		arr.pop_back();
		downheap(1);
	}

};

int main() {

	return 0;
}
