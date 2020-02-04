#include <stdio.h>
#include <stdlib.h>   //srand（）函数
#include <time.h>     //time（）函数
#include <conio.h>    //kbhit（）函数
#include <windows.h>  //sleep（）函数
#include <graphics.h> //图形界面库

//简化而已,下同
#define out outtextxy
#define rec(x, y) rectangle(20 * (x), 20 * (y), 20 * (x + 1), 20 * (y + 1))        //画20*20的方格
#define srec(x, y) solidrectangle(20 * (x), 20 * (y), 20 * (x + 1), 20 * (y + 1))  //画实心方格
#define clear(x, y) clearrectangle(20 * (x), 20 * (y), 20 * (x + 1), 20 * (y + 1)) //清除方格

//游戏数据
TCHAR DL[2], SC[3], ID[12]; //DeadLine，SCORE，ID
int head[4];                //head[0][1]记录蛇头将来位置，head[2][3]记录蛇头现在位置
int sbody[4];               //数据传导载体
int body[700][2];           //body[0]当缓冲区,head[2][3]不断复制给body[0]
int score, speed, food[2];  //得分，速度，食物坐标
int lenth;                  //长度
int dirget;                 //方向记录（1234左上右下）
int n = 0, i = 0;           //工具数
int fd, sw = 1;             //feed函数开关(0不产生1产生食物)，主函数switch开关（1菜单2重玩3退出）

//函数声明
void sneakerhead(); //七彩氪金炫酷鞋头
void beginning();   //欢迎动画
void start();       //游戏初始化
void end();         //游戏结束选项
void game();        //游戏主体
void direction();   //获取移动方向
void move();        //蛇的移动算法
void draw();        //画蛇
void out();         //出局规则
void feed();        //投放食物

