// ŷ���������������㷨.c
// �ж�����������Gcd(a,b)==1

#include <stdio.h>

int Gcd(int, int);

int main()
{
	printf("%d\n", Gcd(55, 15));
    return 0;
}

//ʱ�临�Ӷ�Ϊo(logn)
int Gcd(int m, int n) {
	int rem;
	while (n > 0) {
		rem = m%n;
		m = n;
		n = rem;
	}
	return m;
}
