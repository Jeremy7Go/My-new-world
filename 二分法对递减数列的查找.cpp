//输出要查找的数在数列中的位置（从左至右第几位）
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, m;
    int i, j; //循环工具数
    scanf("%d %d", &n, &m);// n为递减数列大小，m为所有要查找的目标的个数
    int num[n], aim[m];
    int fst, end, mid; //代数工具数
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num[i]); 
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d", &aim[i]);
    }
    //开始查找
    for (i = 0; i < m; i++)//面向aim数组的循环
    {
        fst = 0;//首数下标
        end = n - 1;//尾数下标

        for (j = 0;; j++)//无对象的循环(查找用)
        {
            mid = (fst + end) / 2;//中间数字下标
            if (fst >= end)
            {
                if (aim[i] == num[mid])
                {
                    printf("%d\n", mid + 1);//实际位数为数组下标加1
                    break;
                }
                else
                {
                    printf("none\n");
                    break;
                }
            }
            else if (aim[i] == num[mid])
            {
                printf("%d\n", mid + 1);
                break;
            }
            else if (aim[i] > num[mid])
            {
                end = mid - 1;
                continue;
            }
            else if (aim[i] < num[mid])
            {
                fst = mid + 1;
                continue;
            }
        }
    }

    system("pause");
}
