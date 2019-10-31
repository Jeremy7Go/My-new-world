//大于等于5的质数一定与6的倍数相邻
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int all[2000001], n6[2000001]; //全局变量
int main()
{
    int n, m;               //默认输入的第一个数n大于第二个数m
    int u, j;               //开方工具数
    int i, c, d = 0, k = 0; //循环工具数
    scanf("%d %d", &n, &m);
    //检查m,n
    if (n == m)
    {
        u = sqrt(n);
        for (c = 2; c <= u; c++)
        {
            if (n % c == 0)
                break;
            else if (c == u)
                printf("%d", n);
        }
    }
    else
    {
        //对于小于5的数的判断
        if (m <= 2)
        {
            all[d++] = 2;
        }
        else if (m >= 3 && n <= 2)
        {
            all[d++] = 2;
            all[d++] = 3;
        }
        else if (n == 3)
        {
            all[d++] = 3;
        }
        //构建与6的倍数相邻的数字的数组
        for (i = 1; 6 * i - 1 <= m; i++)
        {
            if (6 * i - 1 <= m && 6 * i - 1 >= n)
            {
                n6[k++] = 6 * i - 1;
            }
            if (6 * i + 1 <= m && 6 * i + 1 >= n)
            {
                n6[k++] = 6 * i + 1;
            }
        }
        //找质数
        for (i = 0; i < k; i++)
        {
            j = sqrt(n6[i]);
            for (c = 2; c <= j; c++)
            {
                if (n6[i] % c == 0)
                    break;
                else if (c == j)
                    all[d++] = n6[i];
            }
        }

        //输出
        for (i = 0; i < d; i++)
        {
            if (i == 0)
                printf("%d ", all[0]);
            else if ((i + 1) % 5 == 0)
                printf("%d\n", all[i]);

            else
                printf("%d ", all[i]);
        }
    }
    system("pause");
}
