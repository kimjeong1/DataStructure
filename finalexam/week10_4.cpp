#include <iostream>
#include <vector>

using namespace std;

// 최대 힙을 위한 비교 함수
bool maxHeapCompare(int a, int b) {
    return a > b;
}

// 최소 힙을 위한 비교 함수
bool minHeapCompare(int a, int b) {
    return a < b;
}

class PriorityQueue {
private:
    vector<int> heap;
    bool (*compare)(int, int);

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

public:
    PriorityQueue(bool (*compareFunc)(int, int)) : compare(compareFunc) {}

    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int pop() {
        int topValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return topValue;
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

        PriorityQueue oddHeap(maxHeapCompare); // 홀수 최대 힙
        PriorityQueue evenHeap(minHeapCompare); // 짝수 최소 힙

        for (int i = 0; i < N; ++i) {
            int book;
            cin >> book;
            if (book % 2 == 0) {
                evenHeap.push(book);
            } else {
                oddHeap.push(book);
            }
        }

        vector<int> sortedBooks;

        while (!evenHeap.empty()) {
            sortedBooks.push_back(evenHeap.pop());
        }
        while (!oddHeap.empty()) {
            sortedBooks.push_back(oddHeap.pop());
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
