/*
 * 1 2000
 5 1 4 2 -1 6
 2 1999 1998
 4 1 4 2 3
 4 1 3 2 -2
 4 1 4 3 5
 4 1 2 5 7
 3 4 1 3
 4 1 4 2 3
 4 1 2 3 6
 2 1 3
 1 1

 Jolly
 Not jolly
 Jolly
 Jolly
 Not jolly
 Jolly
 Jolly
 Not jolly
 Jolly
 Not jolly
 Not jolly
 Jolly

 */
#include <bits/stdc++.h>
using namespace std;
bool visited[3003];
int main() {
	int n;
	int a, b;
	while (cin >> n) {
		fill(visited, visited + n + 1, 0);
		cin >> a;
		for (int i = 0; i < n - 1; ++i) {
			cin >> b;
			visited[abs(a - b)] = 1;
			a = b;
		}
		bool f = 1;
		for (int i = 1; i < n; ++i) {
			if (!visited[i]) {
				f = 0;
				break;
			}
		}
		if (f)
			cout << "Jolly\n";
		else
			cout << "Not jolly\n";
	}
	return 0;
}
