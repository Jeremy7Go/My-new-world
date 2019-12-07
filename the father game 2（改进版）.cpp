/*改进版本， gets()真tmd香*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char ch[30];
    char ch1[30] = "沈杨浥伦"; //防止坑自己，下同
    char ch2[30] = "沈杨";
    printf("这是一个极其准确的亲子鉴定小程序！\n");
    printf("请输入待鉴定人的名字:  ");
    gets(ch);
    if (strcmp(ch, ch2) == 0) //判断两字符串是否相等
        printf("他是你爸爸！！！\n");
    else if (strcmp(ch, ch1) == 0)
        printf("他还是你爸爸！！！你以为说全名他就不是你爸爸了?没听说过！\n");
    else
        printf("%s是%s的儿子。\n",ch,ch1);
    system("pause");
    return 0;
}
