/ *从1到n的累加*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    unsigned long m,n;
    printf("please input n = ");
    scanf("%u",&n);
    m = (n+1)*n/2;
    printf("the sum is %u \n",m);
    system("pause");
}
