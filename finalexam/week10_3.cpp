#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 최대 힙 클래스 정의
class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] < heap[index]) {
                swap(heap[parent], heap[index]);
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

            if (left < size && heap[left] > heap[largest]) {
                largest = left;
            }
            if (right < size && heap[right] > heap[largest]) {
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
    bool empty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }

    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int top() {
        if (heap.empty()) return -1;
        return heap[0];
    }

    int pop() {
        if (heap.empty()) return -1;
        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxValue;
    }

    int second_top() {
        if (heap.size() < 2) return -1;
        if (heap.size() == 2) return heap[1];
        return max(heap[1], heap[2]);
    }
};

int main() {
    int N;
    cin >> N;

    MaxHeap maxHeap;

    for (int i = 0; i < N; ++i) {
        string command;
        cin >> command;

        if (command == "empty") {
            cout << maxHeap.empty() << endl;
        } else if (command == "size") {
            cout << maxHeap.size() << endl;
        } else if (command == "push") {
            int value;
            cin >> value;
            maxHeap.push(value);
        } else if (command == "pop") {
            int result = maxHeap.pop();
            if (result == -1) {
                cout << -1 << endl;
            } else {
                cout << result << endl;
            }
        } else if (command == "top") {
            int result = maxHeap.top();
            if (result == -1) {
                cout << -1 << endl;
            } else {
                cout << result << endl;
            }
        } else if (command == "second_top") {
            int result = maxHeap.second_top();
            if (result == -1) {
                cout << "Error" << endl;
            } else {
                cout << result << endl;
            }
        }
    }

    return 0;
}
