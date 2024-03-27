
#include <iostream>
#include <string>

using namespace std;

class arrayqueue {
public:
	arrayqueue(int capacity) {
		arr = new int[capacity];
		this->capacity = capacity;
		f = 0;
		r = -1;
	}

	int size() {
		arrsize = r - f + 1;
		if (arrsize < 0) arrsize *= -1;
		return arrsize;
	}
	bool isEmpty() {
		if (size() == 0) return 1;
		else return 0;
	}
	int full() {
		if (size() == capacity) return 1;
		else return 0;
	}
	void front() {
		if (!isEmpty()) cout << arr[f] << "\n";
		else cout << "Empty\n";
	}
	void rear() {
		if (!isEmpty()) cout << arr[r] << "\n";
		else cout << "Empty\n";
	}
	void enqueue(int val) {
		if (full()) cout << "Full\n";
		else {
			arr[++r] = val;
		}
	}
	void dequeue() {
		if (isEmpty()) cout << "Empty\n";
		else {
			front();
			f += 1;
		}
	}

private:
	int* arr;
	int capacity;
	int arrsize;
	int f;
	int r;

};

int main() {
	int z, n;
	cin >> z >> n;

	string s;
	arrayqueue q(z);
	int x;

	for (int i = 0; i < n; i++) {
		cin >> s;

		if (s == "size") {
			cout << q.size() <<"\n";
		}
		else if (s == "isEmpty") {
			if (q.isEmpty())cout << "True\n";
			else cout << "False\n";
		}
		else if (s == "full") {
			if (q.full())cout << "True\n";
			else cout << "False\n";
		}
		else if (s == "front") {
			q.front();
		}
		else if (s == "rear") {
			q.rear();
		}
		else if (s == "enqueue") {
			cin >> x;
			q.enqueue(x);
		}
		else if (s == "dequeue") {
			q.dequeue();
		}

	}

	return 0;
}

