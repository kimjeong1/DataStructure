//
// Created by 김정일 on 2024. 5. 10..
//
#include <iostream>
#include <vector>

using namespace std;

struct compare {
    bool operator()(const int& lhs, const int& rhs) {
        return lhs < rhs;
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
    void print(int i) {
        int lchild = i*2;
        int rchild = i*2+1;

        if(lchild <= size()) {
            print(lchild);
        }
        if(rchild <= size()) {
            print(rchild);
        }

        cout << arr[i] << ' ';
    }

};

int main() {
    int t;
    cin >> t;

    for(int i = 0; i<t; i++) {
        int n,p;
        cin >> n >> p;
        heap* h = new heap;

        for(int j = 0; j<n; j++) {
            int x;
            cin >> x;
            h->push(x);
        }

        int count = 0;
        int flag = 0;
        while(h->top() < p) {
            if(h->size() <= 2) {
                cout << "False\n";
                flag = 1;
                break;
            }
            int e1 = h->top();
            h->pop();
            int e2 = h->top();
            h->pop();
            int e3 = h->top();;
            h->pop();
            count++;
            h->push((e1+e3)/2);

        }
        if(flag == 1) continue;
        cout << count << '\n';
        h->print(1);
        cout << '\n';

    }

    return 0;
}
