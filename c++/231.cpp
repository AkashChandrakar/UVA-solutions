#include <bits/stdc++.h>
using namespace std;
vector<int> height;
int maxInterception(vector<int> &height) {
	int res = 1;
	vector<int> LDS(height.size(), 1);
	for (int i = 1; i < height.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (height[i] < height[j]) {
				LDS[i] = max(LDS[i], LDS[j] + 1);
			}
		}
		res = max(res, LDS[i]);
	}
	return res;
}

int main() {
	int a;
	int tno = 1;
	bool blank = 0;
	while (1) {
		while (cin >> a && a != -1) {
			height.push_back(a);
		}
		if (blank)
			cout << endl;
		blank = 1;
		cout << "Test #" << tno << ":" << endl;
		++tno;
		cout << "  maximum possible interceptions: " << maxInterception(height)
				<< endl;
		height.clear();
		cin >> a;
		if (a == -1)
			break;
		height.push_back(a);
	}
	return 0;
}
