// ��������.cpp : �������̨Ӧ�ó������ڵ㡣
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

//ʱ�临�Ӷ�ΪO(n2)
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