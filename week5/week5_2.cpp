#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    DoublyLinkedList(int N, int* elements) {
        header = new Node();
        trailer = new Node();
        header->next = trailer;
        trailer->prev = header;
        header->prev = trailer->next = nullptr;

        for (int i = 0; i < N; ++i) {
            insertBack(elements[i]);
        }
    }

    ~DoublyLinkedList() {
        while (!empty()) {
            eraseFront();
        }
        delete header;
        delete trailer;
    }

    bool empty() const {
        return (header->next == trailer);
    }

    void insertBack(int e) {
        Node* newNode = new Node();
        newNode->data = e;
        newNode->prev = trailer->prev;
        newNode->next = trailer;
        trailer->prev->next = newNode;
        trailer->prev = newNode;
    }

    void eraseFront() {
        if (empty()) {
            return;
        }
        Node* temp = header->next;
        header->next = temp->next;
        temp->next->prev = header;
        delete temp;
    }

    void move(int k) {
        if (k > 0) {
            for (int i = 0; i < k && p->next != trailer; ++i) {
                p = p->next;
            }
        }
        else if (k < 0) {
            for (int i = 0; i < -k && p->prev != header->next; ++i) {
                p = p->prev;
            }
        }
    }

    int getCurrentData() const {
        return p->data;
    }

    void setPositionToHeaderNext() {
        p = header->next;
    }

private:
    Node* header;
    Node* trailer;
    Node* p;
};

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;

        int* elements = new int[N];
        for (int i = 0; i < N; ++i) {
            cin >> elements[i];
        }

        DoublyLinkedList list(N, elements);
        list.setPositionToHeaderNext();

        int M;
        cin >> M;

        for (int i = 0; i < M; ++i) {
            int k;
            cin >> k;

            list.move(k);
            list.move(list.getCurrentData());
        }

        cout << list.getCurrentData() << endl;

        delete[] elements;
    }

    return 0;
}
