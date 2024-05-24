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
    int divisor;
    int hashFnc(int key) {
        return key % capacity;
    }
    int hashFnc2(int key) {
        return divisor - (key % divisor);
    }

public:
    hashtable(int N, int M) {
        capacity = N;
        divisor = M;
        table= new entry[capacity];
    }
    void put(int key, string value) {
        int index = hashFnc(key);
        int probe = 1;

        while (table[index].valid == ISITEM && probe <= capacity) {
            index = hashFnc(index + hashFnc2(key));
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
                cout << table[index].value << '\n';
                table[index].erase();
                return;
            }
            index = hashFnc(index + hashFnc2(key));
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
            index = hashFnc(index + hashFnc2(key));
            probe++;
        }
        return "None";
    }

    void vacant() {
        int cnt = 0;

        for(int i = 0; i< capacity; i++) {
            if(table[i].valid != ISITEM) {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }


};

int main(){
    int t, n, m;
    cin >> t >> n >> m;

    hashtable* ht = new hashtable(n, m);

    for(int i = 0; i<t; i++) {
        string c;
        cin >> c;

        int num;
        string str;
        if(c == "put") {
            cin >> num >> str;
            ht->put(num, str);
        }
        else if(c == "erase") {
            cin >> num;
            ht->erase(num);
        }
        else if(c == "find") {
            cin >> num;
            cout << ht->find(num) << "\n";
        }
        else if(c == "vacant") {
            ht->vacant();
        }
    }


    return 0;
}
