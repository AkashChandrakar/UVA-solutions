#include <bits/stdc++.h>
using namespace std;
const int sz = 52;
char grid[sz][sz];
bool dfs(int n, int m, string word, int widx, int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= m)
		return false;
	if (widx == word.length() - 1)
		return true;
	if (word[widx] != grid[i][j])
		return false;
	char c = grid[i][j];
	grid[i][j] = '#';
	if (dfs(n, m, word, widx + 1, i + 1, j)) {
		grid[i][j] = c;
		return true;
	}
	if (dfs(n, m, word, widx + 1, i - 1, j)) {
		grid[i][j] = c;
		return true;
	}
	if (dfs(n, m, word, widx + 1, i, j + 1)) {
		grid[i][j] = c;
		return true;
	}
	if (dfs(n, m, word, widx + 1, i, j - 1)) {
		grid[i][j] = c;
		return true;
	}
	if (dfs(n, m, word, widx + 1, i + 1, j + 1)) {
		grid[i][j] = c;
		return true;
	}
	if (dfs(n, m, word, widx + 1, i + 1, j - 1)) {
		grid[i][j] = c;
		return true;
	}
	if (dfs(n, m, word, widx + 1, i - 1, j + 1)) {
		grid[i][j] = c;
		return true;
	}
	if (dfs(n, m, word, widx + 1, i - 1, j - 1)) {
		grid[i][j] = c;
		return true;
	}
	grid[i][j] = c;
	return false;
}
void findWord(int n, int m, string word) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (word[0] == grid[i][j]) {
				if (word.length() == 1) {
					cout << i + 1 << " " << j + 1 << endl;
					return;
				}
				if (dfs(n, m, word, 0, i, j)) {
					cout << i + 1 << " " << j + 1 << endl;
					return;
				}
			}
		}
	}
	return;
}

void disp(int n, int m) {
	cout << "---------------" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << grid[i][j];
		}
		cout << endl;
	}
	cout << "---------------" << endl;
}
int main() {
	int cases;
	cin >> cases;
	string line, word;
	int n, m, q;
	for (int t = 0; t < cases; ++t) {
		//read blank line
		getline(cin, line);
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> grid[i][j];
				grid[i][j] = toupper(grid[i][j]);
			}
		}
		cin >> q;
		for (int i = 0; i < q; ++i) {
			cin >> word;
			for (int j = 0; j < word.length(); ++j) {
				word[j] = toupper(word[j]);
			}
			findWord(n, m, word);
		}
		if(t!=cases)
		cout << endl;
	}
	return 0;
}
