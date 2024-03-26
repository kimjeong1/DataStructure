#include <iostream>
#include <string>

using namespace std;

struct node {
	int data;
	node* next;
};

class linkqueue {
public:
	linkqueue() {
		head = NULL;
		tail = NULL;
		listsize = 0;
	}
	int size() {
		return listsize;
	}
	bool isEmpty() {
		if (listsize == 0) return 1;
		else return 0;
	}
	void front() {
		if (!isEmpty()) cout << head->data << "\n";
		else cout << "Empty\n";
	}
	void rear() {
		if (!isEmpty())  cout << tail->data << "\n";
		else cout << "Empty\n";
	}
	void enqueue(int val) {
		node* newnode = new node();
		newnode->data = val;
		newnode->next = NULL;

		if (head == NULL) {
			head = newnode;
		}
		else {
			tail->next = newnode;
		}

		tail = newnode;
		listsize++;
		
	}
	void dequeue() {
		if (isEmpty()) cout << "Empty\n";
		else {
			front();
			node* curNode = head;
			head = head->next;
			delete curNode;
			listsize--;
		}
	}


private:
	int listsize;
	node* head;
	node* tail;

};

int main() {
	int t;
	cin >> t;

	linkqueue q;
	string s;
	int x;

	for (int i = 0; i < t; i++) {
		cin >> s;

		if (s == "size") {
			cout << q.size() << "\n";
		}
		else if (s == "isEmpty") {
			if (q.isEmpty()) cout << "True\n";
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
