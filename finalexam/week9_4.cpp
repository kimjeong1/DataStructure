#include <iostream>
#include <vector>

using namespace std;

struct compare {
    bool operator()(const int& lhs, const int& rhs) {
        int l = lhs;
        int r = rhs;
        while (1) {
            l /= 10;
            r /= 10;
            if (l == 0 || r == 0) {
                break;
            }
        }
        if (l == 0 && r == 0) return lhs < rhs;
        else return lhs > rhs;
    }
};

void insertion(vector<int>& arr) {
    compare c;
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && c(key, arr[j])) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> s(n);

        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        insertion(s);

        cout << "Case #" << i + 1 << ".\n";
        for (int j = 0; j < n; j++) {
            cout << s[j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
