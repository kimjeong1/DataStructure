#include <iostream>
#include <string>

using namespace std;

struct stack {
	int data[100];
	int top = -1;
	int max_size = -1;

	bool empty() {
		return top == -1;
	}

	void push(int x) {
		data[++top] = x;
		if (max_size < top) {
			max_size = top;
		}
	}

	int pop() {
		return data[top--];
	}

	int peek() {
		return data[top];
	}
};

int precedence(char op) {
	if (op == '*')return 2;
	if (op == '+' || op == '-') return 1;
	return 0;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)	{
		stack stk;
		string s;
		cin >> s;

		string result = "";
		for (char ch : s) {
			if (isalnum(ch)) {
				result += ch;
			}
			else {
				while (!stk.empty() && precedence(stk.peek()) >= precedence(ch)) {
					result += stk.pop();
				}

				stk.push(ch);
			}
		}

		while (!stk.empty()) {
			result += stk.pop();
		}
		cout << result << " " << stk.max_size+1 << "\n";
	}

	return 0;
}