int main()
{
    beginning();
    while (sw != 3)
    {
        switch (sw)
        {
        default:
            break;
        case 1:
            cleardevice();
            start();
        case 2:
            cleardevice();
            game();
            end();
        }
    }
    cleardevice();
    out(285, 360, L"<按任意键退出>");
    system("pause");
}
void sneakerhead()
{
    if (n % 7 == 0)
        setfillcolor(LIGHTRED);
    else if (n % 7 == 1)
        setfillcolor(LIGHTGRAY);
    else if (n % 7 == 2)
        setfillcolor(YELLOW);
    else if (n % 7 == 3)
        setfillcolor(LIGHTGREEN);
    else if (n % 7 == 4)
        setfillcolor(LIGHTCYAN);
    else if (n % 7 == 5)
        setfillcolor(LIGHTBLUE);
    else if (n % 7 == 6)
        setfillcolor(LIGHTMAGENTA);
    n++;
}
void beginning()
{
    //基础版面
    initgraph(720, 720);
    setbkcolor(WHITE);
    settextcolor(BLACK);
    setlinecolor(LIGHTCYAN);
    cleardevice();
    while (!kbhit())
    {
        if (i == 33)
            i = -1;
        if (i <= 11 || i >= 18)
            out(310, 322, L"贪吃GIAO");
        sneakerhead();
        out(285, 360, L"<按任意键继续>");
        rec(1 + i, 16);
        rec(2 + i, 16);
        srec(3 + i, 16);
        Sleep(100);
        cleardevice();
        i++;
    }
}
void start()
{
    //玩家ID
    InputBox(ID, 12, L"请输入玩家ID:", L"玩家ID");
    out(100, 180, L"祝你好运咯，");
    out(200, 180, ID);
    out(100, 220, L"WSAD或上下左右为方向键");
    out(100, 260, L"输入序号数字选定选项，按J选定（输入默认为英文输入法）");
    out(100, 300, L"那么开始叭，火狐阿，一给我里Giao~Giao！");
    out(285, 360, L"<按任意键继续>");
    system("pause");
    cleardevice();
    //难度设置
    out(100, 120, L"对于贪吃Giao这个游戏你觉得你是:");
    out(140, 140, L"1.究极带佬");
    out(140, 160, L"2.高手而已");
    out(140, 180, L"3.小小白");
    out(140, 200, L"4.老人家（受不了什么刺激）");
    //挑颜色
    out(100, 240, L"给你的小阿Giao挑个颜色叭:");
    out(140, 260, L"1.基佬紫");
    out(140, 280, L"2.仙女粉");
    out(140, 300, L"3.姨妈红");
    out(140, 320, L"4.原谅绿");
    //实现光标移动效果，后同
    i = 0;
    while (i != 100)
    {
        switch (getch())
        {
        case '1':
            clearrectangle(100, 140, 140, 220);
            out(120, 140, L"-->");
            speed = 15;
            break;
        case '2':
            clearrectangle(100, 140, 140, 220);
            out(120, 160, L"-->");
            speed = 50;
            break;
        case '3':
            clearrectangle(100, 140, 140, 220);
            out(120, 180, L"-->");
            speed = 100;
            break;
        case '4':
            clearrectangle(100, 140, 140, 220);
            out(120, 200, L"-->");
            speed = 200;
            break;
        case 74:
        case 106:
            i = 100;
            break;
        }
    }
    i = 0;
    while (i != 100)
    {
        switch (getch())
        {
        case '1':
            clearrectangle(100, 260, 140, 340); //实现光标移动效果，后同
            out(120, 260, L"-->");
            setlinecolor(MAGENTA);
            setfillcolor(MAGENTA);
            break;
        case '2':
            clearrectangle(100, 260, 140, 340);
            out(120, 280, L"-->");
            setlinecolor(LIGHTMAGENTA);
            setfillcolor(LIGHTMAGENTA);
            break;
        case '3':
            clearrectangle(100, 260, 140, 340);
            out(120, 300, L"-->");
            setlinecolor(LIGHTRED);
            setfillcolor(LIGHTRED);
            break;
        case '4':
            clearrectangle(100, 260, 140, 340);
            out(120, 320, L"-->");
            setlinecolor(LIGHTGREEN);
            setfillcolor(LIGHTGREEN);
            break;
        case 74:
        case 106:
            i = 100;
            break;
        }
    }
    //假装有游戏加载这回事
    out(100, 360, L"OK，正在将你的小阿Giao投入场地...");
    for (int j = 5; j > 0; j--)
    {
        wsprintf(DL, L"%d...", j); //窗口实现整型变量的输出
        out(355, 360, DL);
        Sleep(1000);
    }
    cleardevice();
}
void end()
{
    cleardevice();
    out(100, 120, L"哦豁你挂鸟，你选择:");
    out(140, 140, L"1.再来一盘");
    out(140, 160, L"2.回主菜单");
    out(140, 180, L"3.暴躁退出");
    while (i != 100)
    {
        switch (getch())
        {
        case '1':
            clearrectangle(100, 140, 140, 220);
            out(120, 140, L"-->");
            sw = 2;
            break;
        case '2':
            clearrectangle(100, 140, 140, 220);
            out(120, 160, L"-->");
            sw = 1;
            break;
        case '3':
            clearrectangle(100, 140, 140, 220);
            out(120, 180, L"-->");
            sw = 3;
            break;
        case 74:
        case 106:
            i = 100;
            break;
        }
    }
}
void game()
{
    //进场画面
    rec(1, 16);
    rec(2, 16);
    srec(3, 16);
    out(265, 360, L"<按任意键开始你的表演>");
    system("pause");
    cleardevice();
    //初始数据
    i = 1; //游戏结束与否的开关（1开0关）
    lenth = 3;
    score = 1;
    dirget = 3;
    food[0] = 20;
    food[1] = 16;
    head[0] = 3;
    head[1] = 16;
    body[1][0] = 2;
    body[1][1] = 16;
    body[2][0] = 1;
    body[2][1] = 16;
    while (1)
    {
        move();
        if (i == 0) //getch（）为阻塞函数，必须在此处判断而不是whlie处
            break;
        direction();
    }
    Sleep(300);
}
void direction()
{
    switch (getch())
    {
    case 'A':
    case 'a':
    case 75:
        if (dirget == 2 || dirget == 4)
            dirget = 1;
        break;
    case 'D':
    case 'd':
    case 77:
        if (dirget == 2 || dirget == 4)
            dirget = 3;
        break;
    case 'W':
    case 'w':
    case 72:
        if (dirget == 1 || dirget == 3)
            dirget = 2;
        break;
    case 'S':
    case 's':
    case 80:
        if (dirget == 1 || dirget == 3)
            dirget = 4;
        break;
    }
}
void move()
{
    while (!kbhit())
    {
        switch (dirget)
        {
        case 1:
            head[2] = head[0];
            head[3] = head[1];
            head[0] -= 1;
            out();
            clear(head[2], head[3]);                       //清除上个蛇头
            clear(body[lenth - 1][0], body[lenth - 1][1]); //清蛇尾
            feed();
            draw();
            Sleep(speed);
            break;
        case 2:
            head[2] = head[0];
            head[3] = head[1];
            head[1] -= 1;
            out();
            clear(head[2], head[3]);                       //清除上个蛇头
            clear(body[lenth - 1][0], body[lenth - 1][1]); //清蛇尾
            feed();
            draw();
            Sleep(speed);
            break;
        case 3:
            head[2] = head[0];
            head[3] = head[1];
            head[0] += 1;
            out();
            clear(head[2], head[3]);                       //清除上个蛇头
            clear(body[lenth - 1][0], body[lenth - 1][1]); //清蛇尾
            feed();
            draw();
            Sleep(speed);
            break;
        case 4:
            head[2] = head[0];
            head[3] = head[1];
            head[1] += 1;
            out();
            clear(head[2], head[3]);                       //清除上个蛇头
            clear(body[lenth - 1][0], body[lenth - 1][1]); //清蛇尾
            feed();
            draw();
            Sleep(speed);
            break;
        }
        if (i == 0)
            break;
    }
}
void draw()
{
    sneakerhead();        //七彩蛇头
    body[0][0] = head[2]; //body[0]是缓冲区！
    body[0][1] = head[3];
    srec(head[0], head[1]);             //画蛇头
    for (int m = 0; m < lenth - 1; m++) //图形上移动蛇身
        rec(body[m][0], body[m][1]);
    for (int m = lenth - 1; m >= 0; m--) //数据上移动蛇身
    {
        body[m + 1][0] = body[m][0];
        body[m + 1][1] = body[m][1];
    }
}
void out()
{
    if (head[0] == 36 || head[1] == 36)
        i = 0;
    else if (head[0] == -1 || head[1] == -1)
        i = 0;
    for (int m = 0; m < lenth - 1; m++)
    {
        if (body[m][0] == head[0] && body[m][1] == head[1])
        {
            i = 0;
            break;
        }
    }
}
void feed()
{
    //判断食物是否被吃
    if (food[0] == head[2] && food[1] == head[3])
    {
        clear(food[0], food[1]);
        score++;
        lenth++;
        fd = 1;
    }
    else
        fd = 0;
    //产生合理食物
    while (fd != 0)
    {
        srand((unsigned)time(NULL)); //随机种子（其实time函数的使用可以用工具数n代替）
        food[0] = rand() % 36;
        food[1] = rand() % 36;
        for (int m = 0; m < lenth - 1; m++)
        {
            if (body[m][0] == food[0] && body[m][1] == food[1])
            {
                fd = 1;
                break;
            }
        }
        if (food[1] == 0)
            fd = 1;
        else if (food[0] == 0 && food[1] == 35)
            fd = 1;
        else if (food[0] == 35 && food[1] == 0)
            fd = 1;
        else if (food[0] == 35 && food[1] == 35)
            fd = 1;
        else
            fd = 0;
    }
    //打印食物
    rec(food[0], food[1]);
    wsprintf(SC, L"%d", score);
    out(food[0] * 20 + 3, food[1] * 20 + 3, SC);
}
