#include <iostream>

using namespace std;
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

struct entry {
    int key;
    string value;
    int valid;

    entry() {
        key = 0;
        value = "";
        valid = NOITEM;
    }
    entry(int key, string value) {
        this->key = key;
        this->value = value;
        valid = ISITEM;
    }
    void erase() {
        valid = AVAILABLE;
    }
};

class hashtable {
private:
    entry* table;
    int capacity;
    int hashFnc(int key) {
        return key % capacity;
    }

public:
    hashtable(int N) {
        capacity = N;
        table= new entry[capacity];
    }
    void put(int key, string value) {
        int index = hashFnc(key);
        int probe = 1;

        while (table[index].valid == ISITEM && probe <= capacity) {
            index = hashFnc(index +1);
            probe++;
        }

        if(probe > capacity) return;
        table[index] = entry(key, value);
        cout << probe + index << '\n';
    }
    void erase(int key) {
        int index = hashFnc(key);
        int probe = 1;

        while(table[index].valid != NOITEM && probe <= capacity) {
            if(table[index].valid == ISITEM && table[index].key == key) {
                cout << table[index].value;
                table[index].erase();

                return;
            }
            index = hashFnc(index +1);
            probe++;
        }
        cout << "None\n";
    }

    string find(int key) {
        int index = hashFnc(key);
        int probe = 1;

        while(table[index].valid != NOITEM && probe<= capacity) {
            if(table[index].valid == ISITEM && table[index].key == key) {
                return table[index].value;
            }
            index = hashFnc(index +1);
            probe++;
        }
        return "None";
    }

    void vacant() {
        int cnt = 0;

        for(int i = 0; i<capacity; i++) {
            if(table[i].valid == NOITEM) cnt++;
            if(table[i].valid == AVAILABLE) cnt++;
        }

        cout << cnt << '\n';
    }
};

int main(){

    int t, n;
    cin >> t >> n;
    hashtable *ht = new hashtable(n);

    for(int i = 0; i<t; i++) {
        string c;
        cin >> c;

        int k;
        string s;

        if(c == "put") {
            cin >> k >> s;
            ht->put(k, s);
        }
        else if( c== "erase") {
            cin >> k;
            ht->erase(k);
        }
        else if(c == "find") {
            cin >> k;
            cout << ht->find(k) << '\n';
        }
        else if(c == "vacant"){
            ht->vacant();
        }
    }


    return 0;
}
