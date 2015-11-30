#include<stdio.h>
#include<string.h>
#include <algorithm>
using namespace std;
const int sz = 110;
char s1[sz], s2[sz];
int c1[26], c2[26];
int main() {

	scanf("%s %s", s1, s2);
	for (int i = 0; i < strlen(s1); ++i) {
		++c1[s1[i] - 'A'];
	}
	for (int i = 0; i < strlen(s2); ++i) {
		++c2[s2[i] - 'A'];
	}
	sort(c1, c1 + 26);
	sort(c2, c2 + 26);
	bool ans = 1;
	for (int i = 0; i < 26; ++i) {
		if (c1[i] != c2[i]) {
			ans = 0;
			break;
		}
	}
	if (ans)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}
