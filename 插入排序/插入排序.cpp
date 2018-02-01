// 插入排序.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void InsertionSort(int a[], int n);

int main()
{
	int a[7] = { 3,2,6,1,5,9,7 };
	InsertionSort(a, 7);
	for (int i = 0; i < 7; i++) {
		printf("%d\n", a[i]);
	}
    return 0;
}

//时间复杂度为O(n2)
void InsertionSort(int a[], int n) {
	int i, j;
	int temp;
	for (i = 1; i < n; i++) {
		temp = a[i];
		for (j = i; j > 0 && a[j-1] > temp; j--) {
			a[j] = a[j - 1];
		}
		a[j] = temp;
	}
}