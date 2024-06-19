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

class DoubleHashingHashTable {
private:
    HashEntry* table;
    int N;
    int M;

    int hash1(int key) {
        return key % N;
    }

    int hash2(int key) {
        return M - (key % M);
    }

public:
    DoubleHashingHashTable(int size, int secondHashPrime) : N(size), M(secondHashPrime) {
        table = new HashEntry[N];
    }

    ~DoubleHashingHashTable() {
        delete[] table;
    }

    void put(int key, string value) {
        int h1 = hash1(key);
        int h2 = hash2(key);
        int index = h1;
        int i = 0;

        while (i < N) {
            if (!table[index].isOccupied || table[index].isDeleted) {
                table[index].key = key;
                table[index].value = value;
                table[index].isOccupied = true;
                table[index].isDeleted = false;
                cout << h1 << " " << index << endl;
                return;
            }
            index = (h1 + i * h2) % N;
            i++;
        }

        cout << h1 << " -1" << endl;
    }

    void erase(int key) {
        int h1 = hash1(key);
        int h2 = hash2(key);
        int index = h1;
        int i = 0;

        while (i < N) {
            if (table[index].isOccupied && !table[index].isDeleted && table[index].key == key) {
                table[index].isDeleted = true;
                cout << table[index].value << endl;
                return;
            }
            index = (h1 + i * h2) % N;
            i++;
        }

        cout << "None" << endl;
    }

    void find(int key) {
        int h1 = hash1(key);
        int h2 = hash2(key);
        int index = h1;
        int i = 0;

        while (i < N) {
            if (table[index].isOccupied && !table[index].isDeleted && table[index].key == key) {
                cout << table[index].value << endl;
                return;
            }
            index = (h1 + i * h2) % N;
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
    int T, N, M;
    cin >> T >> N >> M;

    DoubleHashingHashTable hashTable(N, M);

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
