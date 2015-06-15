/*
 * Sample Input

 5
 50
 30 5
 100 20 50
 10 x x 10
 Sample Output

 35
 */
#include <bits/stdc++.h>
using namespace std;
const int sz = 102;
int dp[sz][sz];
void floydwarshall(int n) {
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
}

void disp(int n) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	int n;
	string s;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < n; ++j) {
			dp[i][j] = INT_MAX / 2;
		}
		dp[i][i] = 0;
	}
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			cin >> s;
			if (s != "x") {
				dp[i][j] = atoi(s.c_str());
				dp[j][i] = atoi(s.c_str());
			}
		}
	}
	int res = 0;
	floydwarshall(n);
	for (int i = 2; i <= n; ++i) {
		res = max(res, dp[1][i]);
	}
	printf("%d\n", res);
	return 0;
}
