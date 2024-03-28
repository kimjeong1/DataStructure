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
	int front() {
		if (!isEmpty()) return head->data;
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
	int n;
	int x;

	linkqueue q1;

	cin >> t;


	for (int i = 0; i < t; i++) {
		cin >> n;
		linkqueue q1;
		linkqueue q2;
		
		for (int j = 0; j < n; j++) {
			cin >> x;
			q1.enqueue(x);
		}

		for (int j = 0; j < n; j++) {
			cin >> x;
			q2.enqueue(x);
		}

		int a = q1.front();
		int b = q2.front();
		int diff = 0;
		int score1 = 0, score2 = 0;
		int abc = 0;

		for (int j = 0; j < n; j++) {
			cout << "Round" << j+1 << " ";

			a = q1.front();
			b = q2.front();

			if (abc == 1)  b += diff;
			else if (abc == 2) a += diff;
			
			if (a == b) {
				cout << "Draw\n";
				q1.dequeue();
				q2.dequeue();
				diff = 0;
			}
			else if (a > b) {
				diff = a - b;
				cout << "P1 " << diff << "\n";
				
				q1.dequeue();
				q2.dequeue();
				score1++;
				abc = 1;
			}
			else if (a < b) {
				diff = b - a;
				cout << "P2 " << diff << "\n";
				
				q1.dequeue();
				q2.dequeue();
				score2++;
				abc = 2;
			}

		}

		cout << "Total Score " << score1 << ":" << score2 << " ";
		if (score1 == score2) cout << "Draw\n";
		else if (score1 > score2) cout << "Winner P1";
		else if (score1 < score2) cout << "Winner P2";

	}

	return 0;
}
