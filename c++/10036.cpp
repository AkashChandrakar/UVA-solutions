/*
 * Sample Input
 2
 4 7
 17 5 -21 15
 4 5
 17 5 -21 15
 Sample Output
 Divisible
 Not divisible
 */
#include <bits/stdc++.h>
using namespace std;
map<string, bool> hash;
int a[100];
int n, k;
bool isdivisible(int st) {
	if (st == n - 1)
		return a[st] % k == 0;
	int sv = a[st + 1];
	a[st + 1] += a[st];
	bool f1 = isdivisible(st + 1);
	a[st + 1] -= 2 * sv;
	bool f2 = isdivisible(st + 1);
	return f1 | f2;
}
int main() {
	string s;
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		scanf("%d %d", &n, &k);
		for (int j = 0; j < n; ++j) {
			scanf("%d", &a[j]);
		}
		cout << isdivisible(0);
	}
	return 0;
}
