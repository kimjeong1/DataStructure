#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    DoublyLinkedList() {
        header = new Node();
        trailer = new Node();
        header->next = trailer;
        trailer->prev = header;
        header->prev = trailer->next = nullptr;
    }

    bool empty() {
        return (header->next == trailer);
    }

    void begin() {
        p = header->next;
    }

    void end() {
        p = trailer;
    }

    void insert(int e) {
        Node* newNode = new Node();
        newNode->data = e;
        newNode->prev = p->prev;
        newNode->next = p;
        p->prev->next = newNode;
        p->prev = newNode;
    }

    void erase() {
        if (empty()) {
            cout << "empty" << endl;
            return;
        }
        if (p == trailer)
            return;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        Node* temp = p;
        p = p->next;
        delete temp;
    }

    void nextP() {
        if (p != trailer) {
            p = p->next;
        }
    }

    void prevP() {
        if (p != header->next) {
            p = p->prev;
        }
    }

    void findMultiple(int e) {
        bool found = false;
        int idx = 0;
        Node* current = header->next;
        while (current != trailer) {
            if (current->data % e == 0) {
                if (!found) {
                    found = true;
                }
                else {
                    cout << " ";
                }
                cout << idx;
            }
            current = current->next;
            idx++;
        }
        if (!found) {
            cout << -1;
        }
        cout << endl;
    }

private:
    Node* header;
    Node* trailer;
    Node* p;
};

int main() {
    int N;
    cin >> N;

    DoublyLinkedList list;
    list.begin();

    for (int i = 0; i < N; ++i) {
        string command;
        cin >> command;

        if (command == "insert") {
            int e;
            cin >> e;
            list.insert(e);
        }
        else if (command == "erase") {
            list.erase();
        }
        else if (command == "nextP") {
            list.nextP();
        }
        else if (command == "prevP") {
            list.prevP();
        }
        else if (command == "findmultiple") {
            int multiple;
            cin >> multiple;
            list.findMultiple(multiple);
        }
    }

    return 0;
}
