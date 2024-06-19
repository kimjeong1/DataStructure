#include <iostream>
#include <string>

using namespace std;

#define no_item 0
#define log_out 1
#define log_in 2

struct entry {
	int valid;
	string id, pwd;
	entry(string s, string p) {
		id = s;
		pwd = p;
		valid = log_out;
	}
	entry() {
		id = pwd = "";
		valid = no_item;
	}
};
class hashtable {
	int capacity,login_cnt;
	entry* table;
	int hash(int k) {
		return k % capacity;
	}
	int pow(int a, int n) {
		int result = 1;
		for (int i = 0; i < n; i++)
			result *= a;
		return result;
	}
	int toInt(string s) {
		int result = 0;
		for (int i = 0; i < s.length(); i++)
			result += ((s[i] - 'a') * pow(26, i));
		return result;
	}
public:
	hashtable() {
		capacity = 200003;
		table = new entry[capacity];
		login_cnt = 0;
	}
	void signup(string s, string p) {
		int idx = hash(toInt(s));
		int cnt = 1;
		while (table[idx].valid != no_item && cnt <= capacity) {
			if (table[idx].id == s) {
				cout << "Invalid\n";
				return;
			}
			idx = hash(idx + 1);
			cnt++;
		}
		table[idx] = entry(s, p);
		cout << "Submit\n";
	}
	void login(string s, string p) {
		int idx = hash(toInt(s));
		int cnt = 1;
		while (table[idx].valid != no_item && cnt <= capacity) {
			if (table[idx].id == s) {
				if (table[idx].pwd != p) {
					cout << "Invalid\n";
					return;
				}
				else {
					if (table[idx].valid == log_in) {
						cout << "Already\n";
						return;
					}
					else {
						cout << "Submit\n";
						table[idx].valid = log_in;
						login_cnt++;
						return;
					}
				}
			}
			idx = hash(idx + 1);
			cnt++;
		}
		cout << "Invalid\n";
	}
	void logout(string s) {
		int idx = hash(toInt(s));
		while (table[idx].id != s)
			idx = hash(idx + 1);
		table[idx].valid = log_out;
		login_cnt--;
		cout << "Submit\n";
	}
	void online() {
		cout << login_cnt << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	string cmd, s, p;
	cin >> T;
	hashtable* hs = new hashtable;
	while (T--) {
		cin >> cmd;
		if (cmd == "signup") {
			cin >> s >> p;
			hs->signup(s, p);
		}
		else if (cmd == "login") {
			cin >> s >> p;
			hs->login(s, p);
		}
		else if (cmd == "logout") {
			cin >> s;
			hs->logout(s);
		}
		else if (cmd == "online") {
			hs->online();
		}
	}
}
