//
// Created by 김정일 on 2024. 5. 8..
//
#include <iostream>
#include <vector>

using namespace std;

class heap {
private:
    vector<int> v;
    int rootindex;
    int heapsize;
    int dir;


public:
    heap(int dir) {
        v.push_back(0);
        heapsize = 0;
        rootindex = 1;
        this->dir= dir;
    }

    void swap(int i1, int i2) {
        v[0] = v[i1];
        v[i1] = v[i2];
        v[i2] = v[0];
    }
    void upheap(int i) {
        if(i == rootindex) {
            return;
        }
        else {
            int parent = i /2;
            if(v[i]*dir < v[parent] *dir) {
                swap(parent, i);
                upheap(parent);
            }
        }
    }
    void downheap(int index) {
        int lChild = index * 2;
        int rChild = index * 2 + 1;
        if (rChild <= heapsize) { // 자식이 둘인 경우
            if (v[lChild] * dir <= v[rChild] * dir) {
                if (v[lChild] * dir < v[index] * dir) {
                    swap(lChild, index);
                    downheap(lChild);
                } else {
                    return;
                }
            } else {
                if (v[rChild] * dir < v[index] * dir) {
                    swap(rChild, index);
                    downheap(rChild);
                } else {
                    return;
                }
            }
        } else if (lChild <= heapsize) { // 자식이 하나인 경우
            if (v[lChild] * dir < v[index] * dir) {
                swap(lChild, index);
                downheap(lChild);
            } else {
                return;
            }
        } else {
            return;
        }
    }
    void insert(int i) {
        v.push_back(i);
        heapsize++;
        upheap(heapsize);
    }
    int pop() {
        if(isEmpty()) return -1;
        else {
            int top = v[rootindex];
            v[rootindex] = v[heapsize];
            heapsize--;
            v.pop_back();
            downheap(rootindex);
            return top;
        }


    }
    int top() {
        if(isEmpty()) return -1;

        return v[rootindex];
    }
    int getSize() {
        return heapsize;
    }
    bool isEmpty() {
        return heapsize == 0;
    }
    void print(int i) {
        int lchild = i * 2;
        int rchild = i*2 +1;
        cout << v[i] << ' ';
        if(lchild <= heapsize)
            print(lchild);
        if(rchild <= heapsize)
            print(rchild);
    }

};

int main() {
    int t;
    cin >> t;

    for(int i = 0; i<t; i++) {
        heap* h = new heap(-1);

        int k;
        cin >> k;
        int p;
        cin >> p;
        for(int j = 0; j<k; j++) {
            int x;
            cin >> x;
            h->insert(x);
        }


        int count = 0;
        int flag = 0;
        while(h->top() > p) {
            if(h->getSize() <= 2) {
                cout << "False\n";
                flag = 1;
                break;
            }
            int e1 = h->pop();
            int e2 = h->pop();
            int e3 = h->pop();
            count++;
            h->insert((e1+e3)/2);
        }
        if(flag == 1) continue;
        cout << count << '\n';
        h->print(1);
        cout << '\n';
    }

    return 0;
}
