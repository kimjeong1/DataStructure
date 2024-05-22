//
// Created by 김정일 on 2024. 5. 22..
//

#include <iostream>

using namespace std;

#define Noitem 0
#define available 1
#define Isitem 2

struct entry {

    int key;
    string value;
    int valid;

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

    void erase() {
        this->valid = available;
    }
};

class hashtable {
private:
    entry table[10001];
    int capacity;
    int m;

    int hash1(int key) {
        return key%capacity;
    }
    int hash2(int k) {
        return m - k%m;
    }

public:
    hashtable(int n, int m) {
        capacity = n;
        this->m = m;
    }

    void put(int k, string s) {
        int idx = hash1(k);

        int cnt = 1;
        while(table[idx].valid == Isitem && cnt <= capacity) {
            idx = hash1(idx +hash2(k));
            cnt++;
        }

        table[idx] = entry(k ,s);
        cout << cnt+idx << '\n';
    }
    void erase(int k) {
        int idx = hash1(k);

        int cnt = 1;
        while(table[idx].valid != Noitem && cnt <= capacity) {
            if(table[idx].valid == Isitem && table[idx].key == k) {
                cout << table[idx].value << '\n';
                table[idx].erase();
                return;
            }
            idx = hash1(idx +hash2(k));
        }
        cout << "None\n";
    }
    string find(int k) {
        int idx = hash1(k);

        int cnt = 1;
        while(table[idx].valid != Noitem && cnt<= capacity) {
            if(table[idx].valid == Isitem && table[idx].key == k) {
                return table[idx].value;
            }
            idx = hash1(idx +hash2(k));
        }
        return "None";
    }
    int vacant() {
        int cnt = 0;
        for(int i =0; i<capacity; i++) {
            if(table[i].valid != Isitem) {
                cnt++;
            }

        }
        return cnt;
    }
};

int main() {
    int t, n, m;

    cin >> t >> n >> m;
    hashtable *ht = new hashtable(n,m);

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
