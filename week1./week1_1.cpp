#include <iostream>

using namespace std;

class arr {
private:
	int* a;
	int capacity;
	int idx;

public:
	arr(int c) {
		a = new int[c];
		idx = -1;
		this->capacity = c;
		for (int i = 0; i < capacity; i++) {
			a[i] = 0;
		}
	}
	void at(int i) {
		cout << a[i] << "\n";
	}
	void add(int k, int z) {
		for (int i = capacity-2; i > k-1; i--) {
			a[i + 1] = a[i];
		}
		a[k] = z;
	}
	void remove(int k) {
		for (int i = k+1; i < capacity; i++) {
			a[i-1] = a[i];
		}
		a[capacity-1] = 0;
	}
	void set(int k, int z) {
		a[k] = z;
	}
	void count(int z) {
		int count = 0;
		for (int i = 0; i < capacity; i++) {
			if (a[i] == z) {
				count++;
			}
		}
		cout << count << "\n";
	}
	void print() {
		for (int i = 0; i < capacity; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
	}


};

int main() {
	int t, n;
	cin >> t >> n;

	arr ar(n);

	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;

		if (s == "at") {
			int i;
			cin >> i;
			ar.at(i);
		}
		else if (s == "add") {
			int i, z;
			cin >> i >> z;
			ar.add(i, z);
		}
		else if (s == "remove") {
			int i;
			cin >> i;
			ar.remove(i);
		}
		else if (s == "set") {
			int i, z;
			cin >> i >> z;
			ar.set(i, z);
		}
		else if (s == "count") {
			int z;
			cin >> z;
			ar.count(z);
		}
		else if (s == "print") {
			ar.print();
		}
	}
	return 0;
}
