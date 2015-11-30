#include <stdio.h>
#include <string.h>
const int sz = 1010;
char org[sz], modified[sz];
int main() {
	bool open = 1;
	int len, i, j;
	while (gets(org)) {
		len = strlen(org);
		j = 0;
		for (i = 0; i < len; ++i) {
			if (org[i] == '"') {
				if (open) {
					open = 0;
					modified[j++] = '`';
					modified[j++] = '`';
				} else {
					open = 1;
					modified[j++] = '\'';
					modified[j++] = '\'';
				}
			} else {
				modified[j++] = org[i];
			}
		}
		modified[j] = '\0';
		printf("%s\n", modified);
	}
	return 0;
}
