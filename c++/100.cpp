#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
vector<int> v;
map<int, int> hsh;

int findlength(int i) {
	if (i == 1)
		return 1;
	if (hsh.find(i) != hsh.end())
		return hsh[i];
	int res;
	if (i & 1) {
		res = findlength(3 * i + 1) + 1;
	} else {
		res = findlength(i / 2) + 1;
	}
	hsh[i] = res;
	return hsh[i];
}

int main() {
	int i, j, maxcyclelen;
	bool swp;
	while (scanf("%d %d", &i, &j) != EOF) {
		swp = 0;
		maxcyclelen = 0;
		if (i > j) {
			swap(i, j);
			swp = 1;
		}
		for (int k = i; k <= j; ++k) {
			maxcyclelen = max(maxcyclelen, findlength(k));
		}
		if (swp)
			swap(i, j);
		printf("%d %d %d\n", i, j, maxcyclelen);
	}

	return 0;
}
