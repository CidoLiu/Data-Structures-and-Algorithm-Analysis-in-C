/*
递归打印一个数，假设系统只有一个printf函数，该函数一次只能打印一位数字
通过递归调用打印出一个完整的数
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
n     12345   1234   123   12  1    入栈结束

<--------
n%10  5       4      3     2   1    出栈打印
*/

int main(){
    int n=12345;
    PrintOut(n);
    return 0;
}
