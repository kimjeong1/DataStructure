#include <iostream>

using namespace std;
#define NOITEM 0
#define AVAILABLE 1
#define ABSENT 2
#define PRESENT 3
#define CAPA 500009

class student {
public:
    int id;
    int cls;
    string name;
    int valid;

    student() {
        id = 0;
        cls = 0;
        name = "";
        valid = NOITEM;
    };

    student(int id, int cls, string name) {
        this->id = id;
        this->cls = cls;
        this->name = name;
        this->valid = ABSENT;
    }

    bool isVacant() {
        return (valid == NOITEM || valid == AVAILABLE);
    }

    void setValid(int valid) {
        this->valid = valid;
    }
};

class HashTable {
private:
    student idTable[CAPA];
    student nameTable[CAPA];

    int pow(int x, int y) {
        int ans = 1;
        for (int i{0}; i < y; i++) {
            ans *= x;
        }
        return ans;
    }

    int toInt(string s) {
        int ans = 0;
        for (int i{0}; i < s.length(); i++) {
            ans += (s[i] - 'a') * pow(26, i);
        }
        return ans;
    }

    int hash(int x) {
        return x % CAPA;
    }

public:
    void add(int x, int c, string s) {
        int idx = hash(x);
        int cnt = 1;
        while (!idTable[idx].isVacant() && cnt <= CAPA) {
            idx = hash(idx + 1);
            cnt++;
        }
        idTable[idx] = student(x, c, s);

        idx = hash(toInt(s));
        cnt = 1;

        while (!nameTable[idx].isVacant() && cnt <= CAPA) {
            idx = hash(idx + 1);
            cnt++;
        }
        nameTable[idx] = student(x, c, s);
    }

    void erase(int x) {
        int idx = hash(x);
        while (idTable[idx].id != x) {
            idx = hash(idx + 1);
        }
        idTable[idx].setValid(AVAILABLE);
        cout << idTable[idx].name << ' ' << idTable[idx].cls << '\n';

        idx = hash(toInt(idTable[idx].name));
        while (nameTable[idx].id != x) {
            idx = hash(idx + 1);
        }
        nameTable[idx].setValid(AVAILABLE);
    }

    void name(int x) {
        int idx = hash(x);
        while (idTable[idx].id != x) {
            idx = hash(idx + 1);
        }
        cout << idTable[idx].name << '\n';
    }

    void change(int x, int c) {
        int idx = hash(x);
        while (idTable[idx].id != x) {
            idx = hash(idx + 1);
        }
        idTable[idx].cls = c;
        idx = hash(toInt(idTable[idx].name));
        while (nameTable[idx].id != x) {
            idx = hash(idx + 1);
        }
        nameTable[idx].cls = c;
    }

    void setAttendance(string s, int attendance) {
        int idx = hash(toInt(s));
        int cnt = 1;

        while (nameTable[idx].valid != NOITEM && cnt <= CAPA) {
            if (nameTable[idx].name == s && (nameTable[idx].valid == ABSENT || nameTable[idx].valid == PRESENT)) {
                nameTable[idx].setValid(attendance);
                cout << nameTable[idx].id << ' ' << nameTable[idx].cls << '\n';
                return;
            }
            cnt++;
            idx = hash(idx + 1);
        }
        cout << "Invalid" << '\n';
    }

    int getAttendSize() {
        int cnt = 0;
        for (student &s: nameTable) {
            if (s.valid == PRESENT) {
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    int t;
    cin >> t;
    HashTable *ht = new HashTable();
    while (t--) {
        string cmd;
        int id, cls;
        string name;
        cin >> cmd;
        if (cmd == "add") {
            cin >> id >> cls >> name;
            ht->add(id, cls, name);
        } else if (cmd == "delete") {
            cin >> id;
            ht->erase(id);
        } else if (cmd == "name") {
            cin >> id;
            ht->name(id);
        } else if (cmd == "change") {
            cin >> id >> cls;
            ht->change(id, cls);
        } else if (cmd == "present") {
            cin >> name;
            ht->setAttendance(name, PRESENT);
        } else if (cmd == "absent") {
            cin >> name;
            ht->setAttendance(name, ABSENT);
        }
    }
    cout << ht->getAttendSize();
}
