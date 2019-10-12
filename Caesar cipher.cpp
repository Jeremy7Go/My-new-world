#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
    int A,i,n;
    char ch[100];
    printf("感谢使用！");
    printf("\n请输入要加密的文本(纯小写):");
    gets(ch);
    printf("\n请输入偏移位数n(n<26):");
    scanf("%d",&n);
    for (i = 0; ch[i]; i++) //循环,从首字符开始,直到字符串结束为止
    {
        A = ch[i];
        if (A == 32) //对于空格的识别
        {
            ch[i] = ch[i];
        }
        else if (A < 123 -n)
        {
            ch[i] = A + n;//对ASCII码的改动实现偏移
        }
        else
        {
            ch[i] = A - 26 + n; //对于后n位的字母的处理
        }
    }

    cout << ch << endl;
    system("pause");
}
