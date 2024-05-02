
#include <iostream>
#include <vector>

using namespace std;

// 수열의 우선순위를 결정하는 비교 함수
bool compare(int x, int y) {
    if (x % 5 == 0 && y % 5 != 0) {
        return true;
    }
    if (x % 5 != 0 && y % 5 == 0) {
        return false;
    }
    if (x > y) {
        return true;
    }
    return false;
}

// 수열을 우선순위에 따라 정렬하는 함수
void prioritySort(vector<int>& arr) {
    int n = arr.size(); // 7
    int cur = -1;
    int idx = 0;

    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j < arr.size(); j++) {
            if (compare(arr[j], cur)) {
                cur = arr[j];
                idx = j;
            }
        }

        cout << cur << ' ';
        cur = -1;
        arr.erase(arr.begin() + idx);
        
    }
    cout << "\n";
}

// 수열을 출력하는 함수
void printSequence(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;
        vector<int> sequence;
        for (int i = 0; i < N; i++) {
            int x; 
            cin >> x;
            sequence.push_back(x);
        }
        prioritySort(sequence);
        printSequence(sequence);
    }

    return 0;
}

