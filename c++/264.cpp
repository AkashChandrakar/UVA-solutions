/*
 * Input:
 4
 3
 14
 7
 20

 Output:
 TERM 3 IS 2/1
 TERM 14 IS 2/4
 TERM 7 IS 1/4
 TERM 20 IS 5/2
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int x, y;
	bool up = 0;
	while (cin >> n) {
		x = y = 1;
		for (int i = 1; i < n; ++i) {
			if (x == 1) {
				up = 0;
				if (y & 1) {
					++y;
				} else {
					++x;
					--y;
				}
			} else if (y == 1 && x != 1) {
				up = 1;
				if (x & 1) {
					--x;
					++y;
				} else {
					++x;
				}
			} else {
				if (up) {
					--x;
					++y;
				} else {
					++x;
					--y;
				}
			}
		}
		printf("TERM %d IS %d/%d\n", n, x, y);
	}
	return 0;
}
