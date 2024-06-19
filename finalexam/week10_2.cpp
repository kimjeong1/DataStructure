#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (compare(heap[index], heap[parent])) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && compare(heap[left], heap[largest])) {
                largest = left;
            }
            if (right < size && compare(heap[right], heap[largest])) {
                largest = right;
            }
            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

    bool compare(int a, int b) {
        // 홀수가 우선, 홀수 중에서는 큰 수가 우선
        // 짝수는 나중, 짝수 중에서는 작은 수가 우선
        if ((a % 2 == 1 && b % 2 == 1)) {
            return a > b;
        } else if ((a % 2 == 0 && b % 2 == 0)) {
            return a < b;
        } else {
            return (a % 2 == 1);
        }
    }

public:
    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int pop() {
        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxValue;
    }

    bool empty() {
        return heap.empty();
    }
};

int main() {
    int T; // 테스트 케이스의 수
    cin >> T;

    while (T--) {
        int N; // 책의 개수
        cin >> N;

        PriorityQueue pq;

        for (int i = 0; i < N; ++i) {
            int book;
            cin >> book;
            pq.push(book);
        }

        vector<int> sortedBooks;

        while (!pq.empty()) {
            sortedBooks.push_back(pq.pop());
        }

        for (int i = 0; i < sortedBooks.size(); ++i) {
            cout << sortedBooks[i];
            if (i < sortedBooks.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
