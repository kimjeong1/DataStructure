//
// Created by 김정일 on 2024. 5. 10..
//
#include <iostream>
#include <vector>

using namespace std;

struct compare {
    bool operator()(const int& lhs, const int& rhs) {
        return lhs > rhs;
    }
};

class heap {
private:
    compare C;
    vector<int> arr;

    void swap(int i1, int i2) {
        arr[0] = arr[i1];
        arr[i1] = arr[i2];
        arr[i2] = arr[0];
    }
    void upheap(int i) {
        if (i == 1) return;

        int parent = i / 2;
        if (!C(arr[parent], arr[i])) {
            swap(parent, i);
            upheap(parent);
        }

    }
    void downheap(int i) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int child;

        if (left > size()) {
            return;
        }
        else if (left == size()) {
            child = left;
        }
        else {
            if (C(arr[left], arr[right]))
                child = left;
            else child = right;
        }

        if (!C(arr[i], arr[child])) {
            swap(child, i);
            downheap(child);
        }
    }

public:
    heap() {
        arr.push_back(0);
    }
    int size() {
        return arr.size() - 1;
    }
    bool empty() {
        return size() == 0;
    }
    void push(int e) {
        arr.push_back(e);
        upheap(size());
    }
    int top() {
        if (empty()) return -1;

        return arr[1];
    }
    void pop() {
        if (empty()) return;

        swap(1, size());
        arr.pop_back();
        downheap(1);
    }
    void print() {
        if(empty()) {
            cout << "-1\n";
            return;
        }
        for(int i = 1; i<=size(); i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
};

int main() {
    int t;
    cin >> t;

    heap* h = new heap;
    for(int i = 0; i<t; i++) {
        string c;
        cin >> c;

        if(c == "insert") {
            int x;
            cin >> x;
            h->push(x);
        }
        else if(c == "size") {
            cout << h->size() << '\n';
        }
        else if(c == "isEmpty") {
            cout << h->empty() << '\n';
        }
        else if(c == "pop") {
            cout << h->top() << '\n';
            h->pop();
        }
        else if(c == "top") {
            cout << h->top() << '\n';
        }
        else if(c == "print") {
            h->print();
        }
    }

    return 0;
}
