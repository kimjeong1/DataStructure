#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 비교 함수 정의
bool compare(int a, int b) {
    // 최대 자릿수 계산
    int maxDigitA = to_string(a).length();
    int maxDigitB = to_string(b).length();
    
    if (maxDigitA == maxDigitB) {
        return a < b; // 자릿수가 같으면 작은 수가 우선
    }
    return maxDigitA > maxDigitB; // 자릿수가 다르면 자릿수가 큰 수가 우선
}

// 삽입 정렬 함수
void insertionSort(vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;

        // 비교 함수에 따라 정렬
        while (j >= 0 && compare(key, arr[j])) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int T; // 테스트 케이스의 수
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N; // 수열 S의 크기
        cin >> N;

        vector<int> S(N); // 수열 S

        // 수열 S 입력
        for (int i = 0; i < N; ++i) {
            cin >> S[i];
        }

        // 삽입 정렬을 사용하여 정렬
        insertionSort(S);

        // 결과 출력
        cout << "Case #" << t << "." << endl;
        for (int i = 0; i < N; ++i) {
            cout << S[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
