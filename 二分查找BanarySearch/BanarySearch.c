// 二分查找BanarySearch.c

#include <stdio.h>

int BanarySearch(int a[], int, int);

int main()
{
	int a[6] = { 2,3,5,8,9,12 };
	printf("%d\n", BanarySearch(a, 6, 8));
    return 0;
}

//时间复杂度为O(logn)
int BanarySearch(int a[], int n, int x) {

	int left = 0;
	int right = n - 1;
	int center;
	while (left <= right) {
		center = (left + right) / 2;
		if (a[center] > x) {
			right = center - 1;
		}
		else if (a[center] < x) {
			left = center + 1;
		}
		else {
			return center;
		}
	}
	return -1;
}
