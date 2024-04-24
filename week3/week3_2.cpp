#include <iostream>
#include <string>

using namespace std;

class Stackarr {
public:
    int data[100];
    int top = -1;

    bool isEmpty() {
        return top == -1;
    }

    void push(int x) {
        data[++top] = x;
    }

    int pop() {
        return data[top--];
    }

    int peek() {
        return data[top];
    }
};

// 연산 함수
int op(int x, char c, int y) {
    switch (c) {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        int K;
        cin >> s >> K;

        Stackarr stk;

        for (char ch : s) {
            if (isdigit(ch)) {
                stk.push(ch - '0');
            }
            else {
                int y = stk.pop();
                int x = stk.pop();
                int result = op(x, ch, y);
                stk.push(result);
            }
        }

        int r = stk.pop();

        if (r < 0) r *= -1;

        cout << r % K << "\n";
    }

    return 0;
}


/*
#include<iostream>
#include<string>
using namespace std;

//스택자료구조
struct Node {
    int data;
    Node* next;
    Node* prev;
};
class LinkedLIstStack {
private:
    int stackSize;
    Node* head;
    Node* tail;
public:
    LinkedLIstStack() {
        stackSize = 0;
        head = NULL;
        tail = NULL;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            tail->next = NULL;
            stackSize++;
        }
        else {
            newNode->next = head;
            head = newNode;
            stackSize++;
        }
    }
    int pop() {
        if (head == NULL) {
            return -1;
        }
        else {
            int data = head->data;
            Node* curNode = head;
            head = head->next;
            stackSize--;
            delete curNode;
            return data;

        }
    }
    bool empty() {
        if (head == NULL) {
            return true;

        }
        else {
            return false;
        }
    }
    int top() {
        if (head == NULL)
            return -1;
        else {
            return head->data;
        }
    }
    int size() {
        return stackSize;
    }

};
int main() {

    int n;
    cin >> n;
    while (n--) {
        LinkedLIstStack LStack;
        string stk;
        int k;
        cin >> stk >> k;
        int size = stk.size();
        for (int i = 0; i < size; i++) {
            if (isdigit(stk[i])) {
                int num = stk[i] - '0';
                LStack.push(num);
            }
            else {
                if (stk[i] == '*') {
                    int op2 = LStack.pop();
                    int op1 = LStack.pop();
                    int sum = op1 * op2;
                    LStack.push(sum);
                }
                else if (stk[i] == '/') {
                    int op2 = LStack.pop();
                    int op1 = LStack.pop();
                    int sum = op1 / op2;
                    LStack.push(sum);
                }
                else if (stk[i] == '-') {
                    int op2 = LStack.pop();
                    int op1 = LStack.pop();
                    int sum = op1 - op2;
                    LStack.push(sum);
                }
                else if (stk[i] == '+') {
                    int op2 = LStack.pop();
                    int op1 = LStack.pop();
                    int sum = op1 + op2;
                    LStack.push(sum);
                }
            }
        }
        //cout << LStack.pop() << '\n';
        int result = LStack.pop();
        if (result < 0) {
            result *= -1;
        }
        cout << result % k << '\n';

    }
}
*/
