/*
�ݹ��ӡһ����������ϵͳֻ��һ��printf�������ú���һ��ֻ�ܴ�ӡһλ����
ͨ���ݹ���ô�ӡ��һ����������
2018/2/1
*/

#include <stdio.h>

void PrintOut(int n){
    if(n>=10){
        PrintOut(n/10);
    }
    printf("%d",n%10);

}

/*
-------->
n     12345   1234   123   12  1    ��ջ����

<--------
n%10  5       4      3     2   1    ��ջ��ӡ
*/

int main(){
    int n=12345;
    PrintOut(n);
    return 0;
}
