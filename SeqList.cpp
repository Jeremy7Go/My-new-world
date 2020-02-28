#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 120
#define DataType int
int n, m = 0, k = 0; //输入数暂存，计数器，循环开关
//设表
struct Seqlist
{
    DataType body[MAX_SIZE];
    DataType size = 100; //100项初始数据
} Seq;
//操作
void Print(DataType body[]);//打印
void Add(DataType body[]);//插入数据
void Delete(DataType body[]);//按位置删除数据
void Search(DataType body[]);//按位置索检
void NumAdd(DataType body[]);//按位置插入数据
void NumDelete(DataType body[]);//删除数据
void NumSearch(DataType body[]);//索检
int main()
{
    //初始化数据 （首项为0，公差为5的等差数列）
    for (int i = 0; i < Seq.size; i++)
        Seq.body[i] = i * 5;
    printf("这是一个从小到大排列的顺序数表");
    //用户操作
    while (k == 0)
    {
        printf("\n\n请输入你想进行的操作的序号\nA.退出\nB.打印数表\nC.按位置检索\nD.按数据检索");
        printf("\nE.删除数据\nF.按位置删除数据\nG.插入数据\nH.按位置插入数据\n");
        switch (getchar())
        {
        case 'a':
        case 'A':
            k = 1;
            fflush(stdin); //清空缓冲区吃掉回车
            break;
        case 'b':
        case 'B':
            Print(Seq.body);
            fflush(stdin);
            break;
        case 'c':
        case 'C':
            Search(Seq.body);
            fflush(stdin);
            break;
        case 'd':
        case 'D':
            NumSearch(Seq.body);
            fflush(stdin);
            break;
        case 'e':
        case 'E':
            NumDelete(Seq.body);
            fflush(stdin);
            break;
        case 'f':
        case 'F':
            Delete(Seq.body);
            fflush(stdin);
            break;
        case 'g':
        case 'G':
            Add(Seq.body);
            fflush(stdin);
            break;
        case 'h':
        case 'H':
            NumAdd(Seq.body);
            fflush(stdin);
            break;
        default:
            printf("FBI Warning： Wrong Operation！！！");
            fflush(stdin);
            break;
        }
    }
    //退出
    system("pause");
}
void Print(DataType body[])
{
    for (int i = 0; i < Seq.size; i++)
        printf("\n%d", Seq.body[i]);
}
void Add(DataType body[])
{
    if (Seq.size + 1 > MAX_SIZE)
        printf("数表已满，无法插入");
    else
    {
        printf("请输入需要插入的数据：");
        scanf("%d", &n);
        for (int i = 0; i <= Seq.size; i++)
        {
            if (i == Seq.size)
                Seq.body[i] = n;
            else if (n <= Seq.body[i])
            {
                n ^= Seq.body[i];
                Seq.body[i] ^= n;
                n ^= Seq.body[i];
                m++;
            }
        }
        Seq.size++;
        printf("\n插入成功，此次插入移动了%d项数据", m);
    }
}
void Delete(DataType body[])
{
    printf("现在数表中存在%d项数据", Seq.size);
    printf("\n请输入要删除数据的序数：");
    scanf("%d", &n);
    if (n > Seq.size || n < 1)
        printf("\nFBI Warning： Wrong Operation！！！");
    else
    {
        for (int i = n - 1; i < Seq.size; i++)
            Seq.body[i] = Seq.body[i + 1];
        Seq.size--;
        printf("\n删除成功，此次插入删除移动了%d项数据", Seq.size - n + 1);
    }
}
void Search(DataType body[])
{
    printf("\n请输入需要查找数据的序数：");
    scanf("%d", &n);
    printf("\n第%d项数据是%d", n, Seq.body[n - 1]);
}
void NumAdd(DataType body[])
{
    int a;
    printf("现在数表中存在%d项数据", Seq.size);
    printf("\n请输入需要插入数据的位置：");
    scanf("%d", &a);
    if (a > Seq.size + 1 || a < 1)
        printf("FBI Warning： Wrong Operation！！！");
    else
    {
        printf("请输入数据：");
        scanf("%d", &n);
        for (int i = a - 1; i <= Seq.size; i++)
        {
            n ^= Seq.body[i];
            Seq.body[i] ^= n;
            n ^= Seq.body[i];
        }
        Seq.size++;
        printf("插入成功");
    }
}
void NumDelete(DataType body[])
{
    printf("请输入要删除的数据：");
    scanf("%d", &n);
    for (int i = 0; i < Seq.size; i++)
    {
        if (n == Seq.body[i])
        {
            for (; i < Seq.size; i++)
                Seq.body[i] = Seq.body[i + 1];
            Seq.size--;
            printf("删除成功");
            break;
        }
        if (i == Seq.size - 1)
            printf("%d不在此表中", n);
    }
}
void NumSearch(DataType body[])
{
    printf("请输入要查询的数据：");
    scanf("%d", &n);
    for (int i = 0; i < Seq.size; i++)
    {
        if (n == Seq.body[i])
        {
            printf("%d是第%d项数据", n, i + 1);
            break;
        }
        if (i == Seq.size - 1)
            printf("%d不在此表中", n);
    }
}
