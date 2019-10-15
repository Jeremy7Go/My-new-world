#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//定义全局变量！！！
char n[100];
int x[110], z[210];
int main()
{
    int len1, i, j;
    printf("please input n = ");
    gets(n);
    len1 = strlen(n);

    //实现大数n*n
    for (j = 0, i = len1 - 1; i >= 0; i--) //将字符转换为数字，并倒序保存（乘法先从末位开始）
    {
        x[j++] = n[i] - '0'; //字符串与整数的储存差异
    }
    for (i = 0; i < len1; i++) //模拟笔算竖乘,进位在下一步统一处理
    {
        for (j = 0; j < len1; j++)
        {
            z[i + j] += x[i] * x[j]; //将两数每一位相乘
        }
    }
    for (i = 0; i < 200; i++) //进行进位处理
    {
        if (z[i] >= 10)
        {
            z[i + 1] += z[i] / 10; //进位
            z[i] = z[i] % 10;      //保留个位数
        }
    }
    //实现大数n*n + n
    for (i = 0; i < 200; i++)
    {
        if (i <= 100)
        {
            z[i] += x[i];
            if (z[i] >= 10)
            {
                z[i] -= 10; //保留个位
                z[i + 1]++; //满十进一
            }
        }
    }

    //实现n*(n+1)/2
    for (i = 200; i >= 0; i--) //模拟笔算做除法
    {
        z[i - 1] = z[i - 1] + (z[i] % 2) * 10;
        z[i] = z[i] / 2;
    }
    //输出时的处理
    for (i = 200; i >= 0; i--) //删除0的前缀
    {
        if (z[i] == 0)
            continue;
        else
            break;
    }
    printf("the sum is ");
    for (; i >= 0; i--) //倒序输出
    {
        printf("%d", z[i]);
    }
    printf("\n");
    system("pause");
}
