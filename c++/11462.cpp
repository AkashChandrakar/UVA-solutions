#include <bits/stdc++.h>
using namespace std;
int ages[101];
int main() {
	int n, idx;
	int flag = 0;
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		memset(ages, 0, sizeof(ages));
		flag = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &idx);
			ages[idx]++;
		}
		for (int i = 0; i < 101; ++i) {
			for (int j = 0; j < ages[i]; ++j) {
				if (flag)
					printf(" ");
				flag = 1;
				printf("%d", i);
			}
		}
		printf("\n");
	}
	return 0;
}
