#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
};

class link {
private:
	node* head;
	int size;
public:
	link() {
		head = nullptr;
		size = 0;
	}
	bool empty() {
		return size == 0;
	}
	void print() {
		if (empty()) {
			cout << "empty\n";
			return;
		}
		node* cur = head;
		while (cur != nullptr) {
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << "\n";
	}

	void append(int x) {
		node* newNode = new node;
		newNode->next = nullptr;
		newNode->data = x;
		if (empty()) {
			head = newNode;
		}
		else {
			node* cur = head;
			while (cur->next != nullptr) {
				cur = cur->next;
			}
			cur->next = newNode;
		}
		size++;
	}

	void Deletion(int idx) {
		if (empty() || idx >= size) {
			cout << "-1\n";
			return;
		}
		if (idx == 0) {
			node* del = head;
			head = head->next;
			cout << del->data << "\n";
			delete del;
			size--;
		}
		else {
			node* cur = head;
			for (int i = 0; i < idx - 1; i++) {
				cur = cur->next;
			}
			node* del = cur->next;
			cur->next = cur->next->next;
			cout << del->data << "\n";
			delete del;
			size--;
		}
	}

	void aftermax(int idx) {
		if (empty() || idx >= size)
			cout << "error\n";
		else {
			node* cur = head;
			for (int i = 0; i < idx; i++) {
				cur = cur->next;
			}
			int m = cur->data;
			while (cur != nullptr) {
				if (m < cur->data) {
					m = cur->data;
				}
				cur = cur->next;
			}
			cout << m << "\n";
		}
	}

	void sum() {
		if (empty())
			cout << "0\n";
		else {
			node* cur = head;
			int s = 0;
			while (cur != nullptr) {
				s += cur->data;
				cur = cur->next;
			}
			cout << s << "\n";
		}
	}

};

int main() {
	int m;
	cin >> m;
	link l;

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		int x;
		if (s == "Print") {
			l.print();
		}
		else if (s == "Append") {
			cin >> x;
			l.append(x);
			l.print();
		}
		else if (s == "Delete") {
			cin >> x;
			l.Deletion(x);
		}
		else if (s == "AfterMax") {
			cin >> x;
			l.aftermax(x);
		}
		else if (s == "Sum") {
			l.sum();
		}
	}

	return 0;
}
