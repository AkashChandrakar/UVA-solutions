#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 10002;
ll array[sz];
ll merge(int low, int mid, int high) {
	int lsize, rsize;
	ll res = 0L;
	lsize = mid - low + 1;
	rsize = high - mid;
	ll left[lsize + 1], right[rsize + 1];
	int i, j, k;
	k = 0;
	for (i = low; i <= mid; ++i) {
		left[k++] = array[i];
	}
	k = 0;
	for (j = mid + 1; j <= high; ++j) {
		right[k++] = array[j];
	}
	right[rsize] = left[lsize] = LONG_LONG_MAX;
	i = j = 0;
	for (k = low; k <= high; ++k) {
		if (left[i] > right[j]) {
			//count inversion
			res += (lsize - i);
			array[k] = right[j++];
		} else {
			array[k] = left[i++];
		}
	}
	return res;
}

ll merge_sort(int low, int high) {
	if (low < high) {
		ll left = 0L, right = 0L, total = 0L;
		int mid = low + (high - low) / 2;
		left = merge_sort(low, mid);
		right = merge_sort(mid + 1, high);
		total = left + right;
		total += merge(low, mid, high);
		return total;
	} else {
		return 0;
	}
}
int main() {
	int n;
	ll res;
	while (cin >> n) {
		for (int i = 0; i < n; ++i) {
			cin >> array[i];
		}
		res = merge_sort(0, n - 1);
		cout << "Minimum exchange operations : " << res << endl;
	}
	return 0;
}
