#include<iostream>
#include<vector>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		vector<int> s;
		vector<int> d;
		int max = 0;

		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			s.push_back(x);
			if (max < x)
				max = x;
		}

		for (int j = 0; j < n; j++) {
			int cur = 0;
			int idx = 0;

			for (int k = 0; k < s.size(); k++) { // s.size() = 7
				if (s[k] > cur) {
					cur = s[k];
					idx = k;
				}
			}
			cout << cur << ' ';
			s.erase(s.begin() + idx);
			if (max == cur) continue;
			d.push_back(max - cur);
		}
		cout << '\n';
		for (int num : d)
			cout << num << " ";
		cout << '\n';
		
	}
	

	return 0;
}
