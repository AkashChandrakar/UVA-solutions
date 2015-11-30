#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const int ROW = 10010;
const int COL = 12;
int mat[ROW][COL];
map<ii, int> mp;
string s;
hash<string> str_hash;
int main() {
	int r, c, i, j, k, r1, c1, r2, c2;
	ii p;
	string str;
	while (cin >> r >> c) {
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		for (i = 0; i < r; ++i) {
			getline(cin, s);
			k = 0;
			for (j = 0; j < c - 1; ++j) {
				str = "";
				while (s[k] != ',') {
					str += s[k];
					++k;
				}
				++k;
				mat[i][j] = str_hash(str);
			}
			str = "";
			while (k < (int) s.length()) {
				str += s[k];
				++k;
			}
			mat[i][j] = str_hash(str);
		}
		mp.clear();
		bool ans = 0;
		for (i = 0; i < r && !ans; ++i) {
			for (int j = 0; j < c && !ans; ++j) {
				for (int k = j + 1; k < c && !ans; ++k) {
					p = ii(mat[i][j], mat[i][k]);
					if (mp.find(p) == mp.end()) {
						mp[p] = i;
					} else {
						r1 = mp[p];
						r2 = i;
						c1 = j;
						c2 = k;
						ans = 1;
						break;
					}
				}
			}
		}
		if (!ans) {
			printf("YES\n");
		} else {
			printf("NO\n%d %d\n%d %d\n", ++r1, ++r2, ++c1, ++c2);
		}
	}

	return 0;
}
