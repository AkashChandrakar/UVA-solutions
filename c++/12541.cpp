#include <bits/stdc++.h>
using namespace std;
class student {
public:
	string name;
	int dd, mm, yy;
	void init(string n, int d, int m, int y) {
		name = n;
		dd = d;
		yy = y;
		mm = m;
	}
};
bool comp(student a, student b) {
	if (a.yy == b.yy) {
		if (a.mm == b.mm)
			return a.dd < b.dd;
		else
			return a.mm < b.mm;
	} else {
		return a.yy < b.yy;
	}
}
student s[100];
int findmin(int n) {
	int res = 0;
	for (int i = 1; i < n; ++i) {
		if (comp(s[i], s[res])) {
			res = i;
		}
	}
	return res;
}
int findmax(int n) {
	int res = 0;
	for (int i = 1; i < n; ++i) {
		if (comp(s[res], s[i])) {
			res = i;
		}
	}
	return res;
}
map<int, string> bday;
int main() {
	int cases;
	cin >> cases;
	string name;
	int dd, mm, yy;
	for (int t = 0; t < cases; ++t) {
		cin >> name >> dd >> mm >> yy;
		s[t].init(name, dd, mm, yy);
	}
	int i, j;
	i = findmin(cases);
	j = findmax(cases);
	cout << s[j].name << endl << s[i].name << endl;
	return 0;
}
