#include <stdio.h>
#include <stdlib.h>
#define Datatype int
int c, k = 0; //输入暂存，程序开关
//设置结点
typedef struct node
{
    Datatype data;     //数据域
    struct node *next; //指针域
} Node, *pNode;
//函数声明
pNode Init_list();                   //新建链表
void Print(pNode phead);             //打印
pNode Add_node(pNode phead);         //新建结点
pNode Delete_node(pNode phead);      //删除结点
pNode Addr_search_node(pNode phead); //按地址查找结点
pNode Data_search_node(pNode phead); //按数据查找结点
int main()
{
    pNode phead = Init_list();
    //用户操作
    printf("这是一个首项为5公差为5等差数列链表");
    while (k == 0)
    {
        printf("\n\n请输入你想进行的操作的序号\nA.退出\nB.打印数表\nC.插入结点\nD.删除结点\nE.按地址查找结点\nF.按数据查找结点\n");
        switch (getchar())
        {
        case 'a':
        case 'A':
            k = 1;
            fflush(stdin); //清空缓冲区吃掉回车
            break;
        case 'b':
        case 'B':
            Print(phead);
            fflush(stdin);
            break;
        case 'c':
        case 'C':
            Add_node(phead);
            fflush(stdin);
            break;
        case 'd':
        case 'D':
            Delete_node(phead);
            fflush(stdin);
            break;
        case 'e':
        case 'E':
            Addr_search_node(phead);
            fflush(stdin);
            break;
        case 'f':
        case 'F':
            Data_search_node(phead);
            fflush(stdin);
            break;
        default:
            printf("FBI Warning： Wrong Operation！！！");
            fflush(stdin);
            break;
        }
    }
    system("pause");
}
void Print(pNode phead)
{
    pNode p = phead; //以下p均为临时结点
    printf("链表数据如下：\n");
    while (p->next)
    {
        p = p->next;
        printf("%d ", p->data);
    }
    printf("\n一共有%d项数据", phead->data);
}
pNode Init_list() //初始数据为首项为5公差为5等差数列
{
    pNode head = (pNode)malloc(sizeof(Node)); //创建一个头结点
    pNode phead = head;                       //头指针
    pNode p = head;                           //临时指针
    head->data = 100;                         //记录链表大小
    for (int i = 1; i <= 100; i++)
    {
        pNode a = (pNode)malloc(sizeof(Node));
        a->data = i * 5;
        a->next = NULL;
        p->next = a;
        p = a;
    }
    return phead;
}
pNode Add_node(pNode phead)
{
    int f;
    pNode p = phead;
    printf("现在有%d项数据", phead->data);
    printf("\n请输入需要插入的位置:");
    scanf("%d", &f);
    printf("请输入数据：");
    scanf("%d", &c);
    if (f < 1 || f > phead->data + 1)
        printf("FBI Warning： Wrong Operation！！！");
    else if (f == phead->data + 1)
    {
        pNode a = (pNode)malloc(sizeof(Node));
        a->data = c;
        a->next = NULL;
        while (p->next)
            p = p->next;
        p->next = a;
        phead->data++;
        printf("插入成功");
    }
    else
    {
        for (int i = 1; i < f; i++)
            p = p->next;
        pNode a = (pNode)malloc(sizeof(Node));
        a->data = c;
        a->next = p->next;
        p->next = a;
        printf("插入成功");
        phead->data++;
    }
    return phead;
}
pNode Delete_node(pNode phead)
{
    pNode p = phead;
    printf("现在有%d项数据", phead->data);
    printf("请输入删除数据的位置：");
    scanf("%d", &c);
    if (c < 1 || c > phead->data)
        printf("FBI Warning： Wrong Operation！！！");
    else
    {
        for (int i = 1; i < c; i++)
            p = p->next;
        pNode del = p->next;
        p->next = p->next->next;
        free(del);
        printf("删除成功");
        phead->data--;
    }
    return phead;
}
pNode Addr_search_node(pNode phead)
{
    pNode p = phead;
    printf("现在有%d项数据", phead->data);
    printf("请输入查找数据的位置：");
    scanf("%d", &c);
    if (c < 1 || c > phead->data)
        printf("FBI Warning： Wrong Operation！！！");
    else
    {
        for (int i = 1; i <= c; i++)
            p = p->next;
        printf("第%d项数据为%d", c, p->data);
    }
    return phead;
}
pNode Data_search_node(pNode phead)
{
    int m = 0;
    pNode p = phead;
    printf("请输入要查找的数据：");
    scanf("%d", &c);
    for (int i = 1; i <= phead->data; i++)
    {
        p = p->next;
        if (p->data == c)
        {
            m++;
            printf("第%d项数据是%d \n", i, c);
        }
    }
    if (m == 0)
        printf("%d不在链表中", c);
    return phead;
}
