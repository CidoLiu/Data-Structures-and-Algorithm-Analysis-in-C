// 欧几里得求最大公因数算法.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int Gcd(int, int);

int main()
{
	printf("%d\n", Gcd(55, 15));
    return 0;
}

//时间复杂度为o(logn)
int Gcd(int m, int n) {
	
	int rem;
	while (n > 0) {
		rem = m%n;
		m = n;
		n = rem;
	}
	return m;
}
