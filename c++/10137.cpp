#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
vector<double> v;
const int sz = 1010;
double a[sz];
inline double round(double val) {
	if (val < 0)
		return ceil(val - 0.5);
	return floor(val + 0.5);
}
int main() {
	int n;
	double sum, res1, res2;
	while (scanf("%d", &n) && n) {
		res2 = res1 = sum = 0.0;
		for (int i = 0; i < n; ++i) {
			scanf("%lf", &a[i]);
			sum += a[i];
		}
		sum /= n;
		sum = round(sum * 100.0) / 100.0;
		for (int i = 0; i < n; ++i) {
			if (a[i] > sum) {
				res1 += (a[i] - sum);
			} else {
				res2 += (sum - a[i]);
			}
		}
		if (res1 > res2)
			printf("$%.2lf\n", res2);
		else
			printf("$%.2lf\n", res1);
	}

	return 0;
}
