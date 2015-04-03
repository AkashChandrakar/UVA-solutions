#include <bits/stdc++.h>
using namespace std;
int trains[51];

int countInversion(int n) {
	int res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (trains[i] > trains[j])
				++res;
		}
	}
	return res;
}

int main() {
	int cases;
	int n;
	cin >> cases;
	for (int i = 0; i < cases; ++i) {
		cin >> n;
		for (int j = 0; j < n; ++j) {
			cin >> trains[j];
		}
		cout << "Optimal train swapping takes " << countInversion(n)
				<< " swaps." << endl;
	}
	return 0;
}
