#include <bits/stdc++.h>
using namespace std;
map<char, char> hash;
void fill() {
	hash['A'] = 'A';
	hash['E'] = '3', hash['3'] = 'E';
	hash['H'] = 'H';
	hash['I'] = 'I';
	hash['J'] = 'L', hash['L'] = 'J';
	hash['M'] = 'M';
	hash['O'] = 'O';
	hash['S'] = '2', hash['2'] = 'S';
	hash['T'] = 'T';
	hash['U'] = 'U';
	hash['V'] = 'V';
	hash['W'] = 'W';
	hash['X'] = 'X';
	hash['Y'] = 'Y';
	hash['Z'] = '5', hash['5'] = 'Z';
	hash['1'] = '1';
	hash['8'] = '8';
}
const int sz = 10010;
char s[sz];

bool ispalin() {
	int len = strlen(s);
	int i, j;
	i = 0;
	j = len - 1;
	while (i < j) {
		if (s[i] != s[j])
			return 0;
		++i;
		--j;
	}
	return 1;
}

bool ismirrored() {
	int len = strlen(s);
	int i, j;
	i = 0;
	j = len - 1;
	while (i <= j) {
		if (hash.find(s[i]) == hash.end())
			return 0;
		if (hash[s[i]] != s[j])
			return 0;
		++i;
		--j;
	}
	return 1;
}

int main() {
	bool pal, mirror;
	fill();
	while (scanf("%s", s) != EOF) {
		pal = ispalin();
		mirror = ismirrored();
		printf("%s -- ", s);
		if (pal && mirror) {
			printf("is a mirrored palindrome.");
		} else if (!pal && mirror) {
			printf("is a mirrored string.");
		} else if (pal && !mirror) {
			printf("is a regular palindrome.");
		} else {
			printf("is not a palindrome.");
		}
		printf("\n\n");
	}
	return 0;
}
