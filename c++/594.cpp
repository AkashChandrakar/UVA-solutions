#include <bits/stdc++.h>
using namespace std;

void swapbyte(int beg1, int beg2, int &n) {
	for (int i = 0; i < 8; ++i, --beg1, --beg2) {
		bool a = (1LL << beg1) & n;
		bool b = (1LL << beg2) & n;
		swap(a, b);
		if (a) {
			n |= (1 << beg1);
		} else {
			n &= ~(1 << beg1);
		}
		if (b) {
			n |= (1 << beg2);
		} else {
			n &= ~(1 << beg2);
		}
	}
}

void conv(int &n) {
	int beg1, beg2;
	beg1 = 31;
	beg2 = 7;
	swapbyte(beg1, beg2, n);
	beg1 = 23;
	beg2 = 15;
	swapbyte(beg1, beg2, n);
}
int main() {
	int n, org;
	while (cin >> n) {
		org = n;
		conv(n);
		printf("%d converts to %d\n", org, n);
	}
	return 0;

}
