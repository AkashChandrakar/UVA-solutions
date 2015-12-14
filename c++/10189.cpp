#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
vector<int> v;
const int sz = 110;
set<ii> bombs;
set<ii>::iterator it;
char s[sz][sz], res[sz][sz];
int dx[] = { -1, 1, -1, 0, 1, -1, 0, 1 };
int dy[] = { 0, 0, 1, 1, 1, -1, -1, -1 };
int n, m;
bool isvalid(int a, int b) {
	if (a >= 0 && a < n && b >= 0 && b < m)
		return 1;
	return 0;
}
int main() {
	int fno = 0, x, y, a, b;
	bool blank = 0;
	while (scanf("%d %d", &n, &m) && n) {
		bombs.clear();
		fill(&res[0][0], &res[sz][0], '0');
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("\n%c", &s[i][j]);
				if (s[i][j] == '*')
					bombs.insert(ii(i, j));
			}
		}
		for (it = bombs.begin(); it != bombs.end(); ++it) {
			x = it->first;
			y = it->second;
			for (int i = 0; i < 8; ++i) {
				a = x + dx[i];
				b = y + dy[i];
				if (isvalid(a, b)) {
					++res[a][b];
				}
			}
		}
		for (it = bombs.begin(); it != bombs.end(); ++it) {
			x = it->first;
			y = it->second;
			res[x][y] = '*';
		}
		if (blank)
			printf("\n");
		blank = 1;
		printf("Field #%d:\n", ++fno);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				printf("%c", res[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}
