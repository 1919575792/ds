#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
typedef struct{
    int r, c;      // 以行号和列号作为“坐标位置”类型
}PosType;
typedef struct{
    int ord;       // 通道块在路径上的序号
    PosType seat; // 通道块在迷宫中的“坐标位置”
    int di;            // 从此通道块走向下一通道块的“方向”
}SElemType;           // 定义堆栈元素的类型

typedef struct{
    char arr[10][11];
}MazeType; // 定义迷宫类型（二维字符数组）

typedef struct node
{
    SElemType  pos;
    struct  node *next;

} SqStack;    // 创建栈

int InitStack(SqStack *S)
{
    /* 构造一个空栈S */
    S = new SqStack();
    S->next = NULL;
    return 1;
} //对栈进行初始化

int Pass(MazeType maze,PosType curpos){
    if(maze.arr[curpos.r][curpos.c] != '#')
        return 1;
    return 0;
}//判断当前位置能否通过

void FootPrint(MazeType maze,PosType curpos){
    if(maze.arr[curpos.r][curpos.c] == ' ')
        maze.arr[curpos.r][curpos.c] = '*';
} //留下足迹

void Push(SqStack S,SElemType e){
        SqStack *q = new SqStack();
        q->pos = e;
        q->next = S.next;
        S.next = q->next;
    }
  // 加入路径及入栈

PosType NextPos(PosType CurPos,int x){
    PosType ReturnPos;
    switch (x)
    {
        case 1:
            ReturnPos.r = CurPos.r;
            ReturnPos.c = CurPos.c + 1;
            break;
        case 2:
            ReturnPos.r = CurPos.r + 1;
            ReturnPos.c = CurPos.c;
            break;
        case 3:
            ReturnPos.r = CurPos.r;
            ReturnPos.c = CurPos.c - 1;
            break;
        case 4:
            ReturnPos.r = CurPos.r - 1;
            ReturnPos.c = CurPos.c;
            break;
    }
    return ReturnPos;
}
int StackEmpty(SqStack *S){
    if(S->next == NULL)
        return 1;
    else return 0;
}  //判断栈空
void Pop(SqStack *S,SElemType temp){
    temp = S->next->pos;
    S->next = S->next->next;
}//弹出栈

void MarkPrint (MazeType maze,PosType a){
    maze.arr[a.r][a.c] = '!';
}


//给出的函数
int MazePath(MazeType &maze, PosType start, PosType end){
    SqStack S;
    PosType curpos;
    int curstrep;
    SElemType e;

    InitStack(&S);
    curpos = start;
    curstrep = 1;  //探索第一步
    do {
        if (Pass(maze, curpos)) {  // 当前位置可通过，及时未曾走到过的通道快
            FootPrint(maze, curpos);
            e.di = 1;
            e.ord = curstrep;
            e.seat = curpos;
            Push(S, e); //加入路径
            if (curpos.r == end.r && curpos.c == end.c)
                return 1;
            curpos = NextPos(curpos, 1);
            curstrep++;
        } else {  //当前位置不能通过
            if (!StackEmpty((&S))) {
                Pop(&S,e);
                while (e.di == 4 && !StackEmpty(&S)) {
                    MarkPrint(maze, e.seat);
                    Pop(&S,e); //留下不能通过的标记并退回
                }
                if (e.di < 4) {
                    e.di++;
                    Push(S, e);  //换下一个方西探索
                    curpos = NextPos(e.seat, e.di);
                }
            }
        }
    }while(!StackEmpty(&S));
        return  0;
}

int main(){
    MazeType maze;
    PosType start, end;
    //输入迷宫
    for (int i=0;i<10;i++)
        cin.getline(maze.arr[i], 11);
    //找位置
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++) {
            if(maze.arr[i][j] == 'S') // 获得起点坐标
            {
                start.r = i;
                start.c = j;
            }
            else if(maze.arr[i][j] == 'E')  // 获得终点坐标
            {
                end.r = i;
                end.c = j;
            }
        }
    if (MazePath(maze, start, end)) {
        for (int j = 0; j < 10; j++)
            cout << maze.arr[j] << endl;
    }   //成立时输出

    return 0;
}
