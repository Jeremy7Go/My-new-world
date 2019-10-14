#include <stdio.h>
#include<stdlib.h>
#include <string.h>
int main()
{
    int i, n, A;
    char ch[100];
    printf("\n请输入待加密/解密文本（可区分大小写）：");
    gets(ch);
    printf("\n请输入偏移位数：");
    scanf("%d", &n);
    for (i = 0; ch[i]; i++)
    {
        A = ch[i];
        if (A == 32)//判断空格并保留
        {
            ch[i] = ch[i];
        }
        else if (A < 91 - n)//大写处理
        {
            ch[i] = A + n;
        }
        else if (A < 91)//后n位字母的处理，小写同理
        {
            ch[i] = A - 26 + n;
        }
        else if (A < 123 - n)//小写处理
        {
            ch[i] = A + n;
        }
        else
        {
            ch[i] = A - 26 + n;
        }
    }
    printf("结果为：");
    printf("%s\n", ch);
    system("pause");

}
