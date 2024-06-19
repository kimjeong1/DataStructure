#include <iostream>
#include <string>

using namespace std;

#define no_item 0
#define _present 1
#define _absent 2
#define available 3

struct entry {
public:
	int valid, id, present_count;
	string name;
	entry() {
		present_count = valid = id = no_item;
		name = "";
	}
	entry(int x, string s) {
		valid = _absent;
		name = s;
		id = x;
		present_count = 0;
	}
	bool vacant() {
		return (this->valid == no_item || this->valid == available);
	}
};

class hashtable {
public:
	entry* id_table;
	entry* name_table;
	int capacity;
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
		int strlen = s.length();
		for (int i = 0; i < strlen; i++)
			result += ((s[i] - 'a') * pow(26, i));
		return result;
	}
	hashtable() {
		capacity = 200003;
		id_table = new entry[capacity];
		name_table = new entry[capacity];
	}
	void add(int x, string s) {
		entry* newent = new entry(x, s);
		int idx = hash(x);
		int cnt = 1;
		while (!id_table[idx].vacant() && cnt <= capacity) {
			idx = hash(idx + 1);
			cnt++;
		}
		id_table[idx] = *newent;
		idx = hash(toInt(s));
		while (!name_table[idx].vacant() && cnt <= capacity) {
			idx = hash(idx + 1);
			cnt++;
		}
		name_table[idx] = *newent;
	}
	void erase(int x) {
		int idx = hash(x);
		while (id_table[idx].id!=x)
			idx = hash(idx + 1);
		id_table[idx].valid = available;
		string name = id_table[idx].name;
		idx = hash(toInt(name));
		while (name_table[idx].name != name)
			idx = hash(idx + 1);
		name_table[idx].valid = available;
	}
	void getname(int x) {
		int idx = hash(x);
		while (id_table[idx].id != x)
			idx = hash(idx + 1);
		cout << id_table[idx].name << '\n';
	}
	void number(string s) {
		int idx = hash(toInt(s));
		int cnt = 1;
		while (name_table[idx].valid != no_item && cnt <= capacity) {
			if (name_table[idx].valid != available && name_table[idx].name == s) {
				cout << name_table[idx].id << '\n';
				return;
			}
			idx = hash(idx + 1);
			cnt++;
		}
		cout << 0 << '\n';
	}
	void present(string s) {
		int idx = hash(toInt(s));
		int cnt = 1;
		int x = 0;
		while (name_table[idx].valid != no_item && cnt <= capacity) {
			if (name_table[idx].valid != available && name_table[idx].name == s) {
				name_table[idx].present_count++;
				x = name_table[idx].id;
				break;
			}
			idx = hash(idx + 1);
			cnt++;
		}
		if(x==0)
			cout << -1 << '\n';
		else {
			idx = hash(x);
			while (id_table[idx].valid != no_item && cnt <= capacity) {
				if (id_table[idx].valid != available && id_table[idx].id == x) {
					id_table[idx].present_count++;
					cout << id_table[idx].present_count << '\n';
					return;
				}
				idx = hash(idx + 1);
				cnt++;
			}
		}
	}
	void count(int x) {
		int idx = hash(x);
		int cnt = 1;
		while (id_table[idx].valid != no_item && cnt <= capacity) {
			if (id_table[idx].valid != available && id_table[idx].id == x) {
				cout << id_table[idx].present_count << '\n';
				return;
			}
			idx = hash(idx + 1);
			cnt++;
		}
		cout << -1 << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, x;
	string s, cmd;
	hashtable* hs = new hashtable;
	cin >> T;
	while (T--) {
		cin >> cmd;
		if (cmd == "add") {
			cin >> x >> s;
			hs->add(x, s);
		}
		else if (cmd == "delete") {
			cin >> x;
			hs->erase(x);
		}
		else if (cmd == "name") {
			cin >> x;
			hs->getname(x);
		}
		else if (cmd == "number") {
			cin >> s;
			hs->number(s);
		}
		else if (cmd == "present") {
			cin >> s;
			hs->present(s);
		}
		else if (cmd == "count") {
			cin >> x;
			hs->count(x);
		}
	}
}
