#include <iostream>

using namespace std;
class arr {
private:
	int* a;
	int capacity;
public:
	arr(int n) {
		a = new int[n];
		this->capacity = n;
		for (int i = 0; i < n; i++) {
			a[i] = i;
		}
	}

	void print() {
		for (int i = 0; i < capacity; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
	}

	void shift(int x, int y) {
		int tmp = a[x];
		for (int i = x; i < y; i++) {
			a[i] = a[i+1];
		}
		a[y] = tmp;
	}
	void swap(int x, int y) {
		int tmp = a[x];
		a[x] = a[y];
		a[y] = tmp;
	}
};

int main() {
	int t, n;
	cin >> t >> n;

	arr ar(n);

	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;

		if (s == "print") {
			ar.print();
		}
		else if (s == "shift")
		{
			int i, j;
			cin >> i >> j;
			ar.shift(i, j);
		}
		else if (s == "swap") {
			int i, j;
			cin >> i >> j;
			ar.swap(i, j);
		}
	}

	return 0;
}
