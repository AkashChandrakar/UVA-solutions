#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
vector<int> v;
const int INF = INT_MAX / 4;
const int sz = 110;
int dp[sz][sz];
set<int> s;
void floydwarshall(int n) {
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
}
int main() {
	int u, v, n, cases = 0;
	while (scanf("%d %d", &u, &v) && u) {
		n = 0;
		s.clear();
		fill(&dp[0][0], &dp[sz][0], INF);
		dp[u][v] = 1;
		s.insert(u);
		s.insert(v);
		n = max(n, u);
		n = max(n, v);
		while (scanf("%d %d", &u, &v) && u) {
			dp[u][v] = 1;
			n = max(n, u);
			n = max(n, v);
			s.insert(u);
			s.insert(v);

		}
		floydwarshall(n);
		double div, sum = 0.0;
		div = s.size() * (s.size() - 1);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (dp[i][j] != INF && i != j)
					sum += dp[i][j];
			}
		}
		sum = sum / div;
		printf("Case %d: average length between pages = %.3lf clicks\n",
				++cases, sum);
	}

	return 0;
}
