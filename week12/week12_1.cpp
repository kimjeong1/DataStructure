//
// Created by 김정일 on 2024. 5. 22..
//
#include <iostream>

using namespace std;

#define Noitem 0
#define available 1
#define Isitem 2

class entry {
private:
    int key;
    string value;
    int valid;
public:
    entry() {
        key = 0;
        value = "";
        valid = Noitem;
    }
    entry(int key, string value) {
        this->key = key;
        this->value = value;
        this->valid = Isitem;
    }
    int getkey() {
        return key;
    }
    string getvalue() {
        return value;
    }
    bool isitem() {
        return this->valid == Isitem;
    }
    bool noitem() {
        return this->valid == Noitem;
    }
    void erase() {
        this->valid = available;
    }
};

class hashtable {
private:
    entry *table;
    int capacity;

    int hash(int key) {
        return key%capacity;
    }

public:
    hashtable(int n) {
        table = new entry[n];
        capacity = n;
    }

    void put(int k, string s) {
        int idx = hash(k);

        int cnt = 1;
        while(table[idx].isitem() && cnt <= capacity) {
            idx = hash(idx +1);
            cnt++;
        }
        entry *e = new entry(k, s);
        table[idx] = *e;
        cout << cnt+idx << '\n';
    }
    void erase(int k) {
        int idx = hash(k);

        int cnt = 1;
        while(!table[idx].noitem() && cnt <= capacity) {
            if(table[idx].isitem() && table[idx].getkey() == k) {
                cout << table[idx].getvalue() << '\n';
                table[idx].erase();
                return;
            }
            idx = hash(idx +1);
        }
        cout << "None\n";
    }
    string find(int k) {
        int idx = hash(k);

        int cnt = 1;
        while(!table[idx].noitem() && cnt<= capacity) {
            if(table[idx].isitem() && table[idx].getkey() == k) {
                return table[idx].getvalue();
            }
            idx = hash(idx +1);
        }
        return "None";
    }
    int vacant() {
        int cnt = 0;
        for(int i =0; i<capacity; i++) {
            if(!table[i].isitem()) {
                cnt++;
            }

        }
        return cnt;
    }
};

int main() {
    int t, n;

    cin >> t >> n;
    hashtable *ht = new hashtable(n);

    for(int i = 0; i<t; i++) {
        string c;
        cin >> c;

        if(c == "put") {
            int k;
            string s;
            cin >> k >> s;
            ht->put(k, s);
        }
        else if(c == "erase") {
            int k;
            cin >> k;
            ht->erase(k);
        }
        else if(c == "find") {
            int k;
            cin >> k;
            cout << ht->find(k) << '\n';
        }
        else if(c == "vacant") {
            cout << ht->vacant() << '\n';
        }
    }


    return 0;
}
