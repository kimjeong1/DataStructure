#include <iostream>
#include <string>

using namespace std;

struct HashEntry {
    int key;
    string value;
    bool isOccupied;
    bool isDeleted;

    HashEntry() : key(0), value(""), isOccupied(false), isDeleted(false) {}
};

class LinearProbingHashTable {
private:
    HashEntry* table;
    int N;

    int hash(int key) {
        return key % N;
    }

public:
    LinearProbingHashTable(int size) : N(size) {
        table = new HashEntry[N];
    }

    ~LinearProbingHashTable() {
        delete[] table;
    }

    void put(int key, string value) {
        int h = hash(key);
        int index = h;
        int i = 0;

        while (i < N) {
            if (!table[index].isOccupied || table[index].isDeleted) {
                table[index].key = key;
                table[index].value = value;
                table[index].isOccupied = true;
                table[index].isDeleted = false;
                cout << h << " " << index << endl;
                return;
            }
            index = (h + i) % N;
            i++;
        }

        cout << h << " -1" << endl;
    }

    void erase(int key) {
        int h = hash(key);
        int index = h;
        int i = 0;

        while (i < N) {
            if (table[index].isOccupied && !table[index].isDeleted && table[index].key == key) {
                table[index].isDeleted = true;
                cout << table[index].value << endl;
                return;
            }
            index = (h + i) % N;
            i++;
        }

        cout << "None" << endl;
    }

    void find(int key) {
        int h = hash(key);
        int index = h;
        int i = 0;

        while (i < N) {
            if (table[index].isOccupied && !table[index].isDeleted && table[index].key == key) {
                cout << table[index].value << endl;
                return;
            }
            index = (h + i) % N;
            i++;
        }

        cout << "None" << endl;
    }

    void vacant() {
        int count = 0;
        for (int i = 0; i < N; ++i) {
            if (!table[i].isOccupied || table[i].isDeleted) {
                count++;
            }
        }
        cout << count << endl;
    }
};

int main() {
    int T, N;
    cin >> T >> N;

    LinearProbingHashTable hashTable(N);

    for (int i = 0; i < T; ++i) {
        string command;
        cin >> command;

        if (command == "put") {
            int key;
            string value;
            cin >> key >> value;
            hashTable.put(key, value);
        } else if (command == "erase") {
            int key;
            cin >> key;
            hashTable.erase(key);
        } else if (command == "find") {
            int key;
            cin >> key;
            hashTable.find(key);
        } else if (command == "vacant") {
            hashTable.vacant();
        }
    }

    return 0;
}
