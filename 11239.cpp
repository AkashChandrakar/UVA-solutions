#include <bits/stdc++.h>
using namespace std;
bool comp(pair<string, int> a, pair<string, int> b) {
	if (a.second == b.second)
		return a.first > b.first;
	return a.second > b.second;
}
int main() {
	string prj, uid, up, savprj, key;
	map<string, set<string> > projects;
	map<string, set<string> >::iterator it;
	set<string> victims;
	map<string, string> student;
	set<string> s;
	vector<pair<string, int> > res;
	vector<pair<string, int> >::iterator v;
	while (getline(cin, prj), prj != "0") {
		while (prj != "1") {
			up = prj;
			transform(up.begin(), up.end(), up.begin(), ::toupper);
			if (up == prj) {
				// a project
				savprj = prj;
				projects[prj] = set<string>();
			} else {
				//an student
				if (victims.count(prj) != 0)
					continue;
				if (student.count(prj) == 0) {
					student[prj] = savprj;
					s = projects[savprj];
					s.insert(prj);
					projects[savprj] = s;
				} else {
					if (savprj != student[prj]) {
						//student registered for more than 1 project
						key = student[prj];
						s = projects[key];
						s.erase(savprj);
						projects[key] = s;
						victims.insert(savprj);
					}
				}
			}
			getline(cin, prj);
		}
		//end of one test case
		for (it = projects.begin(); it != projects.end(); ++it) {
			res.push_back(make_pair(it->first, (it->second).size()));
		}
		//sort
		sort(res.begin(), res.end(), comp);
		//display
		for (v = res.begin(); v != res.end(); ++v) {
			cout << v->first << " " << v->second << endl;
		}
		//clear hash
		victims.clear();
		s.clear();
		projects.clear();
		student.clear();
		res.clear();
	}
	return 0;
}
