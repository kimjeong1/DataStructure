#include <iostream>

using namespace std;

class arrayQueue {
public:
    arrayQueue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        frontindex = rearindex = 0;
        n = 0;
    }
    bool empty() {
        return (n == 0);
    }
    int size() {
        return n;
    }
    int front() {
        if (empty()) return -1;
        return arr[frontindex];
    }
    int rear() {
        if (empty()) return -1;
        return arr[(rearindex - 1 + capacity) % capacity];
    }
    void enqueue(int data) {
        if (size() == capacity) {
            cout << "Full\n";
            return;
        }
        arr[rearindex] = data;
        rearindex = (rearindex + 1) % capacity;
        n++;
    }
    void dequeue() {
        if (empty()) {
            cout << "Empty\n";
            return;
        }
        frontindex = (frontindex + 1) % capacity;
        n--;
    }

private:
    int* arr;
    int capacity;
    int frontindex;
    int rearindex;
    int n;

};

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        arrayQueue q1(n), q2(n);
        int score1 = 0, score2 = 0;

        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            q1.enqueue(x);
        }
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            q2.enqueue(x);
        }

        int abc = 0;
        int a, b;
        int diff = 0;


        for (int j = 0; j < n; j++) {
            cout << "Round" << j + 1 << " ";
            a = q1.front();
            b = q2.front();

            if (abc == 1) a += diff;
            else if (abc == 2) b += diff;

            if (a == b) {
                cout << a << "=" << b;
                cout << " " << score1 << ":" << score2 << "\n";
                q1.dequeue();
                q2.dequeue();
                diff = 0;
            }
            else if (a>b) {
                cout << a << ">" << b;
                score1++;
                cout << " " << score1 << ":" << score2 << "\n";
                diff = a - b;
                q1.dequeue();
                q2.dequeue();
                abc = 1;
                
            }
            else if (a<b) {
                cout << a << "<" << b;
                score2++;
                cout << " " << score1 << ":" << score2 << "\n";
                diff = b - a;
                q1.dequeue();
                q2.dequeue();
                abc = 2;

            }
        }

        
        if (score1 > score2)
            cout << "Winner P1\n";
        else if (score1 == score2)
            cout << "Draw\n";
        else
            cout << "Winner P2\n";
    }

    return 0;
}
