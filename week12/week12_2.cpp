#include <iostream>

using namespace std;
#define NOITEM 0
#define LOGOUT 1
#define LOGIN 2
#define CAPA 500009

class entry {
public:
    string id;
    string pw;
    int valid;

    entry() {
        id = "";
        pw = "";
        valid = NOITEM;
    }

    entry(string id, string pw) {
        this->id = id;
        this->pw = pw;
        this->valid = LOGOUT;
    }
};

class HashTable {
private:
    entry table[CAPA];

    int pow(int x, int y) {
        int ans = 1;
        for (int i = 0; i < y; i++) {
            ans *= x;
        }
        return ans;
    }

    int toInt(string str) {
        int ret = 0;
        for (int i = 0; i < str.length(); i++) {
            ret += (str[i] - 'a') * pow(26, i);
        }
        return ret;
    }

    int hash(int k) {
        return k % CAPA;
    }


public:
    void signUp(string id, string pw) {
        int idx = hash(toInt(id));

        int cnt = 1;
        while (table[idx].valid != NOITEM && cnt <= CAPA) {
            if (table[idx].id == id) {
                cout << "Invalid " << table[idx].pw << '\n';
                return;
            }
            idx = hash(idx + 1);
            cnt++;
        }
        table[idx] = entry(id, pw);
        cout << "Submit" << '\n';
    }

    void login(string id, string pw) {
        int idx = hash(toInt(id));
        int cnt = 1;

        while (table[idx].valid != NOITEM && cnt <= CAPA) {
            if (table[idx].id == id) {
                if (table[idx].pw != pw) {
                    cout << "Invalid" << '\n';
                    return;
                }
                if (table[idx].valid == LOGIN) {
                    cout << "Quit" << '\n';
                    return;
                }
                cout << "Submit" << '\n';
                table[idx].valid = LOGIN;
                return;
            }
            idx = hash(idx + 1);
            cnt++;
        }
        cout << "Invalid" << '\n';
    }

    void logout(string id) {
        int idx = hash(toInt(id));
        while (table[idx].id != id) {
            idx = hash(idx + 1);
        }
        table[idx].valid = LOGOUT;
        cout << "Submit" << '\n';
    }

    void change(string id, string pw) {
        int idx = hash(toInt(id));
        while (table[idx].id != id) {
            idx = hash(idx + 1);
        }
        table[idx].pw = pw;
        cout << "Submit" << '\n';
    }

};


int main() {
    int t;
    cin >> t;
    HashTable *ht = new HashTable();
    while (t--) {
        string cmd;
        string id, pw;
        cin >> cmd;
        if (cmd == "signup") {
            cin >> id >> pw;
            ht->signUp(id, pw);
        } else if (cmd == "login") {
            cin >> id >> pw;
            ht->login(id, pw);
        } else if (cmd == "logout") {
            cin >> id;
            ht->logout(id);
        } else if (cmd == "change") {
            cin >> id >> pw;
            ht->change(id, pw);
        }
    }
}
