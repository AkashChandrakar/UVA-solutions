/*
 1 3
 2 3 4
 3 4 5 6
 1 6
 1 7
 2 12 13
 1 8
 2 9 10
 1 11
 1 11
 2 12 17
 1 14
 2 14 15
 2 15 16
 1 16
 1 19
 2 18 19
 1 20
 1 20
 5
 1 20
 2 9
 19 5
 18 19
 16 20
 4 2 3 5 6
 1 4
 3 4 10 5
 5 10 11 12 19 18
 2 6 7
 2 7 8
 2 9 10
 1 9
 1 10
 2 11 14
 3 12 13 14
 3 18 17 13
 4 14 15 16 17
 0
 0
 0
 2 18 20
 1 19
 1 20
 6
 1 20
 8 20
 15 16
 11 4
 7 13
 2 16

 O/P
 Test Set #1
 1 to 20: 7
 2 to 9: 5
 19 to 5: 6
 18 to 19: 2
 16 to 20: 2

 Test Set #2
 1 to 20: 4
 8 to 20: 5
 15 to 16: 2
 11 to 4: 1
 7 to 13: 3
 2 to 16: 4
 */

#include <iostream>
#include <stdio.h>
#include <limits.h>
using namespace std;
const int sz = 22;
int dp[sz][sz];
void reset() {
	for (int i = 0; i < 21; ++i) {
		for (int j = 0; j < 21; ++j) {
			dp[i][j] = INT_MAX / 2;
		}
		dp[i][i] = 0;
	}
}
void floydwarshall() {
	for (int k = 1; k < 21; ++k) {
		for (int i = 1; i < 21; ++i) {
			for (int j = 1; j < 21; ++j) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
}
int main() {
	int n, a, x, y;
	int cases = 1;
	bool blank = 0;
	while (cin >> n) {
		reset();
		for (int i = 0; i < n; ++i) {
			cin >> a;
			dp[1][a] = 1;
			dp[a][1] = 1;
		}
		for (int i = 2; i < 20; ++i) {
			cin >> n;
			for (int j = 0; j < n; ++j) {
				cin >> a;
				dp[i][a] = 1;
				dp[a][i] = 1;
			}
		}
		if (blank)
			cout << endl;
		blank = 1;
		cin >> n;
		cout << "Test Set # " << cases << endl;
		floydwarshall();
		for (int i = 0; i < n; ++i) {
			cin >> x >> y;
			printf("%d to %d: %d\n", x, y, dp[x][y]);
		}
		++cases;
	}
	return 0;
}
