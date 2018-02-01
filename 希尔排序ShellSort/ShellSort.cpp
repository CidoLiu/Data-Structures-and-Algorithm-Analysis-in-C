// ShellSort.cpp
//

#include <stdio.h>

void ShellSort(int[], int);

int main()
{
	int a[10] = { 3,6,4,9,2,1,5,12,36,50 };
	ShellSort(a, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}
    return 0;
}
//时间复杂度：不确定，和所选取的希尔序列有关
void ShellSort(int a[], int n) {
	int i, j, increment;
	int temp;
	for (increment = n / 2; increment > 0; increment /= 2) {
		for (i = increment; i < n; i++) {
			temp = a[i];
			for (j = i; j >= increment; j -= increment) {
				if (temp < a[j - increment]) {
					a[j] = a[j - increment];
				}
				else {
					break;
				}
			}
			a[j] = temp;
		}
	}
}
