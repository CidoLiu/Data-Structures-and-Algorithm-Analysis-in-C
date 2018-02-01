
// �������������������к�
// 2017/8/3

#include <stdio.h>

int MaxSubsequenceSum1(int a[], int n);
int MaxSubsequenceSum2(int a[], int n);
int MaxSubsequenceSum3(int a[], int n);
static int MaxSubSum(int a[], int, int);
int MaxSubsequenceSum4(int a[], int n);

int main()
{
	int a[6] = { -2,11,-4,13,-5,-2 };
	printf("Alg1:%d\n", MaxSubsequenceSum1(a, 6));
	printf("Alg2:%d\n", MaxSubsequenceSum2(a, 6));
	printf("Alg3:%d\n", MaxSubsequenceSum3(a, 6));
	printf("Alg4:%d\n", MaxSubsequenceSum4(a, 6));
    return 0;
}

//�㷨1��ʱ�临�Ӷ�O(n3)
int MaxSubsequenceSum1(int a[],int n) {

	int thisSum, maxSum, i, j, k;

	maxSum = 0;
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			thisSum = 0;
			for (k = i; k < j; k++) {
				thisSum += a[k];
			}
			if (thisSum>maxSum)
			{
				maxSum = thisSum;
			}
		}
	}
	return maxSum;
}

//�㷨2��ʱ�临�Ӷ�O(n2)
int MaxSubsequenceSum2(int a[], int n) {

	int thisSum, maxSum, i, j;
	maxSum = 0;
	for (i = 0; i < n; i++) {
		thisSum = 0;
		for ( j = i; j < n; j++){
			thisSum += a[j];
			if (thisSum>maxSum) {
				maxSum = thisSum;
			}
		}
	}
	return maxSum;
}

//�㷨3��ʱ�临�Ӷ�ΪO(nlogn)
int MaxSubsequenceSum3(int a[], int n) {
	return MaxSubSum(a, 0, n - 1);
}

static int MaxSubSum(int a[], int left, int right) {
	int maxLeftSum, maxRightSum;
	int maxLeftBorderSum, maxRightBorderSum;
	int leftBorderSum, rightBorderSum;
	int center, i;

	if (left == right) {
		if (a[left]>0){
			return a[left];
		}
		else {
			return 0;
		}
	}

	center = (left + right) / 2;
	maxLeftSum = MaxSubSum(a, left, center);
	maxRightSum = MaxSubSum(a, center + 1, right);

	maxLeftBorderSum = 0;
	leftBorderSum = 0;
	for ( i = center; i >=left ; i--)
	{
		leftBorderSum += a[i];
		if (leftBorderSum > maxLeftBorderSum) {
			maxLeftBorderSum = leftBorderSum;
		}
	}

	maxRightBorderSum = 0;
	rightBorderSum = 0;
	for ( i = center+1; i < right; i++)
	{
		rightBorderSum += a[i];
		if (rightBorderSum > maxRightBorderSum) {
			maxRightBorderSum = rightBorderSum;
		}
	}

	return (maxLeftSum > maxRightSum ? maxLeftSum : maxRightSum) > (maxLeftBorderSum + maxRightBorderSum) ?
		(maxLeftSum > maxRightSum ? maxLeftSum : maxRightSum) : (maxLeftBorderSum + maxRightBorderSum);
}

//�㷨4��ʱ�临�Ӷ�ΪO(n)
//�����㷨��������ʱ�̶��ܶ����Ѿ���������ݸ����������������ȷ��
int MaxSubsequenceSum4(int a[], int n) {
	int thisSum, maxSum, i;
	thisSum = maxSum = 0;
	for ( i = 0; i < n; i++){
		thisSum += a[i];
		if (thisSum > maxSum) {
			maxSum = thisSum;
		}
		else if (thisSum < 0) {
			thisSum = 0;
		}
	}
	return maxSum;
}
