#include <iostream>
#include <vector>

using namespace std;

class heap {
private:
    vector<int> v;
    int heapsize;
    int rootindex;
    int dir;

public:
    heap(int dir) {
        v.push_back(0);
        heapsize = 0;
        rootindex = 1;
        this->dir = dir;
    }

    bool compare(int idx1, int idx2) {
        return (v[idx1] * dir < v[idx2] * dir);
    }

    void swap(int idx1, int idx2) {
        v[0] = v[idx1];
        v[idx1] = v[idx2];
        v[idx2] = v[0];
    }

    void upheap(int idx) {
        if(idx == rootindex) {
            return;
        }
        int parent = idx / 2;
        if(compare(idx, parent)) {
            swap(parent, idx);
            upheap(parent);
        }
    }

    void downheap(int idx) {
        int lchild = idx *2;
        int rchild = idx * 2 + 1;
        if(rchild <= heapsize) {
            if(compare(lchild, rchild)) {
                swap(lchild, idx);
                downheap(lchild);
            }
            else {
                if(compare(rchild, idx)) {
                    swap(rchild, idx);
                    downheap(rchild);
                }
            }
        }
        else if(lchild <= heapsize) { // 오른쪽자식이 없을때 수행
            if(compare (lchild, idx)) {
                swap(lchild, idx);
                downheap(lchild);
            }
        }
    }

    void insert(int i) {
        v.push_back(i);
        heapsize++;
        upheap(heapsize);
    }

    int getSize() {
        return heapsize;
    }

    bool isEmpty() {
        return getSize() == 0;
    }

    int pop() {
        if(isEmpty()) {
            return -1;
        }
        int top = v[rootindex];
        v[rootindex] = v[heapsize];
        heapsize--;
        v.pop_back();
        downheap(rootindex);
        return top;
    }

    int top() {
        if(isEmpty()) return -1;

        return v[rootindex];
    }

    void print() {
        if(isEmpty()) {
            cout << "-1\n";
            return;
        }
        for(int i = rootindex; i<=heapsize; i++) {
            cout << v[i] << ' ';
        }
        cout << "\n";
    }
};

int main() {
    int t;
    cin >> t;

    heap* h = new heap(1); // 1이면 minheap -1이면 maxheap

    for(int i = 0; i<t; i++) {
        string c;
        cin >> c;

        if(c == "insert") {
            int i;
            cin >> i;
            h->insert(i);
        }
        else if(c == "size") {
            cout << h->getSize() << "\n";
        }

        else if(c == "isEmpty") {
            cout << h->isEmpty() << "\n";
        }
        else if (c == "pop") {
            cout << h->pop() << "\n";
        }
        else if(c == "top") {
            cout << h->top() << "\n";
        }
        else if(c == "print") {
            h->print();
        }

    }

    return 0;
}
