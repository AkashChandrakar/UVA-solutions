#include<bits/stdc++.h>
using namespace std;
int arr[50001];
int main()
{

	int n, q, x, y, h;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d", &h);
		x = lower_bound(arr, arr + n, h) - arr;
		if (arr[x] >= h && x > 0)
		{
			printf("%d ", arr[x - 1]);
		}
		else if(arr[n-1] < h)
		printf("%d ", arr[n - 1]);
		  else
			printf("X ");
		y = upper_bound(arr, arr + n, h) - arr;
		if (y != n)
			printf("%d\n", arr[y]);
		else
			 printf("X\n");
	}
	return 0;
}